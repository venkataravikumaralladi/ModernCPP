#pragma once

// ============================================================================
// <copyright file="User.h" company="VRK">
//     Copyright (c) Venkata 2022. All rights reserved.
// </copyright>
// ============================================================================

/***
 * Reference from "Modern C++ Programming with Test-Driven Development",
 * published by The Pragmatic Bookshelf.
 * Copyrights apply to this code. It may not be used to create training material,
 * courses, books, articles, and the like. Contact us if you are in doubt.
 * We make no guarantees that this code is fit for any purpose.
 * Visit http://www.pragmaticprogrammer.com/titles/lotdd for more book information.
***/

// Local includes, e.g. files in the same folder, typically corresponding declarations.
#include "Location.h"

// System includes, e.g. STL, Library headers, ...

class User {
public:
    User(const std::string& name, Location location)
        : name_(name), location_(location) {}
    std::string name() { return name_; }
    Location location() { return location_; }

private:
    std::string name_;
    Location location_;
};


