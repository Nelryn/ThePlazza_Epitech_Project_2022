/*
** EPITECH PROJECT, 2022
** B-CCP-400-RUN-4-1-theplazza-emilie.baunifais
** File description:
** Ingredients
*/

#pragma once

#include "Clock.hpp"

namespace plazza
{
    class StockIngredients
    {
        public:
            StockIngredients();
            ~StockIngredients();

            int getDoe() const;
            int getTomato() const;
            int getGruyere() const;
            int getHam() const;
            int getMushrooms() const;
            int getSteak() const;
            int getEggplant() const;
            int getGoatcheese() const;
            void regenerateFood();
            bool makeMargarita();
            bool makeRegina();
            bool makeAmericana();
            bool makeFantasia();
            void showIngredientsAmount();
            void refill(Clock *time, int interval);
        private:
            int _doe;
            int _tomato;
            int _gruyere;
            int _ham;
            int _mushrooms;
            int _steak;
            int _eggplant;
            int _goatcheese;
    };
}
