/*
** EPITECH PROJECT, 2019
** SERVER // SOURCES
** File description:
** fd_handler.c
*/

#include "server.h"

void initfds(fd_set *readfds, server_t server, client_t *clients, int *fdmax)
{
    int index = 0;

    FD_ZERO(readfds);
    FD_SET(server.fd, readfds);
    *fdmax = server.fd;
    while (index < MAX_CLIENTS) {
        if (clients[index].fd > 0)
            FD_SET(clients[index].fd, readfds);
        if (clients[index].fd > *fdmax)
            *fdmax = clients[index].fd;
        index += 1;
    }
}

int checkfds(server_t *server, client_t *clients, fd_set *readfds)
{
    int index = 0;

    while (index < MAX_CLIENTS) {
        if ((FD_ISSET(clients[index].fd, readfds))
            && (execute(server, clients, index) == 84))
            return (84);
        index += 1;
    }
    return (0);
}