/*
** EPITECH PROJECT, 2022
** B-CCP-400-RUN-4-1-theplazza-emilie.baunifais
** File description:
** Reception
*/

#pragma once

#include <string>
#include <iostream>
#include "Utils.hpp"
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>

namespace plazza
{
    enum PizzaType
    {
        Regina = 1,
        Margarita = 2,
        Americana = 4,
        Fantasia = 8
    };

    enum PizzaSize
    {
        S = 1,
        M = 2,
        L = 4,
        XL = 8,
        XXL = 16
    };

    class Reception
    {
        public:
            Reception(double cookT, int max, int time);
            ~Reception();

            void status() const;
            void getCommand();
            bool checkCmdError();

            void createKitchen();
            // void destroyKitchen();

            double getCookingTime() const;
            int getMaxCook() const;
            int getRegenTime() const;
            int getNbKitchen() const;
            bool getCreateKitchen() const;
            Utils getMessageQueue() const;

            std::string getUserInput();
            pid_t doFork();
            pid_t doWaitpid(pid_t pid, int *wstatus, int options);
            int doMkfifo(std::string &pathname, mode_t mode);
            int doOpen(const std::string &pathname, int flags);
            std::string doRead(int fd);
            int doWrite(int fd, std::string get);
            int doClose(int fd);

        private:
            std::string _userInput = "";
            std::string _pipeName = "fifo.pipe";
            int _nbKitchen = 0;
            const double _cookingTime = -1;
            const int _maxCook = -1;
            const int _regenTime = -1;
            pid_t _child = -1;
            Utils _queue;
            pid_t pid = -1;
            bool _createKitchen = false;
            bool _fifo = false;
            int _retval = 0;
    };
} //namespace plazza
