/*
** EPITECH PROJECT, 2022
** B-CCP-400-RUN-4-1-theplazza-emilie.baunifais
** File description:
** Clock
*/

#include "Clock.hpp"

namespace plazza {
    Clock::Clock()
    {
    }

    Clock::~Clock()
    {
    }

    void Clock::restart()
    {
        _time = std::chrono::high_resolution_clock::now();
    }

    double Clock::getTimeInMilliSeconds() const
    {
        auto chrono = std::chrono::high_resolution_clock::now().time_since_epoch() -
            _time.time_since_epoch();

        return std::chrono::duration_cast<std::chrono::milliseconds>(chrono).count();
    }

    double Clock::getTimeAsSeconds() const
    {
        auto chrono = std::chrono::high_resolution_clock::now().time_since_epoch() -
            _time.time_since_epoch();

        return std::chrono::duration_cast<std::chrono::seconds>(chrono).count();
    }

} //namespace plazza
