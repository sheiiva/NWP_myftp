/*
** EPITECH PROJECT, 2019
** SERVER // INCLUDE
** File description:
** server.h
*/

#ifndef SERVER_H_
    #define SERVER_H_

    #define BACKLOG 2

    typedef struct sockaddr sockaddr_t;
    typedef struct sockaddr_in sockaddr_in_t;

    #include <sys/types.h>
    #include <sys/socket.h>
    #include <arpa/inet.h>
    #include <netinet/in.h>
    #include <signal.h>
    #include <stdlib.h>
    #include <stdio.h>
    #include <string.h>
    #include <unistd.h>

    int accept_connection(int fd_server, struct sockaddr *addr);
    int create_socket(void);
    int execute(int fd_client, int fd_server,
                struct sockaddr_in client,
                struct sockaddr_in server);
    int listen_socket(int fd, int backlog);
    int server(int port);

#endif /* !SERVER_H_ */