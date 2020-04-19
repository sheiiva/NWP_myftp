/*
** EPITECH PROJECT, 2019
** SERVER // INCLUDE
** File description:
** protocol.h
*/

#ifndef PROTOCOL_H_
    #define PROTOCOL_H_

    #define CLRF   "\r\n"
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
    #define QUIT    "QUIT"

    #define READYINNMIN         "120 Service ready in nnn minutes."
    #define TRANSFERSTART       "125 Data connection already open; transfer starting."
    #define OPENDATACONNECT     "150 File status okay; about to open data connection."
    #define COMMANDOK           "200 Command okay."
    #define HELP_MESSAGE        "214 Help message."
    #define READYFORNEWUSER     "220 Service ready for new user."
    #define LOGOUT              "221 Service closing control connection."
    #define CLOSEDATACONNECT    "226 Closing data connection."
    #define PASSIVEMODE         "227 Entering Passive Mode (h1,h2,h3,h4,p1,p2)."
    #define LOGGEDIN            "230 User logged in, proceed."
    #define ACTIONOK            "250 Requested file action okay, completed."
    #define PATHNAMECREATED     "257 \"PATHNAME\" created."
    #define USERNAMEOK          "331 User name okay, need password."
    #define NEEDACCOUNT         "332 Need account for login."
    #define ERROR               "xxx Error (RFC compliant)"

#endif /* !PROTOCOL_H_ */