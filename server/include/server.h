/*
** EPITECH PROJECT, 2019
** SERVER // INCLUDE
** File description:
** server.h
*/

#ifndef SERVER_H_
    #define SERVER_H_

    #include <arpa/inet.h>
    #include <stdio.h>
    #include <strings.h>
    #include <sys/types.h>
    #include <sys/select.h>
    #include <sys/socket.h>
    #include <sys/time.h>
    #include <unistd.h>

    #include "clients_handler.h"
    #include "structures.h"
    #include "fd_handler.h"
    #include "macro.h"
    #include "socket_manager.h"

    int server(int port, char *path);

#endif /* !SERVER_H_ */