/*
** EPITECH PROJECT, 2019
** SERVER // SOURCES // COMMANDS
** File description:
** cmd_path.c
*/

#include "execute.h"

int help(server_t *server, int index)
{
    char output[strlen(HELP_MESSAGE) + strlen(COMMAND_H) + 1];

    strcpy(output, HELP_MESSAGE);
    strcat(output, "\n");
    strcat(output, COMMAND_H);
    if (write_to(server->clients[index].sockfd, output) == 84)
        return (84);
    return (0);
}