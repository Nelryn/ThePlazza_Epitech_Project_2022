/*
** EPITECH PROJECT, 2022
** B-CCP-400-RUN-4-1-theplazza-emilie.baunifais
** File description:
** Clock
*/

#pragma once

#include <chrono>

namespace plazza {
    class Clock {
        public:
            Clock();
            ~Clock();

            void restart();
            double getTimeInMilliSeconds() const;
            double getTimeAsSeconds() const;

        private:
            std::chrono::time_point<std::chrono::high_resolution_clock> _time=
                std::chrono::high_resolution_clock::now();
    };
} //namespace plazza