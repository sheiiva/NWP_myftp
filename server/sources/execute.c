/*
** EPITECH PROJECT, 2019
** SERVER // SOURCES
** File description:
** execute.c
*/

#include "server.h"

static int read_input(server_t server, char *buffer)
{
    int readsize = 0;

    memset(buffer, 0, BUFFERSIZE);
    readsize = read(server.fd, buffer, BUFFERSIZE);
    if (readsize == -1)
        perror("reader.c:: Read from server's fd");
    if (readsize <= BUFFERSIZE)
        buffer[readsize - 1] = '\0';
    return (readsize);
}

int execute(int *status, server_t server, client_t client)
{
    int readsize = 0;
    char buffer[BUFFERSIZE];

    memset(buffer, 0, BUFFERSIZE);
    while (strcmp(buffer, "QUIT") != 0) {
        if ((readsize = read_input(server, (char *)buffer)) == -1)
            return (84);
        printf("buffer: %s\n", buffer);
        write(1, buffer, readsize);
    }
    if (close(client.fd) == -1) {
        perror(NULL);
        return (84);
    }
    *status = CLOSE;
    return (0);
}