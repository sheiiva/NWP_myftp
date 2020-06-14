/*
** EPITECH PROJECT, 2019
** SERVER // SOURCES // COMMANDS
** File description:
** cmd_file.c
*/

#include "execute.h"

int dele(server_t *server, int index)
{
    if (server->clients[index].state == DISCONNECTED)
        return (write_to(server->clients[index].sockfd, NOTLOGGEDIN));
    if (remove(server->buffer + strlen("DELE ")) == -1)
        return (write_to(server->clients[index].sockfd, ACTIONNOTTAKEN));
    else
        return (write_to(server->clients[index].sockfd, ACTIONOK));
}