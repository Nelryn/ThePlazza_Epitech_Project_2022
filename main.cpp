/*
** EPITECH PROJECT, 2022
** B-CCP-400-RUN-4-1-theplazza-emilie.baunifais
** File description:
** main
*/

#include "src/Reception.hpp"
#include "src/Kitchen.hpp"
#include "src/Error.hpp"
#include "src/ParseCommand.hpp"
#include "src/Clock.hpp"
#include "src/Ingredients.hpp"

int main(int ac, char **av)
{
    plazza::Utils queue;
    plazza::Error err;
    plazza::ParseCommand parse;
    plazza::Clock time;
    plazza::StockIngredients stock;

    try {
        if (ac != 4)
            throw ac;
        if (!err.isFloat(std::string(av[1])))
            throw(84);
        for (int i = 2; i < 4; i++) {
            if (!err.isDigit(std::string(av[i])))
                throw 84;
        }
        plazza::Reception rec(std::stod(std::string(av[1])),
        std::stoi(std::string(av[2])), std::stoi(std::string(av[3])));
        while (1) {
            std::cout << "> ";
            rec.getCommand();
            if (rec.getNbKitchen() == 0 && rec.getCreateKitchen()) {
                rec.createKitchen();
            }
        }
    } catch(int e) {
        std::cerr << "An exception was caught. Returned code: " << e << std::endl;
        return e;
    }
    return 0;
}
