/*
** EPITECH PROJECT, 2019
** SERVER // SOURCES
** File description:
** execute.c
*/

#include <errno.h>
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

int read_input(int fd, char *buffer)
{
    int i = 0;
    int readsize = 0;

    memset(buffer, 0, BUFFERSIZE);
    readsize = read(fd, buffer, BUFFERSIZE);
    if (readsize <= 0)
        perror("execute.c:: Read from server's fd");
    else if (readsize == 1) {
        if (write_to(fd, WRONGCOMMAND) == 84)
            return (84);
    } else {
        for (i = 0; i < readsize; i++) {
            if ((buffer[i] == '\r') || (buffer[i] == '\n'))
                buffer[i] = '\0';
            // CAREFULL EXTRA SPACES
        }
    }
    return (readsize);
}

int command_parser(server_t *server, client_t *client)
{
    int ret = 0;
    int index = 0;

    if (server->buffer[0] == 0)
        return (0);
    while (index < COMMANDSNBR) {
        if (!strncmp(server->buffer, commands[index].cmd,
                strlen(commands[index].cmd))) {
            ret = commands[index].function(server, client);
            memset(server->buffer, 0, BUFFERSIZE);
            return (ret);
        }
        index += 1;
    }
    if (write_to(client->fd, WRONGCOMMAND) == 84)
        return (84);
    return (0);
}

int execute(server_t *server, client_t *clients, int index)
{
    int readsize = 0;

    memset(server->buffer, 0, BUFFERSIZE);
    readsize = read_input(clients[index].fd, (char *)server->buffer);
    if (readsize <= 0)
        return (close_client(clients, index, true));
    else if (!strncmp(server->buffer, QUIT, strlen(QUIT)))
        return (close_client(clients, index, false));
    else
        return (command_parser(server, &clients[index]));
}