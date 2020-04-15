/*
** EPITECH PROJECT, 2019
** SERVER // SOURCES
** File description:
** fd_handler.c
*/

#include "server.h"

void init_fds(fd_set *readfds, server_t server, client_t *clients, int *fdmax)
{
    client_t *client = clients;

    FD_ZERO(readfds);
    FD_SET(server.fd, readfds);
    *fdmax = server.fd;
    while (client) {
        if (client->fd > 0)
            FD_SET(client->fd, readfds);
        if (client->fd > *fdmax)
            *fdmax = client->fd;
        client = client->next;
    }
}

int check_each_fds(client_t *clients, fd_set *readfds)
{
    client_t *client = clients;
    
    while (client) {
        if (FD_ISSET(client->fd, readfds)) {
            printf("execute\n");
        }
        client = client ->next;
    }
    return (0);
}