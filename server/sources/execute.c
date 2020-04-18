/*
** EPITECH PROJECT, 2019
** SERVER // SOURCES
** File description:
** execute.c
*/

#include "execute.h"

static commands_t commands[COMMANDSNBR] = {
            {USER,    &cmd_user},
            {PASS,    &cmd_pass},
            {CWD,     &cmd_cwd},
            {CDUP,    &cmd_cdup},
            {PWD,     &cmd_pwd},
            {PASV,    &cmd_pasv},
            {PORT,    &cmd_port},
            {HELPM,   &cmd_help},
            {NOOP,    &cmd_noop},
            {RETR,    &cmd_retr},
            {STOR,    &cmd_stor},
            {LIST,    &cmd_list}
    };

static int read_input(int fd, char *buffer)
{
    int i = 0;
    int readsize = 0;

    memset(buffer, 0, BUFFERSIZE);
    readsize = read(fd, buffer, BUFFERSIZE);
    if (readsize == -1)
        perror("execute.c:: Read from server's fd");
    for (i = 0; i < readsize; i++) {
        if (buffer[i] == '\r' || buffer[i] == '\n')
            buffer[i] = '\0';
    }
    return (readsize);
}

static int command_parser(server_t *server, client_t *client)
{
    int index = 0;

    while (index < COMMANDSNBR) {
        if (!strncmp(server->buffer, commands[index].cmd,
                strlen(commands[index].cmd)))
            return (commands[index].function(server, client));
        index += 1;
    }
    return (0);
}

int execute(server_t *server, client_t *clients, int index)
{
    int readsize = 0;

    memset(server->buffer, 0, BUFFERSIZE);
    readsize = read_input(clients[index].fd, (char *)server->buffer);
    if (readsize == -1)
        return (close_client(clients, index, true));
    else if (!strncmp(server->buffer, QUIT, strlen(QUIT)))
        return (close_client(clients, index, false));
    else
        return (command_parser(server, &clients[index]));
}