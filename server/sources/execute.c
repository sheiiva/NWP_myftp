/*
** EPITECH PROJECT, 2019
** SERVER // SOURCES
** File description:
** execute.c
*/

#include "execute.h"

static command_t commands[NBCOMMANDS] = {
    {"CWD",     &cwd},
    {"CDUP",    &cdup},
    {"HELP",    &help},
    {"LIST",    &list},
    {"NOOP",    &noop},
    {"PASS",    &pass},
    {"PASV",    &pasv},
    {"PORT",    &port},    
    {"PWD",     &pwd},
    {"USER",    &user},
    {"QUIT",    &quit},
    // {"DELE",    &dele},
};

void remove_extra_spaces(char *str)
{
    size_t i = 0;
    size_t x = 0;

    while (str[i]) {
        if (str[i] != ' ' || (i > 0 && str[i - 1] != ' '))
            str[x++] = str[i];
        i += 1;
    }
    while (x < BUFFERSIZE)
        str[x++] = '\0';
}

void clean_input(char *buffer)
{
    size_t i = 0;

    while (i < BUFFERSIZE) {
        if (buffer[i] == '\r' || buffer[i] == '\n')
            buffer[i] = '\0';
        if (buffer[i] == '\t')
            buffer[i] = ' ';
        i += 1;
    }
    remove_extra_spaces(buffer);
}

int execute(server_t *server, int index)
{
    size_t i = 0;

    while (i < NBCOMMANDS) {
        if (!strncmp(server->buffer, commands[i].cmd, strlen(commands[i].cmd)))
            return (commands[i].function(server, index));
        i += 1;
    }
    if (write_to(server->clients[index].sockfd, WRONGCOMMAND) == 84)
        return (FAILURE);
    return (SUCCESS);
}