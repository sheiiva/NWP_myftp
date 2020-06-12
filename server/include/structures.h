/*
** EPITECH PROJECT, 2019
** SERVER // INCLUDE
** File description:
** structures.h
*/

#ifndef STRUCTURES_H_
    #define STRUCTURES_H_

    #include <stdbool.h>
    #include <sys/types.h>
    #include <sys/socket.h>

    #include "macro.h"

    typedef struct client_s {
        int fd;
        bool connected;
        struct sockaddr_in socket;
        char path[PATHSIZE];
        char name[BUFFERSIZE];
    } client_t;

    typedef struct server_s {
        int fd;
        int port;
        struct sockaddr_in socket;
        char buffer[BUFFERSIZE];
    } server_t;

#endif /* !STRUCTURES_H_ */