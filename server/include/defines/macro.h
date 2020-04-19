/*
** EPITECH PROJECT, 2019
** SERVER // INCLUDE
** File description:
** macro.h
*/

#ifndef MACRO_H_
    #define MACRO_H_

    #define CLOSE       0
    #define OPEN        1
    #define BACKLOG     3

    #define COMMANDSNBR 12
    #define MAX_CLIENTS 1024

    #define BUFFERSIZE  100
    #define PATHSIZE    256

    typedef struct sockaddr sockaddr_t;
    typedef struct sockaddr_in sockaddr_in_t;

    #define COMMAND_H   "\
USER <SP> <username> <CRLF>   : Specify user for authentication\n\
PASS <SP> <password> <CRLF>   : Specify password to login\n\n\
CWD  <SP> <pathname> <CRLF>   : Change working directory\n\
CDUP <CRLF>                   : CWD to parent directory\n\n\
QUIT <CRLF>                   : Disconnection\n\n\
DELE <SP> <pathname> <CRLF>   : Delete file on the server\n\n\
PWD  <CRLF>                   : Print working directory\n\n\
PASV <CRLF>                   : 'passive' mode for data transfer\n\
PORT <SP> <host-port> <CRLF>  : 'active' mode for data transfer\n\
HELP [<SP> <string>] <CRLF>   : List available commands\n\n\
NOOP <CRLF>                   : Do nothing\n\n\
(the following are commands using data transfer )\n\
RETR <SP> <pathname> <CRLF>   : Download file from server\n\
STOR <SP> <pathname> <CRLF>   : Upload file from client to server\n\
LIST [<SP> <pathname>] <CRLF> : Files in the current directory\n\n"

    #define USAGE   "\
USAGE: ./myftp port path\n\
\tport\tis the port number on which the server socket listens\n\
\tpath\tis the path to the home directory for the Anonymous user\n"

#endif /* !MACRO_H_ */