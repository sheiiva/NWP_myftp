/*
** EPITECH PROJECT, 2019
** SERVER // INCLUDE
** File description:
** entities.h
*/

#ifndef ENTITIES_H_
    #define ENTITIES_H_

    #define PATHSIZE    256

    typedef struct client_s
    {
        int fd;
        sockaddr_in_t socket;
        char path[PATHSIZE];
        struct client_s *next;
        struct client_s *prev;
    } client_t;

    typedef struct server_s
    {
        int fd;
        int port;
        sockaddr_in_t socket;
    } server_t ;
    
    
#endif /* !ENTITIES_H_ */