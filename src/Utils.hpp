/*
** EPITECH PROJECT, 2022
** B-CCP-400-RUN-4-1-theplazza-emilie.baunifais
** File description:
** utils
*/

#ifndef UTILS_HPP_
#define UTILS_HPP_

#include <sys/ipc.h>
#include <sys/types.h>
#include <sys/msg.h>
#include <iostream>
#include <string.h>
#include <string>
#include <vector>

#define MAX 100

namespace plazza
{
    class Utils {
        public:
            Utils();
            ~Utils();
            void createMessageQueue();
            void sendToMessageQueue(std::string command);
            std::string getFromMessageQueue();
            void destroyMessageQueue();
            void showMessage();
            std::string getMessage();
            bool emptymessageQueue();
            void getInput();
            bool sendIfCommandGood(std::string command, int nb_cook);
        protected:
        private:
            std::string _queue;
            msqid_ds _buf;
            int _msgid = 0;
    };
} // namespace plazza

#endif /* !UTILS_HPP_ */
