#pragma once

// ============================================================================
// <copyright file="Work.h" company="VRK">
//     Copyright (c) Venkata 2022. All rights reserved.
// </copyright>
// ==========

/***
 * Excerpted from "Modern C++ Programming with Test-Driven Development",
 * published by The Pragmatic Bookshelf.
 * Copyrights apply to this code. It may not be used to create training material,
 * courses, books, articles, and the like. Contact us if you are in doubt.
 * We make no guarantees that this code is fit for any purpose.
 * Visit http://www.pragmaticprogrammer.com/titles/lotdd for more book information.
***/

// Local includes, e.g. files in the same folder, typically corresponding declarations.


// System includes, e.g. STL, Library headers, ...
#include <functional>

class Work {
public:
    static const int DefaultId{ 0 };
    Work(int id = DefaultId)
        : id_{ id }
        , executeFunction_{ [] {} } {}
    Work(std::function<void()> executeFunction, int id = DefaultId)
        : id_{ id }
        , executeFunction_{ executeFunction }
    {}
    void execute() {
        executeFunction_();
    }
    int id() const {
        return id_;
    }
private:
    int id_;
    std::function<void()> executeFunction_;
};

