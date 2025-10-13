/*
** EPITECH PROJECT, 2022
** B-CCP-400-RUN-4-1-theplazza-emilie.baunifais
** File description:
** MessageQueue
*/

#ifndef MESSAGEQUEUE_HPP_
#define MESSAGEQUEUE_HPP_

#include <sys/ipc.h>
#include <sys/types.h>
#include <sys/msg.h>
#include <iostream>
#include <string.h>

#define MAX 100

typedef struct message_queue_s {
    long int msg_type;
    char message[MAX];
} message_queue_t;

class MessageQueue {
    public:
        MessageQueue();
        ~MessageQueue();
        int createQueue();
        // sendQueue();
        message_queue_t _mqueue;
        int msgid;
    protected:
    private:
};

#endif /* !MESSAGEQUEUE_HPP_ */
