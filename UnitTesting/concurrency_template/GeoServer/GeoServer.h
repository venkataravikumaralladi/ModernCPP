#pragma once

// ============================================================================
// <copyright file="Graph.h" company="VRK">
//     Copyright (c) Venkata 2022. All rights reserved.
// </copyright>
// ============================================================================


/***
 * Reference: Modern C++ Programming with Test-Driven Development,
 * published by The Pragmatic Bookshelf.
 * Copyrights apply to this code. It may not be used to create training material,
 * courses, books, articles, and the like. Contact us if you are in doubt.
 * We make no guarantees that this code is fit for any purpose.
 * Visit http://www.pragmaticprogrammer.com/titles/lotdd for more book information.
***/

// Local includes, e.g. files in the same folder, typically corresponding declarations.
#include "Location.h"
#include "User.h"
#include "Area.h"
#include "ThreadPool.h"

// System includes, e.g. STL, Library headers, ...
#include <string>
#include <unordered_map>

/*
  Asynchronous design idea: (see page 249, section 9.5)
        Idea is to separate the three concerns implied into three classes.

            • Work, which represents a work item to be queued and executed
            • ThreadPool, which creates worker threads to handle the work queue
            • GeoServer, which creates a Work object and sends it to the ThreadPool for execution
*/

class GeoServerListener {
public:
    virtual void updated(const User& user) = 0;
};

class GeoServer {
public:
    // ...
    void track(const std::string& user);
    void stopTracking(const std::string& user);
    void updateLocation(const std::string& user, const Location& location);

    bool isTracking(const std::string& user) const;
    Location locationOf(const std::string& user) const;
    bool isDifferentUserInBounds(
        const std::pair<std::string, Location>& each,
        const std::string& user,
        const Area& box) const;
    void usersInBox(
        const std::string& user, double widthInMeters, double heightInMeters,
        GeoServerListener* listener = nullptr) const;
    void useThreadPool(std::shared_ptr<ThreadPool> pool);

private:
    std::unordered_map<std::string, Location> locations_;
    std::shared_ptr<ThreadPool> pool_;

    std::unordered_map<std::string, Location>::const_iterator
        find(const std::string& user) const;
};


