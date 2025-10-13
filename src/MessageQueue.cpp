/*
** EPITECH PROJECT, 2022
** B-CCP-400-RUN-4-1-theplazza-emilie.baunifais
** File description:
** MessageQueue
*/

#include "MessageQueue.hpp"

MessageQueue::MessageQueue()
{
}

MessageQueue::~MessageQueue()
{
}

int MessageQueue::createQueue()
{
    this->msgid = msgget((key_t)12345, 0666 | IPC_CREAT);
    if (this->msgid == -1) {
        std::cout << "Error in creating queue\n" << std::endl;
        std::exit(84);
    }
    return this->msgid;
}