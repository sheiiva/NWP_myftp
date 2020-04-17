/*
** EPITECH PROJECT, 2019
** SERVER // SOURCES
** File description:
** execute.c
*/

#include "server.h"
#include "protocol.h"

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
    int readsize = 0;

    memset(buffer, 0, BUFFERSIZE);
    readsize = read(fd, buffer, BUFFERSIZE);
    if (readsize == -1)
        perror("reader.c:: Read from server's fd");
    if (buffer[readsize - 1] == '\n')
        buffer[readsize - 1] = '\0';
    return (readsize);
}

static int command_parser(server_t *server, client_t *client)
{
    int index = 0;

    while (index < COMMANDSNBR) {
        if (!strncmp(server->buffer, commands[index].cmd, 4))
            return (commands[index].function(server, client)); 
        index += 1;
    }
    if (dprintf(client->fd, ERROR) < 0) {
        perror("execute.c :: Send ERROR Replay-code");
        return (84);
    }
    return (0);
}

int execute(server_t *server, client_t *clients, int index)
{
    int readsize = 0;

    memset(server->buffer, 0, BUFFERSIZE);
    readsize = read_input(clients[index].fd, (char *)server->buffer);
    if (readsize == -1 || !strncmp(server->buffer, "QUIT", 4))
        return (close_client(clients, index));
    return (command_parser(server, &clients[index]));
}