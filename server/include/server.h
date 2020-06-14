/*
** EPITECH PROJECT, 2019
** SERVER // INCLUDE
** File description:
** server.h
*/

#ifndef SERVER_H_
    #define SERVER_H_

    #include "structures.h"
    #include "fd_handler.h"
    #include "io_handler.h"
    #include "socket_handler.h"
    #include "client_handler.h"
    #include "execute.h"

    int server_system(server_t *server, int index);
    int init_server(server_t *server, int port);
    int server(int port, char *path);

#endif /* !SERVER_H_ */