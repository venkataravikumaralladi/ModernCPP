// ============================================================================
// <copyright file="GeoServerTest.cpp" company="VRK">
//     Copyright (c) Venkata 2022. All rights reserved.
// </copyright>
// ============================================================================

// Local includes, e.g.files in the same folder, typically corresponding declarations.
#include "../../../GraphExplorers/GeoServer/Work.h"

// C++ includes.
#include <functional>
#include <vector>
#include <sstream>

// google test includes
#include "gmock/gmock.h" 

using namespace std;

class AWorkObject : public testing::Test {
};

TEST(AWorkObject, DefaultsFunctionToNullObject) {
    Work work;
    try {
        work.execute();
    }
    catch (...) {
        FAIL() << "unable to execute function";
    }
}

TEST(AWorkObject, DefaultsFunctionToNullObjectWhenConstructedWithId) {
    Work work(1);
    try {
        work.execute();
    }
    catch (...) {
        FAIL() << "unable to execute function";
    }
}

TEST(AWorkObject, CanBeConstructedWithAnId) {
    Work work(1);
    EXPECT_DOUBLE_EQ(1, work.id());
}

TEST(AWorkObject, DefaultsIdTo0) {
    Work work;
    EXPECT_DOUBLE_EQ(0, work.id());
}
TEST(AWorkObject, DefaultsIdTo0WhenFunctionSpecified) {
    Work work{ [] {} };
    EXPECT_DOUBLE_EQ(0, work.id());
}

TEST(AWorkObject, CanBeConstructedWithAFunctionAndId) {
    Work work{ [] {}, 1 };
    EXPECT_DOUBLE_EQ(1, work.id());
}

TEST(AWorkObject, ExecutesFunctionStored) {
    bool wasExecuted{ false };
    auto executeFunction = [&]() { wasExecuted = true; };
    Work work(executeFunction);
    work.execute();
    ASSERT_TRUE(wasExecuted);
}

/*
* The test serves to reinforce knowledge of how to use lambdas and demonstrates how client code 
* can take advantage of a Work object. The function stored in executeFunction captures the locally
* defined data vector and subsequently demonstrates execution on that data.
* This will provide us with an example of what we’ll want to do in GeoServer.
*/
TEST(AWorkObject, CanExecuteOnDataCapturedWithFunction) {
    vector<string> data{ "a", "b" };
    string result;
    auto callbackFunction = [&](string s) {
        result.append(s);
    };
    auto executeFunction = [&]() {
        stringstream s;
        s << data[0] << data[1];
        callbackFunction(s.str());
    };
    Work work(executeFunction);
    work.execute();
    ASSERT_EQ("ab", result);
}