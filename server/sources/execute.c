/*
** EPITECH PROJECT, 2019
** SERVER // SOURCES
** File description:
** execute.c
*/

#include "server.h"

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

int execute(server_t *server, client_t *clients, int index)
{
    int ret = 0;
    int readsize = 0;

    memset(server->buffer, 0, BUFFERSIZE);
    readsize = read_input(clients[index].fd, (char *)server->buffer);
    if (readsize == -1 || !strncmp(server->buffer, "QUIT", 4))
        ret = close_client(clients, index);
    else {
        write(1, server->buffer, readsize);
        write(1, "\n", 1);
    }
    //read stdin to check server closed
    // ret = 1 if QUIT;
    return (ret);
}