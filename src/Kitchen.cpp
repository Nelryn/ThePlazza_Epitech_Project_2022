/*
** EPITECH PROJECT, 2022
** B-CCP-400-RUN-4-1-theplazza-emilie.baunifais
** File description:
** Kitchen
*/

#include "Kitchen.hpp"

namespace plazza
{
    Kitchen::Kitchen(int cooks, double time, int regen)
    {
        _maxCook = cooks;
        _cookingTime = time;
        _regenTime = regen;
        _close = 0;
        _stat = false;
    }

    Kitchen::~Kitchen()
    {
    }

    void Kitchen::setCookingTime(double time)
    {
        this->_cookingTime = time;
    }

    void Kitchen::setCommand(std::string command)
    {
        std::vector<int> list;
        std::string cmd;

        this->_mutex.lock();
        _timeKitchen.restart();
        std::stringstream stream(command);
        while (std::getline(stream, cmd, ' '))
            list.push_back(std::stoi(cmd));
        if (list.at(0) == 0 && list.at(1) == 0 && list.at(2) == 0) {
            for (size_t p = 0; p < this->getStatus().size(); p++)
               std::cout << this->getStatus().at(p) << std::endl;
            _stat = true;
        } else {
            for (int i = 0; i < list.back(); i++)
                _command.push(list);
        }
        this->_mutex.unlock();
    }

    double Kitchen::getCookingTime() const
    {
        return this->_cookingTime;
    }

    int Kitchen::getRegenTime() const
    {
        return _regenTime;
    }

    std::queue<std::vector<int>> Kitchen::getCommand() const
    {
        return _command;
    }

    Clock Kitchen::getTimeKitchen() const
    {
        return _timeKitchen;
    }

    Clock Kitchen::getTimeRefill() const
    {
        return _timeRefill;
    }

    StockIngredients Kitchen::getStockIngredients() const
    {
        return _stock;
    }

    std::vector<std::string> Kitchen::getStatus() const
    {
        return _status;
    }

    int Kitchen::getMaxCooks() const
    {
        return _maxCook;
    }

    void Kitchen::cookingRegina(int id)
    {
        Clock time;

        this->udpateStatus(id, "I am waiting ingredients...");
        while (_stock.makeRegina() == false)
            this->refillIngredient();
        time.restart();
        this->udpateStatus(id, "I am cooking regina...");
        while (time.getTimeAsSeconds() < _cookingTime * 2) {
            _timeKitchen.restart();
        }
        this->udpateStatus(id, "Regina is ready");
    }

    void Kitchen::cookingMargarita(int id)
    {
        Clock time;

        this->udpateStatus(id, "I am waiting ingredients...");
        while (_stock.makeMargarita() == false)
            this->refillIngredient();
        time.restart();
        this->udpateStatus(id, "I am cooking margarita...");
        while (time.getTimeAsSeconds() < 1) {
            _timeKitchen.restart();
        }
        this->udpateStatus(id, "Margarita is ready");
    }

    void Kitchen::cookingAmericana(int id)
    {
        Clock time;

        this->udpateStatus(id, "I am waiting ingredients...");
        while (_stock.makeAmericana() == false)
            this->refillIngredient();
        time.restart();
        this->udpateStatus(id, "I am cooking americana...");
        while (time.getTimeAsSeconds() < _cookingTime * 2) {
            _timeKitchen.restart();
        }
        this->udpateStatus(id, "Americana is ready");
    }

    void Kitchen::cookingFantasia(int id)
    {
        Clock time;

        this->udpateStatus(id, "I am waiting ingredients...");
        while (_stock.makeFantasia() == false)
            this->refillIngredient();
        time.restart();
        this->udpateStatus(id, "I am cooking fantasia...");
        while (time.getTimeAsSeconds() < _cookingTime * 4) {
            _timeKitchen.restart();
        }
        this->udpateStatus(id, "Fantasia is ready");
    }

    std::queue<std::vector<int>> Kitchen::takeCommand()
    {
        if (!_command.empty())
            _command.pop();
        return _command;
    }

