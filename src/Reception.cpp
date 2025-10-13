/*
** EPITECH PROJECT, 2022
** B-CCP-400-RUN-4-1-theplazza-emilie.baunifais
** File description:
** Reception
*/

#include "Reception.hpp"
#include "ParseCommand.hpp"
#include "Kitchen.hpp"
#include <queue>

namespace plazza {
    Reception::Reception(double cookT, int max, int time) : _cookingTime(cookT),
        _maxCook(max), _regenTime(time)
    {
        _queue.createMessageQueue();
    }

    Reception::~Reception()
    {
        _queue.destroyMessageQueue();
    }

    void Reception::status() const
    {
        std::cout << "Current number of kitchen: " << _nbKitchen << std::endl;
        // current occupancy of cooks
        // Stock of ingredients
    }

    double Reception::getCookingTime() const
    {
        return this->_cookingTime;
    }

    int Reception::getMaxCook() const
    {
        return this->_maxCook;
    }

    int Reception::getRegenTime() const
    {
        return this->_regenTime;
    }

    int Reception::getNbKitchen() const
    {
        return this->_nbKitchen;
    }

    bool Reception::getCreateKitchen() const
    {
        return this->_createKitchen;
    }

    void Reception::getCommand()
    {
        std::string str;
        ParseCommand parse;

        std::getline(std::cin, str);
        if (std::cin.eof() == 1)
            std::exit(84);
        _userInput = parse.eraseUselessSpaces(str);
        for (int a = 0; a != _userInput.length(); a++)
            _userInput[a] = ::tolower(_userInput[a]);
        _createKitchen = _queue.sendIfCommandGood(this->getUserInput(), this->getMaxCook());
        if (!_createKitchen) {
            std::cout << "Menu: [Pizza] [Size] x[Number of pizza]" << std::endl;
            std::cout << "Pizzas: " << std::endl << "\tRegina\n\tMargarita\n\tAmericana\n\tFantasia" << std::endl;
            std::cout << "Sizes: " << std::endl << "\tS\n\tM\n\tL\n\tXL\n\tXXL" << std::endl;
            std::cout << "The number of pizza can't be over 2 times the number of cooks" << std::endl;
        }
    }

    bool Reception::checkCmdError()
    {
        return false;
    }

    std::string Reception::getUserInput()
    {
        return this->_userInput;
    }

    pid_t Reception::doFork()
    {
        return fork();
    }

    pid_t Reception::doWaitpid(pid_t pid, int *wstatus, int options)
    {
        return waitpid(pid, wstatus, options);
    }

    void Reception::createKitchen()
    {
        int fd_child = 0;
        int fd_parent = 0;
        int status = 0;

        if (!_fifo) {
            _retval = this->doMkfifo(this->_pipeName, S_IRWXU);
            _fifo = true;
        }

        int child = this->doFork();
        Kitchen *kitchen = new Kitchen(this->getMaxCook(), this->getCookingTime(), this->getRegenTime());

        if (child == -1) {
            std::cerr << "Error Fork" << std::endl;
            throw(-1);
        } else if (child == 0) {
            kitchen->createCooks(this->_queue);
            // for (size_t p = 0; p < kitchen->getStatus().size(); p++)
            //    std::cout << kitchen->getStatus().at(p) << std::endl;
            // send to ipc HERE
            if (kitchen->closeKitchen() == this->getMaxCook()) {
                delete kitchen;
                fd_child = this->doOpen(this->_pipeName, O_WRONLY);
                this->doWrite(fd_child, "destroyed.\n");
                this->doClose(fd_child);
                std::exit(0);
            }
        } else {
            _nbKitchen++;
            _createKitchen = false;
            doWaitpid(child, &status, WNOHANG);
            fd_parent = this->doOpen(this->_pipeName, O_RDONLY);
            std::string buffer = this->doRead(fd_parent);
            this->doClose(fd_parent);
            if (buffer.compare("destroyed.") == 0) {
                _createKitchen = true;
                _nbKitchen--;
            }
        }
    }

    Utils Reception::getMessageQueue() const
    {
        return _queue;
    }

    int Reception::doMkfifo(std::string &pathname, mode_t mode)
    {
        return mkfifo(pathname.c_str(), mode);
    }

    int Reception::doOpen(const std::string &pathname, int flags)
    {
        return open(pathname.c_str(), flags);
    }

    std::string Reception::doRead(int fd)
    {
        char c;
        std::string str;

        while (read(fd, &c, 1) != -1) {
            if (c == '\n')
                break;
            write(1, &c, 1);
            str.append(&c);
        }
        return str;
    }

    int Reception::doWrite(int fd, std::string get)
    {
        return write(fd, get.c_str(), get.length());
    }

    int Reception::doClose(int fd)
    {
        return close(fd);
    }
} //namespace plazza
