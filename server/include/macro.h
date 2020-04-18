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

#endif /* !MACRO_H_ */