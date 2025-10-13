/*
** EPITECH PROJECT, 2022
** B-CCP-400-RUN-4-1-theplazza-emilie.baunifais
** File description:
** Kitchen
*/

#pragma once

#include <queue>
#include <thread>
#include <list>
#include <iostream>
#include <chrono>
#include <mutex>
#include <sstream>
#include "Ingredients.hpp"
#include "Reception.hpp"
#include "Clock.hpp"

namespace plazza
{
    enum Ingredients
    {
        DOE = 0,
        TOMATO,
        GRUYERE,
        HAM,
        MUSHROOMS,
        STEAK,
        EGGPLANT,
        GOATCHEESE
    };

    class Kitchen {
        public:
            Kitchen(int cooks, double time, int regen);
            ~Kitchen();

            void createCooks(Utils queue);
            void cookingRegina(int id);
            void cookingMargarita(int id);
            void cookingAmericana(int id);
            void cookingFantasia(int id);
            std::queue<std::vector<int>> takeCommand();
            void refillIngredient();
            int closeKitchen();
            std::vector<std::string> initStatus(int id);
            void udpateStatus(int id, std::string status);
            std::vector<std::string> updateStatusCommand(int id, int type, int size, int nbr);

            double getCookingTime() const;
            int getRegenTime() const;
            std::queue<std::vector<int>> getCommand() const;
            Clock getTimeKitchen() const;
            Clock getTimeRefill() const;
            StockIngredients getStockIngredients() const;
            std::vector<std::string> getStatus() const;
            int getMaxCooks() const;

            void setCookingTime(double time);
            void setCommand(std::string command);
            std::vector<std::string> setStatusCommand();

        protected:
        private:
            int _regenTime;
            double _cookingTime;
            int _maxCook;
            int _cookAvailable;
            int _close;
            bool _stat;
            std::vector<std::string> _status;
            std::string _pipeName = "fifo.pipe";
            std::vector<std::thread> _cooks;
            std::mutex _mutex;
            std::queue<std::vector<int>> _command;
            StockIngredients _stock;
            Clock _timeKitchen;
            Clock _timeRefill;
    };
} //namespace plazza