    void Kitchen::refillIngredient()
    {
        _stock.refill(&_timeRefill, _regenTime);
    }

    int Kitchen::closeKitchen()
    {
        _close += 1;
        return _close;
    }

    std::vector<std::string> Kitchen::initStatus(int index)
    {
        std::string stat = "Cook ";
        stat.append(std::to_string(index));
        stat.append(": I am ready");
        _status.push_back(stat);
        return _status;
    }

    std::vector<std::string> Kitchen::setStatusCommand()
    {
        _status.push_back("Command is not ready");
        return _status;
    }

    void Kitchen::udpateStatus(int id, std::string status)
    {
        std::string stat = "Cook ";
        stat.append(std::to_string(id));
        stat.append(": ");
        stat.append(status);
        _status.at(id) = stat;
        //for (size_t p = 0; p < this->getStatus().size(); p++)
        //    std::cout << this->getStatus().at(p) << std::endl;
    }

    std::vector<std::string> Kitchen::updateStatusCommand(int id, int type, int size, int nbr)
    {
        std::string stat = "Command '";
        if (type == Regina)
            stat.append("Regina ");
        if (type == Margarita)
            stat.append("Margarita ");
        if (type == Americana)
            stat.append("Americana ");
        if (type == Fantasia)
            stat.append("Fantasia ");
        if (size == S)
            stat.append("S x");
        if (size == M)
            stat.append("M x");
        if (size == L)
            stat.append("L x");
        if (size == XL)
            stat.append("XL x");
        if (size == XXL)
            stat.append("XXL x");
        stat.append(std::to_string(nbr));
        stat.append("' is ready");
        _status.at(id) = stat;
        return _status;
    }

    void Kitchen::createCooks(Utils queue)
    {
        for (int i = 0; i < _maxCook; i++) {
            std::this_thread::sleep_for(std::chrono::seconds(1));
            _cooks.push_back(std::thread([&, i]{
                std::vector<int> cmd;
                bool end = false;
                this->initStatus(i);
                while (this->getTimeKitchen().getTimeAsSeconds() < 5) {
                    this->udpateStatus(i, "I am free");
                    this->refillIngredient();
                    if (this->getCommand().empty() && this->getTimeKitchen().getTimeAsSeconds() < 5 && !queue.emptymessageQueue()) {
                        this->setCommand(queue.getFromMessageQueue());
                    }
                    this->_mutex.lock();
                    if (!this->getCommand().empty()) {
                        for (size_t j = 0; j < this->getCommand().front().size(); j++) {
                            cmd.push_back(this->getCommand().front().at(j));
                        }
                    }
                    this->takeCommand();
                    if (!cmd.empty() && this->getCommand().empty())
                        end = true;
                    if (!this->getCommand().empty() && cmd.at(0) != this->getCommand().front().at(0) &&
                    cmd.at(1) != this->getCommand().front().at(1) && cmd.at(2) != this->getCommand().front().at(2)) {
                        end = true;
                    }
                    this->_mutex.unlock();
                    if (this->getStatus().size() == this->getMaxCooks())
                        this->setStatusCommand();
                    if (!cmd.empty() && cmd.front() == Regina)
                        this->cookingRegina(i);
                    if (!cmd.empty() && cmd.front() == Margarita)
                        this->cookingMargarita(i);
                    if (!cmd.empty() && cmd.front() == Americana)
                        this->cookingAmericana(i);
                    if (!cmd.empty() && cmd.front() == Fantasia)
                        this->cookingFantasia(i);
                    if (end == true && !cmd.empty() && this->getStatus().size() == this->getMaxCooks() + 1) {
                        this->updateStatusCommand(this->getMaxCooks(), cmd.at(0), cmd.at(1), cmd.at(2));
                        end = false;
                    }
                    std::this_thread::sleep_for(std::chrono::seconds(1));
                    while (!cmd.empty())
                        cmd.pop_back();
                }
                this->closeKitchen();
                return true;
            }));
        }
        for (int i = 0; i < _maxCook; i++) {
            _cooks[i].join();
        }
    }
} //namespace plazza
