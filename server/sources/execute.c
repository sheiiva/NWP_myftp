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
    if (readsize <= BUFFERSIZE)
        buffer[readsize - 1] = '\0';
    return (readsize);
}

static int command_parser(server_t *server, client_t *clients)
{
    int index = 0;

    (void)clients;
    while (index < COMMANDSNBR) {
        if (!strncmp(server->buffer, commands[index].cmd, 4))
            printf("%s\n", commands[index].cmd); // CHANGE .cmd
        index += 1;
    }
    return (0);
}

int execute(server_t *server, client_t *clients, int index)
{
    int ret = 0;
    int readsize = 0;

    memset(server->buffer, 0, BUFFERSIZE);
    readsize = read_input(clients[index].fd, (char *)server->buffer);
    if (readsize == -1 || !strncmp(server->buffer, "QUIT", 4))
        ret = close_client(clients, index);
    else {
        ret = command_parser(server, &clients[index]);
    }
    //read stdin to check server closed
    // ret = 1 if QUIT;
    return (ret);
}