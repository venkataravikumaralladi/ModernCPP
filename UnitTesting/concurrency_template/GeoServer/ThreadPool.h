#pragma once

// ============================================================================
// <copyright file="ThreadPool.h" company="VRK">
//     Copyright (c) Venkata 2022. All rights reserved.
// </copyright>
// ============================================================================

/***
 * Excerpted from "Modern C++ Programming with Test-Driven Development",
 * published by The Pragmatic Bookshelf.
 * Copyrights apply to this code. It may not be used to create training material,
 * courses, books, articles, and the like. Contact us if you are in doubt.
 * We make no guarantees that this code is fit for any purpose.
 * Visit http://www.pragmaticprogrammer.com/titles/lotdd for more book information.
***/
// Local includes, e.g. files in the same folder, typically corresponding declarations.
#include "Work.h"

// System includes, e.g. STL, Library headers, ...
#include <string>
#include <deque>
#include <thread>
#include <memory>
#include <atomic>
#include <mutex>
#include <vector>
#include <iostream>


class ThreadPool {
public:
    virtual ~ThreadPool() {
        stop();
    }

    void stop() {
        done_ = true;
        for (auto& thread : threads_) thread.join();
    }

    void start(unsigned int numberOfThreads = 1) {
        for (unsigned int i{ 0u }; i < numberOfThreads; i++)
            threads_.push_back(std::thread(&ThreadPool::worker, this));
    }

    bool hasWork() {
        std::lock_guard<std::mutex> block(mutex_);
        return !workQueue_.empty();
    }

    virtual void add(Work work) {
        std::lock_guard<std::mutex> block(mutex_);
        workQueue_.push_front(work);
    }

    Work pullWork() {
        std::lock_guard<std::mutex> block(mutex_);

        if (workQueue_.empty()) return Work{};

        auto work = workQueue_.back();
        workQueue_.pop_back();
        return work;
    }

private:
    void worker() {
        while (!done_) {
            while (!done_ && !hasWork())
                ;
            if (done_) break;
            pullWork().execute();
        }
    }

    std::atomic<bool> done_{ false };
    std::deque<Work> workQueue_;
    std::shared_ptr<std::thread> workThread_;
    std::mutex mutex_;
    std::vector<std::thread> threads_;
};

