/*
** EPITECH PROJECT, 2019
** SERVER // SOURCES
** File description:
** server.c
*/

#include "server.h"

int init_server(server_t *server, int port)
{
    size_t i = 0;

    server->sockfd = create_socket();
    if (server->sockfd == -1)
        return (FAILURE);
    if (server_socket(server, port) == 84)
        return (FAILURE);
    if (listen_socket(server->sockfd) == 84)
        return (FAILURE);
    while (i < FD_SETSIZE) {
        server->clients[i].sockfd = 0;
        server->clients[i].state = DISCONNECTED;
        if (!memset(server->clients[i].name, 0, BUFFERSIZE)
        || !memset(server->clients[i].password, 0, BUFFERSIZE)) {
            return (FAILURE);
        }
        i += 1;
    }
    server->addrlen = sizeof(server->addr);
    return (SUCCESS);
}

int server_system(server_t *server, int index)
{
    int readsize = read_input(server->clients[index].sockfd, server->buffer);

    if (readsize <= 0)
        return (quit(server, index));
    clean_input(server->buffer);
    if (execute(server, index) == 84)
        return (FAILURE);
    FD_CLR(server->clients[index].sockfd, &(server->readfds));
    return (SUCCESS);
}

int server(int port, char *path)
{
    server_t server;

    path = path;
    if (init_server(&server, port) == 84)
        return (FAILURE);
    printf("__ WELCOME ON YOUR SERVER! __\n");
    while (true) {
        initfds(&server);
        if (select_newclient(&server) == 84)
            return (FAILURE);
        if (check_fds(&server) == 84)
            return (FAILURE);
    }
    if (close(server.sockfd) == -1) {
        perror("close");
        return (FAILURE);
    }
    return (SUCCESS);
}