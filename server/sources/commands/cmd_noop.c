/*
** EPITECH PROJECT, 2019
** SERVER // SOURCES // COMMANDS
** File description:
** cmd_noop.c
*/

#include "execute.h"

int noop(server_t *server, int index)
{
    if (server->clients[index].state == DISCONNECTED)
        return (write_to(server->clients[index].sockfd, NOTLOGGEDIN));
    if (write_to(server->clients[index].sockfd, COMMANDOK) == 84)
        return (FAILURE);
    return (SUCCESS);
}