/*
** EPITECH PROJECT, 2019
** SERVER // INCLUDE
** File description:
** socket_handler.h
*/

#ifndef _SOCKET_HANDLER_H_
    #define _SOCKET_HANDLER_H_

    #include <stdio.h>
    #include <string.h>
    #include <unistd.h>

    #include "fd_handler.h"

    int create_socket(void);
    int listen_socket(int sockfd);
    int server_socket(server_t *s, int port);

#endif /* !_SOCKET_HANDLER_H_ */