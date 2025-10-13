/*
** EPITECH PROJECT, 2022
** B-CCP-400-RUN-4-1-theplazza-emilie.baunifais
** File description:
** Ingredients
*/

#include "Ingredients.hpp"
#include <iostream>

namespace plazza
{
    StockIngredients::StockIngredients()
    {
        this->_doe = 5;
        this->_tomato = 5;
        this->_gruyere = 5;
        this->_ham = 5;
        this->_mushrooms = 5;
        this->_steak = 5;
        this->_eggplant = 5;
        this->_goatcheese = 5;
    }

    StockIngredients::~StockIngredients()
    {
    }

    int StockIngredients::getDoe() const
    {
        return this->_doe;
    }

    int StockIngredients::getTomato() const
    {
        return this->_tomato;
    }

    int StockIngredients::getGruyere() const
    {
        return this->_gruyere;
    }

    int StockIngredients::getHam() const
    {
        return this->_ham;
    }

    int StockIngredients::getMushrooms() const
    {
        return this->_mushrooms;
    }

    int StockIngredients::getSteak() const
    {
        return this->_steak;
    }

    int StockIngredients::getEggplant() const
    {
        return this->_eggplant;
    }

    int StockIngredients::getGoatcheese() const
    {
        return this->_goatcheese;
    }

    void StockIngredients::regenerateFood()
    {
        this->_doe += 1;
        this->_tomato += 1;
        this->_gruyere += 1;
        this->_ham += 1;
        this->_mushrooms += 1;
        this->_steak += 1;
        this->_eggplant += 1;
        this->_goatcheese += 1;
    }

    bool StockIngredients::makeMargarita()
    {
        if (this->_doe > 0 && this->_tomato > 0 && this->_gruyere > 0) {
            this->_doe -= 1;
            this->_tomato -= 1;
            this->_gruyere -= 1;
            return true;
        }
        return false;
    }

    bool StockIngredients::makeRegina()
    {
        if (this->_doe > 0 && this->_tomato > 0 && this->_gruyere > 0 && this->_ham > 0 && this->_mushrooms > 0) {
            this->_doe -= 1;
            this->_tomato -= 1;
            this->_gruyere -= 1;
            this->_ham -= 1;
            this->_mushrooms -= 1;
            return true;
        }
        return false;
    }

    bool StockIngredients::makeAmericana()
    {
        if (this->_doe > 0 && this->_tomato > 0 && this->_gruyere > 0 && this->_steak > 0) {
            this->_doe -= 1;
            this->_tomato -= 1;
            this->_gruyere -= 1;
            this->_steak -= 1;
            return true;
        }
        return false;
    }

    bool StockIngredients::makeFantasia()
    {
        if (this->_doe > 0 && this->_tomato > 0 && this->_eggplant > 0 && this->_goatcheese > 0) {
            this->_doe -= 1;
            this->_tomato -= 1;
            this->_eggplant -= 1;
            this->_goatcheese -= 1;
            return true;
        }
        return false;
    }

    void StockIngredients::showIngredientsAmount()
    {
        std::cout << "Doe: " << this->getDoe() << std::endl;
        std::cout << "Tomato: " << this->getTomato() << std::endl;
        std::cout << "Gruyère: " << this->getGruyere() << std::endl;
        std::cout << "Ham: " << this->getHam() << std::endl;
        std::cout << "Mushroom: " << this->getMushrooms() << std::endl;
        std::cout << "Steak: " << this->getSteak() << std::endl;
        std::cout << "Eggplant: " << this->getEggplant() << std::endl;
        std::cout << "Goat: " << this->getGoatcheese() << std::endl;
    }

    void StockIngredients::refill(Clock *time, int interval)
    {
        if ((*time).getTimeInMilliSeconds() >= interval) {
            this->regenerateFood();
            (*time).restart();
        }
    }
}
