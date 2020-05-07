/*
** EPITECH PROJECT, 2019
** SERVER // SOURCES // COMMANDS
** File description:
** cmd_path.c
*/

#include "execute.h"

int cmd_help(server_t *server, client_t *client)
{
    char output[strlen(HELP_MESSAGE) + strlen(COMMAND_H) + 1];

    (void)server;
    strcpy(output, HELP_MESSAGE);
    strcat(output, "\n");
    strcat(output, COMMAND_H);
    if (write_to(client->fd, output) == 84)
        return (84);
    return (0);
}