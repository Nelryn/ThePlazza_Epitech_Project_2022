/*
** EPITECH PROJECT, 2022
** B-CCP-400-RUN-4-1-theplazza-emilie.baunifais
** File description:
** Utils
*/

#include "ParseCommand.hpp"
#include "Reception.hpp"

namespace plazza
{
    Utils::Utils()
    {
    }

    Utils::~Utils()
    {
    }

    void Utils::createMessageQueue()
    {
        this->_msgid = msgget((key_t)12345, 0666 | IPC_CREAT);
        if (this->_msgid == -1) {
            std::cout << "Error in creating queue\n" << std::endl;
            std::exit(84);
        }
    }

    void Utils::sendToMessageQueue(std::string command)
    {
        msgsnd(this->_msgid, (void *)command.c_str(), MAX, 0);
    }

    std::string Utils::getFromMessageQueue()
    {
        std::string mess;
        msgrcv(this->_msgid, (void *)this->_queue.c_str(), MAX, 0, 0);
        mess = this->_queue.c_str();
        return mess;
    }

    void Utils::destroyMessageQueue()
    {
        msgctl(this->_msgid, IPC_RMID, 0);
    }

    void Utils::showMessage()
    {
        std::cout << this->_queue.c_str() << std::endl;
    }

    std::string Utils::getMessage()
    {
        return this->_queue;
    }

    bool Utils::emptymessageQueue()
    {
        msgctl(this->_msgid, IPC_STAT, &this->_buf);
        // std::cout << this->_buf.msg_qnum << std::endl;
        if (this->_buf.msg_qnum > 0)
            return false;
        return true;
    }

    void Utils::getInput()
    {
        std::cin >> this->_queue;
    }

    bool Utils::sendIfCommandGood(std::string command, int nb_cook)
    {
        ParseCommand parse;
        std::string tmp = command;
        std::string sub;
        std::string word;
        std::string to_send;
        int i = 0;
        bool sendable = true;
        bool display_menu = false;
        std::vector<std::string> all_str;

        for (;tmp.find(";") != std::string::npos;) {
            for (; tmp[i] != ';'; i++);
            sub = parse.eraseUselessSpaces(tmp.substr(0, i));
            tmp = tmp.substr(i + 1, (command.length() - sub.length()));
            if (sub.compare("status") == 0) {
                all_str.push_back("0 0 0");
            } else {
                if (parse.checkNbWord(sub) == false)
                    sendable = false;
                if (sendable == true && parse.checkPizzaName(sub) == false)
                    sendable = false;
                if (sendable == true && parse.checkPizzaSize(sub) == false)
                    sendable = false;
                if (sendable == true && parse.checkPizzaAmount(sub, nb_cook) == false)
                    sendable = false;
                if (sendable == true) {
                    word = parse.getPizzaName(sub);
                    if (word.compare("regina") == 0)
                        to_send += std::to_string(PizzaType::Regina);
                    if (word.compare("margarita") == 0)
                        to_send += std::to_string(PizzaType::Margarita);
                    if (word.compare("americana") == 0)
                        to_send += std::to_string(PizzaType::Americana);
                    if (word.compare("fantasia") == 0)
                        to_send += std::to_string(PizzaType::Fantasia);
                    to_send += " ";
                    word = parse.getPizzaSize(sub);
                    if (word.compare("s") == 0)
                        to_send += std::to_string(PizzaSize::S);
                    if (word.compare("m") == 0)
                        to_send += std::to_string(PizzaSize::M);
                    if (word.compare("l") == 0)
                        to_send += std::to_string(PizzaSize::L);
                    if (word.compare("xl") == 0)
                        to_send += std::to_string(PizzaSize::XL);
                    if (word.compare("xxl") == 0)
                        to_send += std::to_string(PizzaSize::XXL);
                    to_send += " ";
                    to_send += &parse.getPizzaAmount(sub)[1];
                    all_str.push_back(to_send);
                    to_send.clear();
                } else {
                    display_menu = true;
                }
            }
            sendable = true;
            i = 0;
        }
        to_send.clear();
        tmp = parse.eraseUselessSpaces(tmp);
        if (tmp.compare("status") == 0) {
            all_str.push_back("0 0 0");
        } else {
            if (parse.checkNbWord(tmp) == false)
                sendable = false;
            if (sendable == true && parse.checkPizzaName(tmp) == false)
                sendable = false;
            if (sendable == true && parse.checkPizzaSize(tmp) == false)
                sendable = false;
            if (sendable == true && parse.checkPizzaAmount(tmp, nb_cook) == false)
                sendable = false;
            if (sendable == true) {
                word = parse.getPizzaName(tmp);
                if (word.compare("regina") == 0)
                    to_send += std::to_string(PizzaType::Regina);
                if (word.compare("margarita") == 0)
                    to_send += std::to_string(PizzaType::Margarita);
                if (word.compare("americana") == 0)
                    to_send += std::to_string(PizzaType::Americana);
                if (word.compare("fantasia") == 0)
                    to_send += std::to_string(PizzaType::Fantasia);
                to_send += " ";
                word = parse.getPizzaSize(tmp);
                if (word.compare("s") == 0)
                    to_send += std::to_string(PizzaSize::S);
                if (word.compare("m") == 0)
                    to_send += std::to_string(PizzaSize::M);
                if (word.compare("l") == 0)
                    to_send += std::to_string(PizzaSize::L);
                if (word.compare("xl") == 0)
                    to_send += std::to_string(PizzaSize::XL);
                if (word.compare("xxl") == 0)
                    to_send += std::to_string(PizzaSize::XXL);
                to_send += " ";
                to_send += &parse.getPizzaAmount(tmp)[1];
                all_str.push_back(to_send);
            } else {
                display_menu = true;
            }
        }
        for (auto i = all_str.begin(); i != all_str.end(); i++) {
            this->sendToMessageQueue(*i);
        }
        if (display_menu == true)
            return false;
        return true;
    }
}