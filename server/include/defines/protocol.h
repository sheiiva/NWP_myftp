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

    #define COMMANDOK           "200 Command okay.\r\n"
    #define READYFORNEWUSER     "220 Service ready for new user.\r\n"
    #define LOGOUT              "221 Service closing control connection.\r\n"
    #define LOGGEDIN            "230 User logged in, proceed.\r\n"
    #define USERNAMEOK          "331 User name okay, need password.\r\n"
    #define WRONGCOMMAND        "500 Syntax error, command unrecognized.\r\n"
    #define NOTLOGGEDIN         "530 Not logged in.\r\n"
    //
    #define READYINNMIN         "120 Service ready in nnn minutes.\r\n"
    #define TRANSFERSTART\
        "125 Data connection already open; transfer starting.\r\n"
    #define OPENDATACONNECT\
        "150 File status okay; about to open data connection.\r\n"
    #define HELP_MESSAGE        "214 Help message.\r\n"
    #define CLOSEDATACONNECT    "226 Closing data connection.\r\n"
    #define PASSIVEMODE\
        "227 Entering Passive Mode (h1,h2,h3,h4,p1,p2).\r\n"
    #define ACTIONOK\
        "250 Requested file action okay, completed.\r\n"
    #define PATHNAMECREATED     "257 \"PATHNAME\" created.\r\n"
    #define NEEDACCOUNT         "332 Need account for login.\r\n"
    #define INSUFSTORAGE\
        "452 Requested action not taken: insufficient system storage.\r\n"
    #define WRONGARGUMENTS\
        "501 Syntax error in parameters or arguments.\r\n"
    #define NOTIMPLEMENTED      "502 Command not implemented.\r\n"
    #define ACTIONNOTTAKEN      "550 Requested action not taken.\r\n"
    #define ERROR               "xxx"

#endif /* !PROTOCOL_H_ */