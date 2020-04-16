/*
** EPITECH PROJECT, 2019
** SERVER // INCLUDE
** File description:
** server.h
*/

#ifndef SERVER_H_
    #define SERVER_H_

    #define CLOSE       0
    #define OPEN        1
    #define BACKLOG     3
    #define MAX_CLIENTS 1024

    typedef struct sockaddr sockaddr_t;
    typedef struct sockaddr_in sockaddr_in_t;

    #include <sys/time.h>
    #include <sys/types.h>
    #include <sys/socket.h>
    #include <arpa/inet.h>
    #include <netinet/in.h>
    #include <signal.h>
    #include <stdlib.h>
    #include <stdio.h>
    #include <string.h>
    #include <unistd.h>

    #include "entities.h"

    int add_client(client_t *clients, int fdserver);
    int close_client(client_t *clients);
    void free_clients_list(client_t *clients);

    int accept_connection(int fd_server, client_t *client);
    int check_each_fds(client_t *clients, fd_set *readfds);
    int create_socket(void);
    int execute(server_t *server, client_t *client);
    void init_fds(fd_set *readfds, server_t server,
                    client_t *clients, int *fdmax);
    int listen_socket(int fd, int backlog);
    int server(int port, char *path);

#endif /* !SERVER_H_ */