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

int execute(server_t *server, client_t *client, char *path)
{
    int ret = 0;
    int readsize = 0;

    (void)path;
    memset((*server).buffer, 0, BUFFERSIZE);
    readsize = read_input(client->fd, (char *)(*server).buffer);
    if (readsize == -1)
        return (84);
    printf("buffer: %s\n", server->buffer);
    if (strcmp(server->buffer, "QUIT") != 0)
        ret = close_client(client);
    else
        write(1, server->buffer, readsize);
    //read stdin to check server closed
    // ret = 1 if QUIT;
    return (ret);
}