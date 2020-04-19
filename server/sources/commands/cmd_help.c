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
    if (dprintf(client->fd, "%s %s\n%s\n",
                HELP_MESSAGE, USAGE, COMMAND_H) < 0) {
        perror("cmd_help.c :: Send HELP Reply-code");
        return (84);
    }
    return (0);
}