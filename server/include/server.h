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
    #define COMMANDSNBR 12
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

    int show_usage(void);

    int add_client(client_t *clients, int fdserver,
                    char *path, int *last_client);
    int close_client(client_t *clients, int index, bool interrupt);
    void initclients(client_t *clients, char *path);

    void initfds(fd_set *readfds, server_t server,
                    client_t *clients, int *fdmax);
    int checkfds(server_t *server, client_t *clients, fd_set *readfds);

    int accept_connection(int fd_server, client_t *client);
    int create_socket(void);
    int listen_socket(int fd, int backlog);

    int execute(server_t *server, client_t *clients, int index);

    int server(int port, char *path);

    typedef struct commands_s {
        char *cmd;
        int (*function)(server_t *, client_t *);
    } commands_t;

    int cmd_user(server_t *server, client_t *client);
    int cmd_pass(server_t *server, client_t *client);
    int cmd_cwd(server_t *server, client_t *client);
    int cmd_cdup(server_t *server, client_t *client);
    int cmd_pwd(server_t *server, client_t *client);
    int cmd_pasv(server_t *server, client_t *client);
    int cmd_port(server_t *server, client_t *client);
    int cmd_help(server_t *server, client_t *client);
    int cmd_noop(server_t *server, client_t *client);
    int cmd_retr(server_t *server, client_t *client);
    int cmd_stor(server_t *server, client_t *client);
    int cmd_list(server_t *server, client_t *client);

#endif /* !SERVER_H_ */