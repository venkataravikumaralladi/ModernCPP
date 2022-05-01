// ============================================================================
// <copyright file="GeoServerTest.cpp" company="VRK">
//     Copyright (c) Venkata 2022. All rights reserved.
// </copyright>
// ============================================================================

// >GraphExplorersUT.exe --gtest_filter=AGeoServer_UsersIn*
// 
// C++ includes.
#include <string>

// application includes
#include "../../../GraphExplorers/GeoServer/GeoServer.h"
#include "../../../GraphExplorers/GeoServer/VectorUtil.h"
#include "../../../GraphExplorers/GeoServer/User.h"
#include "../../../GraphExplorers/GeoServer/ThreadPool.h"

// google test includes
#include "gmock/gmock.h" 

using ::testing::Eq;
using namespace std;
using std::chrono::milliseconds;

class AGeoServer : public testing::Test {
public:
	GeoServer server;

	const string aUser{ "auser" };
	const double LocationTolerance{ 0.005 };
};

TEST_F(AGeoServer, AnswersUnknownLocationWhenUserNoLongerTracked) {
	server.track(aUser);

	server.stopTracking(aUser);

	// slow reading. Fix this.
	auto location = server.locationOf(aUser);
	ASSERT_EQ(numeric_limits<double>::infinity(), location.latitude());
}

TEST_F(AGeoServer, TracksAUser) {
	server.track(aUser);

	ASSERT_TRUE(server.isTracking(aUser));
}

TEST_F(AGeoServer, IsNotTrackingAUserNotTracked) {
	ASSERT_FALSE(server.isTracking(aUser));
}

TEST_F(AGeoServer, TracksMultipleUsers) {
	server.track(aUser);
	server.track("anotheruser");

	ASSERT_FALSE(server.isTracking("thirduser"));
	ASSERT_TRUE(server.isTracking(aUser));
	ASSERT_TRUE(server.isTracking("anotheruser"));
}

TEST_F(AGeoServer, IsTrackingAnswersFalseWhenUserNoLongerTracked) {
	server.track(aUser);

	server.stopTracking(aUser);

	ASSERT_FALSE(server.isTracking(aUser));
}

TEST_F(AGeoServer, UpdatesLocationOfUser) {
	server.track(aUser);

	server.updateLocation(aUser, Location{ 38, -104 });

	auto location = server.locationOf(aUser);
	EXPECT_DOUBLE_EQ(38, location.latitude(), LocationTolerance);
	EXPECT_DOUBLE_EQ(-104, location.longitude(), LocationTolerance);
}

TEST_F(AGeoServer, AnswersUnknownLocationForUserNotTracked) {
	ASSERT_TRUE(server.locationOf("anAbUser").isUnknown());
}

TEST_F(AGeoServer, AnswersUnknownLocationForTrackedUserWithNoLocationUpdate) {
	server.track(aUser);

	ASSERT_TRUE(server.locationOf(aUser).isUnknown());
}

TEST_F(AGeoServer, AnswersUnknownLocationForUserNoLongerTracked) {
	server.track(aUser);
	server.updateLocation(aUser, Location(40, 100));

	server.stopTracking(aUser);

	ASSERT_TRUE(server.locationOf(aUser).isUnknown());
}

class GeoServerUsersInBoxTests : public testing::Test {
public:
	GeoServer server;

	const double TenMeters{ 10 };
	const double Width{ 2000 + TenMeters };
	const double Height{ 4000 + TenMeters };
	const string aUser{ "auser" };
	const string bUser{ "buser" };
	const string cUser{ "cuser" };

	Location aUserLocation{ 38, -103 };

	shared_ptr<ThreadPool> pool;

	virtual void SetUp() override {
		server.useThreadPool(pool);

		server.track(aUser);
		server.track(bUser);
		server.track(cUser);

		server.updateLocation(aUser, aUserLocation);
	}

	string userName(unsigned int i) {
		return string{ "user" + to_string(i) };
	}

