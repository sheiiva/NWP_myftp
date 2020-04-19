/*
** EPITECH PROJECT, 2019
** SERVER // INCLUDE
** File description:
** clients_handler.h
*/

#ifndef CLIENTS_HANDLER_H_
    #define CLIENTS_HANDLER_H_

    #include <stdio.h>
    #include <string.h>
    #include <unistd.h>

    #include "socket_manager.h"
    #include "fd_handler.h"

    int add_client(client_t *clients, int fdserver, char *path);
    int close_client(client_t *clients, int index, bool interrupt);
    void initclients(client_t *clients, char *path);

#endif /* !CLIENTS_HANDLER_H_ */