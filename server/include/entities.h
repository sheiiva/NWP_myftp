/*
** EPITECH PROJECT, 2019
** SERVER // INCLUDE
** File description:
** entities.h
*/

#ifndef ENTITIES_H_
    #define ENTITIES_H_

    #define BUFFERSIZE  100
    #define PATHSIZE    256

    #include <stdbool.h>
    
    typedef struct client_s {
        int fd;
        bool connected;
        sockaddr_in_t socket;
        char path[PATHSIZE];
    } client_t;

    typedef struct server_s {
        int fd;
        int port;
        sockaddr_in_t socket;
        char buffer[BUFFERSIZE];
    } server_t ;


#endif /* !ENTITIES_H_ */