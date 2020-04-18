/*
** EPITECH PROJECT, 2019
** SERVER // INCLUDE
** File description:
** entities.h
*/

#ifndef ENTITIES_H_
    #define ENTITIES_H_

    #include <stdbool.h>
    #include <sys/types.h>
    #include <sys/socket.h>

    #include "macro.h"

    typedef struct client_s {
        int fd;
        bool connected;
        struct sockaddr_in socket;
        char path[PATHSIZE];
    } client_t;

    typedef struct server_s {
        int fd;
        int port;
        struct sockaddr_in socket;
        char buffer[BUFFERSIZE];
    } server_t ;


#endif /* !ENTITIES_H_ */