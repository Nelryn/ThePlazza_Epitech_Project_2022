/*
** EPITECH PROJECT, 2022
** B-CCP-400-RUN-4-1-theplazza-emilie.baunifais
** File description:
** Error
*/

#include "Error.hpp"

namespace plazza
{
    Error::Error()
    {
    }

    Error::~Error()
    {
    }

    bool Error::isDigit(const std::string &s) const
    {
        for (int i = 0; i < s.length(); i++) {
            if (!isdigit(s[i]))
                return false;
        }
        return true;
    }

    bool Error::isFloat(const std::string &s) const
    {
        int dot = 0;

        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '.')
                dot++;
        }
        if (dot == 0)
            return this->isDigit(s);
        else if (dot > 1 || s[0] == '.')
            return false;
        for (int i = 0; i < s.length(); i++) {
            if (!isdigit(s[i]) && s[i] != '.')
                return false;
        }
        int nb = std::stoi(s);
        if (dot == 1 && nb > 1)
            return false;
        return true;
    }
} // namespace plazza
