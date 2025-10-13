/*
** EPITECH PROJECT, 2022
** B-CCP-400-RUN-4-1-theplazza-emilie.baunifais
** File description:
** Error
*/

#pragma once

#include <string>
#include <exception>

namespace plazza {
    class Error : std::exception {
        public:
            Error();
            ~Error();

            bool isDigit(const std::string &s) const;
            bool isFloat(const std::string &s) const;
            const char *what() const throw() {
                return "Conditions not matched";
            }

        protected:
        private:
    };

    class ErrorStr : public Error {
        public:
            ErrorStr() {}
            ~ErrorStr() {}
            const char *what() const throw()
            {
                return "System internal Error.";
            }
        protected:
        private:
    };
} //namespace plazza
