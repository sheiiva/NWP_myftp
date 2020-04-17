/*
** EPITECH PROJECT, 2019
** SERVER // INCLUDE
** File description:
** protocol.h
*/

#ifndef PROTOCOL_H_
    #define PROTOCOL_H_

    #define CLRF    "\r\n"
    #define SP      " "

    #define USER    "USER"
    #define PASS    "PASS"
    #define CWD     "CWD"
    #define CDUP    "CDUP"
    #define PWD     "PWD"
    #define PASV    "PASV"
    #define PORT    "PORT"
    #define HELPM   "HELP"
    #define NOOP    "NOOP"
    #define RETR    "RETR"
    #define STOR    "STOR"
    #define LIST    "LIST"

    #define READYFORNMIN        "120"
    #define TRANSFERSTART       "125"
    #define OPENDATACONNECT     "150"
    #define COMMANDOK           "200"
    #define HELP MESSAGE        "214"
    #define READYFORNEWUSER     "220"
    #define LOGOUT              "221"
    #define CLOSEDATACONNECT    "226"
    #define PASSIVEMODE         "227"
    #define LOGGEDIN            "230"
    #define ACTIONOK            "250"
    #define PATHNAMECREATED     "257"
    #define USERNAMEOK          "331"
    #define NEEDACCOUNT         "332"
    #define ERROR               "XXX"

#endif /* !PROTOCOL_H_ */