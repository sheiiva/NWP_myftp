/*
** EPITECH PROJECT, 2019
** SERVER // INCLUDE
** File description:
** socket_manager.h
*/

#ifndef SOCKET_MANAGER_H_
    #define SOCKET_MANAGER_H_

    #include <arpa/inet.h>
    #include <netinet/in.h>
    #include <stdio.h>
    #include <sys/types.h>
    #include <sys/socket.h>

    #include "structures.h"
    #include "protocol.h"
    #include "fd_handler.h"

    int accept_connection(int fd_server, client_t *client);
    int create_socket(void);
    int listen_socket(int fd, int backlog);

#endif /* !SOCKET_MANAGER_H_ */