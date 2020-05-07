/*
** EPITECH PROJECT, 2019
** SERVER // SOURCES // COMMANDS
** File description:
** cmd_noop.c
*/

#include "execute.h"

int cmd_noop(server_t *server, client_t *client)
{
    (void)server;
    if (write_to(client->fd, COMMANDOK) == 84)
        return (84);
    return (0);
}