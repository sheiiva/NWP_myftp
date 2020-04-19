/*
** EPITECH PROJECT, 2019
** SERVER // SOURCES // COMMANDS
** File description:
** cmd_path.c
*/

#include "execute.h"

int cmd_help(server_t *server, client_t *client)
{
    (void)server;
    if (write_to(client->fd, HELP_MESSAGE, COMMAND_H) == 84)
        return (84);
    return (0);
}