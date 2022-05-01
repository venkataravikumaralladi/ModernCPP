// ============================================================================
// <copyright file="TestTimer.cpp" company="VRK">
//     Copyright (c) Venkata 2022. All rights reserved.
// </copyright>
// ============================================================================


// Local includes, e.g. files in the same folder, typically corresponding declarations.
#include "TestTimer.h"

#include <iostream>

using namespace std;

TestTimer::TestTimer()
    : TestTimer("default string") {
}

TestTimer::TestTimer(const string& text)
    : Start{ chrono::system_clock::now() }
    , Text{ text } {}

TestTimer::~TestTimer() {
    Stop = chrono::system_clock::now();
    Elapsed = chrono::duration_cast<chrono::microseconds>(Stop - Start);
    cout << endl <<
        Text << " elapsed time = " << Elapsed.count() * 0.001 << "ms" << endl;
}

