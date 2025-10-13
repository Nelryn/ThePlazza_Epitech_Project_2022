/*
** EPITECH PROJECT, 2022
** B-CCP-400-RUN-4-1-theplazza-emilie.baunifais
** File description:
** ParseCommand
*/

#ifndef PARSECOMMAND_HPP_
#define PARSECOMMAND_HPP_

#include <vector>
#include <iostream>
#include <algorithm>
#include <string.h>

namespace plazza {

    class ParseCommand {
        public:
            ParseCommand();
            ~ParseCommand();
            std::string eraseUselessSpaces(std::string str);
            std::string getPizzaName(std::string pizza);
            std::string getPizzaSize(std::string pizza);
            std::string getPizzaAmount(std::string pizza);
            bool checkPizzaName(std::string pizza);
            bool checkPizzaSize(std::string size);
            bool checkPizzaAmount(std::string amount, int nb_cook);
            bool checkNbWord(std::string command);
        protected:
        private:
    };
}

#endif /* !PARSECOMMAND_HPP_ */
