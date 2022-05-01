// ============================================================================
// <copyright file="ThreadPoolTest.cpp" company="VRK">
//     Copyright (c) Venkata 2022. All rights reserved.
// </copyright>
// ============================================================================

// Local includes, e.g.files in the same folder, typically corresponding declarations.
#include "../../../GraphExplorers/GeoServer/ThreadPool.h"

// C++ includes.
#include <functional>
#include <vector>
#include <sstream>
#include <condition_variable>
#include <mutex>
#include <chrono>

// google test includes
#include "gmock/gmock.h" 

using namespace std;
using std::chrono::milliseconds;

class AThreadPool : public testing::Test {
public:
	mutex m;
	ThreadPool pool;
};


TEST_F(AThreadPool, HasNoWorkOnCreation) {
	ASSERT_FALSE(pool.hasWork());
}

TEST_F(AThreadPool, HasWorkAfterAdd) {
	pool.add(Work{});
	ASSERT_TRUE(pool.hasWork());
}

TEST_F(AThreadPool, AnswersWorkAddedOnPull) {
	pool.add(Work{ 1 });
	auto work = pool.pullWork();
	EXPECT_DOUBLE_EQ(1, work.id());
}

TEST_F(AThreadPool, PullsElementsInFIFOOrder) {
	pool.add(Work{ 1 });
	pool.add(Work{ 2 });

	auto work = pool.pullWork();
	EXPECT_DOUBLE_EQ(1, work.id());
}

TEST_F(AThreadPool, HasNoWorkAfterLastElementRemoved) {
	pool.add(Work{});
	pool.pullWork();
	ASSERT_FALSE(pool.hasWork());
}

TEST_F(AThreadPool, HasWorkAfterWorkRemovedButWorkRemains) {
	pool.add(Work{});
	pool.add(Work{});
	pool.pullWork();
	ASSERT_TRUE(pool.hasWork());
}

TEST_F(AThreadPool, PullsWorkInAThread) {
	pool.start();
	condition_variable wasExecuted;
	bool wasWorked{ 0 };
	Work work{ [&] {
	   unique_lock<mutex> lock(m);
	   wasWorked = true;
	   wasExecuted.notify_all();
	} };

	pool.add(work);

	unique_lock<mutex> lock(m);
	ASSERT_TRUE(wasExecuted.wait_for(lock, chrono::milliseconds(100),
		[&] { return wasWorked; }));
}

TEST_F(AThreadPool, ExecutesAllWork) {
	pool.start();
	unsigned int count{ 0 };
	unsigned int NumberOfWorkItems{ 3 };
	condition_variable wasExecuted;
	Work work{ [&] {
	   std::unique_lock<std::mutex> lock(m);
	   ++count;
	   wasExecuted.notify_all();
	} };
	for (unsigned int i{ 0 }; i < NumberOfWorkItems; i++)
		pool.add(work);
	unique_lock<mutex> lock(m);
	ASSERT_TRUE(wasExecuted.wait_for(lock, chrono::milliseconds(100),
		[&] { return count == NumberOfWorkItems; }));
}

class ThreadPoolThreadTests : public testing::Test {
public:
	ThreadPool pool;
	mutex m;
	condition_variable wasExecuted;
	unsigned int count{ 0 };
	vector<shared_ptr<thread>> threads; /* to simulate threads so that multiple threads sends requests */

	void TearDown() override {
		for (auto& t : threads) t->join();
	}

	void incrementCountAndNotify() {
		std::unique_lock<std::mutex> lock(m);
		++count;
		wasExecuted.notify_all();
	}

	void waitForCountAndFailOnTimeout(
		unsigned int expectedCount,
		const milliseconds& time = milliseconds(500)) {
		unique_lock<mutex> lock(m);
		ASSERT_TRUE(wasExecuted.wait_for(lock, time,
			[&] { return expectedCount == count; }));
	}
};

class AThreadPool_AddRequest : public ThreadPoolThreadTests {
public:

	void SetUp() override {
		pool.start();
	}
};

TEST_F(AThreadPool_AddRequest, PullsWorkInAThread) {
	Work work{ [&] { incrementCountAndNotify(); } };
	unsigned int NumberOfWorkItems{ 1 };

	pool.add(work);

	waitForCountAndFailOnTimeout(NumberOfWorkItems);
}

TEST_F(AThreadPool_AddRequest, ExecutesAllWork) {
	Work work{ [&] { incrementCountAndNotify(); } };
	unsigned int NumberOfWorkItems{ 3 };

	for (unsigned int i{ 0 }; i < NumberOfWorkItems; i++)
		pool.add(work);

	waitForCountAndFailOnTimeout(NumberOfWorkItems);
}

TEST_F(AThreadPool_AddRequest, HoldsUpUnderClientStress) {
	Work work{ [&] { incrementCountAndNotify(); } };
	unsigned int NumberOfWorkItems{ 10 };
	unsigned int NumberOfThreads{ 10 };

	for (unsigned int i{ 0 }; i < NumberOfThreads; i++)
		threads.push_back(
			make_shared<thread>([&] {
				for (unsigned int j{ 0 }; j < NumberOfWorkItems; j++)
					pool.add(work);
				}));
	waitForCountAndFailOnTimeout(NumberOfThreads * NumberOfWorkItems);
}

class AThreadPoolWithMultipleThreads : public ThreadPoolThreadTests {
public:
	set<thread::id> threads;

	void addThreadIfUnique(const thread::id& id) {
		std::unique_lock<std::mutex> lock(m);
		threads.insert(id);
	}

	size_t numberOfThreadsProcessed() {
		return threads.size();
	}
};


TEST_F(AThreadPoolWithMultipleThreads, DispatchesWorkToMultipleThreads) {
	unsigned int numberOfThreads{ 2 };
	pool.start(numberOfThreads);
	Work work{ [&] {
	   addThreadIfUnique(this_thread::get_id());
	   incrementCountAndNotify();
	} };
	unsigned int NumberOfWorkItems{ 500 };

	for (unsigned int i{ 0 }; i < NumberOfWorkItems; i++)
		pool.add(work);

	waitForCountAndFailOnTimeout(NumberOfWorkItems);
	ASSERT_DOUBLE_EQ(numberOfThreads, numberOfThreadsProcessed());
}


