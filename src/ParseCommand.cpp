/*
** EPITECH PROJECT, 2022
** B-CCP-400-RUN-4-1-theplazza-emilie.baunifais
** File description:
** ParseCommand
*/

#include "ParseCommand.hpp"
#include "Reception.hpp"

namespace plazza {

    ParseCommand::ParseCommand()
    {
    }

    ParseCommand::~ParseCommand()
    {
    }

    std::string ParseCommand::eraseUselessSpaces(std::string str)
    {
        int i = 0;
        int copy_index = 0;
        int count_less = 0;
        std::string copy;

        while (str[0] != str[str.length()]) {
            if (str[0] != ' ' && str[0] != ';')
                break;
            str = &str[1];
        }
        if (str[0] == '\0') {
            copy = "";
            return copy;
        }
        for (int a = str.length() - 1; a != 0; a--, count_less++) {
            if (str[a] != ' ' && str[a] != ';')
                break;
        }
        for (; i != str.length() - count_less; i++, copy_index++) {
            if (str[i] == ' ') {
                for (; str[i + 1] == ' '; i++);
            }
            copy += str[i];
        }
        copy[copy_index] = '\0';
        return copy;
    }

    std::string ParseCommand::getPizzaName(std::string pizza)
    {
        int i = 0;
        std::string name;

        for (; pizza[i] != ' '; i++)
            if (i == pizza.length())
                break;
        name = pizza.substr(0, i);
        return name;
    }

    std::string ParseCommand::getPizzaSize(std::string pizza)
    {
        int size_pizza = 0;
        int i = 0;
        std::string required_size;

        for (; pizza[i] != ' '; i++)
            if (i == pizza.length())
                break;
        for (int a = i + 1; pizza[a] != ' '; a++) {
            if (a == pizza.length())
                break;
            size_pizza++;
        }
        required_size = pizza.substr(i + 1, size_pizza);
        return required_size;
    }

    std::string ParseCommand::getPizzaAmount(std::string pizza)
    {
        int i = 0;
        int nb_char_nb_commands = 0;
        int count_space = 2;
        std::string nb_pizza;

        for (; count_space != 0; i++) {
            if (pizza[i] == ' ')
                count_space--;
            if (i == pizza.length())
                break;
        }
        for (int a = i; a != pizza.length(); a++)
            nb_char_nb_commands++;
        nb_pizza = pizza.substr(i, nb_char_nb_commands);
        return nb_pizza;
    }

    bool ParseCommand::checkPizzaName(std::string pizza)
    {
        int i = 0;
        std::vector<std::string> menu = {"regina", "margarita", "americana", "fantasia"};
        std::string name;

        for (; pizza[i] != ' '; i++)
            if (i == pizza.length())
                break;
        name = pizza.substr(0, i);
        if (std::find(menu.begin(), menu.end(), name.c_str()) != menu.end())
            return true;
        std::cerr << "Pizza name not found..." << std::endl;
        return false;
    }

    bool ParseCommand::checkPizzaSize(std::string pizza)
    {
        std::vector<std::string> sizes = {"s", "m", "l", "xl", "xxl"};
        int size_pizza = 0;
        int i = 0;
        std::string required_size;

        for (; pizza[i] != ' '; i++)
            if (i == pizza.length())
                break;
        for (int a = i + 1; pizza[a] != ' '; a++) {
            if (a == pizza.length())
                break;
            size_pizza++;
        }
        required_size = pizza.substr(i + 1, size_pizza);
        if (std::find(sizes.begin(), sizes.end(), required_size.c_str()) != sizes.end())
            return true;
        std::cerr << "Size not accepted" << std::endl;
        return false;
    }

    bool ParseCommand::checkPizzaAmount(std::string pizza, int nb_cook)
    {
        int i = 0;
        int nb_char_nb_commands = 0;
        int count_space = 2;
        std::string nb_pizza;


        for (; count_space != 0; i++) {
            if (pizza[i] == ' ')
                count_space--;
            if (i == pizza.length())
                break;
        }
        for (int a = i; a != pizza.length(); a++)
            nb_char_nb_commands++;
        nb_pizza = pizza.substr(i, nb_char_nb_commands);
        if (nb_pizza[0] != 'x') {
            std::cerr << "Don't begin by x, not accepted" << std::endl;
            return false;
        }
        for (int a = 1; a != nb_pizza.length(); a++) {
            if (nb_pizza[a] < '0' || nb_pizza[a] > '9') {
                std::cerr << "Else than a number" << std::endl;
                return false;
            }
        }
        if (std::stoi(&nb_pizza[1]) > (nb_cook * 2)) {
            std::cerr << "Too much pizza" << std::endl;
            return false;
        }
        return true;
    }

    bool ParseCommand::checkNbWord(std::string command)
    {
        int nb_word = 0;

        for (int i = 0; i != command.length(); i++) {
            if (i + 1 == command.length())
                nb_word++;
            if (command[i] == ' ')
                nb_word++;
        }
        if (nb_word != 3)
            return false;
        return true;
    }
}