	void addUsersAt(unsigned int number, const Location& location) {
		for (unsigned int i{ 0 }; i < number; i++) {
			string user = userName(i);
			server.track(user);
			server.updateLocation(user, location);
		}
	}
};

class AGeoServer_UsersInBox : public GeoServerUsersInBoxTests {

public:

	class GeoServerUserTrackingListener : public GeoServerListener {
	public:
		void updated(const User& user) { Users.push_back(user); }
		vector<User> Users;
	} trackingListener;

	class SingleThreadedPool : public ThreadPool {
	public:
		virtual void add(Work work) override { work.execute(); }
	};

	void SetUp() override {
		pool = make_shared<SingleThreadedPool>();
		GeoServerUsersInBoxTests::SetUp();
	}

	vector<string> UserNames(const vector<User>&users) {
		return Collect<User, string>(users, [](User each) { return each.name(); });
	}
};

TEST_F(AGeoServer_UsersInBox, AnswersUsersInSpecifiedRange) {
	pool->start(0);
	server.updateLocation(
		bUser, Location{ aUserLocation.go(Width / 2 - TenMeters, East) });

	server.usersInBox(aUser, Width, Height, &trackingListener);

	ASSERT_EQ(vector<string> { bUser }, UserNames(trackingListener.Users));
}

TEST_F(AGeoServer_UsersInBox, AnswersOnlyUsersWithinSpecifiedRange) {
	pool->start(0);
	server.updateLocation(
		bUser, Location{ aUserLocation.go(Width / 2 + TenMeters, East) });
	server.updateLocation(
		cUser, Location{ aUserLocation.go(Width / 2 - TenMeters, East) });

	server.usersInBox(aUser, Width, Height, &trackingListener);

	ASSERT_EQ(vector<string> { cUser }, UserNames(trackingListener.Users));
}

TEST_F(AGeoServer_UsersInBox, HandlesLargeNumbersOfUsers) {
	pool->start(0);
	const unsigned int lots{ 5000 };
	addUsersAt(lots, Location{ aUserLocation.go(TenMeters, West) });

	server.usersInBox(aUser, Width, Height, &trackingListener);

	EXPECT_DOUBLE_EQ(lots, trackingListener.Users.size());
}

class AGeoServer_ScaleTests : public GeoServerUsersInBoxTests {

public:

	class GeoServerCountingListener : public GeoServerListener {
	public:
		void updated(const User& user) override {
			unique_lock<std::mutex> lock(mutex_);
			Count++;
			wasExecuted_.notify_all();
		}

		void waitForCountAndFailOnTimeout(unsigned int expectedCount,
			const milliseconds& time = milliseconds(10000)) {
			unique_lock<mutex> lock(mutex_);
			ASSERT_TRUE(wasExecuted_.wait_for(lock, time, [&]
				{ return expectedCount == Count; }));
		}

		condition_variable wasExecuted_;
		unsigned int Count{ 0 };
		mutex mutex_;
	};

	GeoServerCountingListener countingListener;
	shared_ptr<thread> t;

	void SetUp() override {
		pool = make_shared<ThreadPool>();
		GeoServerUsersInBoxTests::SetUp();
	}

	void TearDown() override {
		t->join();
	}
};

class AGeoServer_Performance : public GeoServerUsersInBoxTests {};

TEST_F(AGeoServer_Performance, LocationOf) {
	const unsigned int lots{ 500000 };
	addUsersAt(lots, Location{ aUserLocation.go(TenMeters, West) });


	for (unsigned int i{ 0 }; i < lots; i++)
		server.locationOf(userName(i));
}

TEST_F(AGeoServer_ScaleTests, HandlesLargeNumbersOfUsers) {
	pool->start(4);
	const unsigned int lots{ 5000 };
	addUsersAt(lots, Location{ aUserLocation.go(TenMeters, West) });

	t = make_shared<thread>(
		[&] { server.usersInBox(aUser, Width, Height, &countingListener); });

	countingListener.waitForCountAndFailOnTimeout(lots);
}




