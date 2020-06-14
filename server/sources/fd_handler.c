/*
** EPITECH PROJECT, 2019
** SERVER // SOURCES
** File description:
** fd_handler.c
*/

#include "fd_handler.h"

void initfds(server_t *server)
{
    size_t i = 0;

    FD_ZERO(&(server->readfds));
    FD_SET(server->sockfd, &(server->readfds));
    server->max_sd = server->sockfd;
    while (i < FD_SETSIZE) {
        if (server->clients[i].sockfd > 0)
            FD_SET(server->clients[i].sockfd, &(server->readfds));
        if (server->clients[i].sockfd > server->max_sd)
            server->max_sd = server->clients[i].sockfd;
        i += 1;
    }
}

int check_fds(server_t *server)
{
    size_t i = 0;

    while (i < FD_SETSIZE) {
        if (FD_ISSET(server->clients[i].sockfd, &(server->readfds))
        && (server_system(server, i) == 84))
            return (FAILURE);
        i += 1;
    }
    return (SUCCESS);
}