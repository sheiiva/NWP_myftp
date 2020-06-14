/*
** EPITECH PROJECT, 2019
** SERVER // INCLUDE
** File description:
** structures.h
*/

#ifndef STRUCTURES_H_
    #define STRUCTURES_H_

    #include <arpa/inet.h>
    #include <stdbool.h>
    #include <sys/types.h>
    #include <sys/socket.h>
    #include <sys/select.h>
    #include <sys/time.h>
    #include <unistd.h>

    #include "macro.h"

    typedef struct client_s
    {
        int sockfd;
        char name[BUFFERSIZE];
        char password[BUFFERSIZE];
        int state;
    } client_t;

    typedef struct server_s {
        char buffer[BUFFERSIZE];
        struct sockaddr_in addr;
        unsigned int addrlen;
        int sockfd;
        int new_sockfd;
        client_t clients[FD_SETSIZE];
        int max_sd;
        fd_set readfds;
    } server_t;

#endif /* !STRUCTURES_H_ */