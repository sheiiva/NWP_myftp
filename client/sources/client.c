/*
** EPITECH PROJECT, 2019
** CLIENT // SOURCES
** File description:
** client.c
*/

#include "client.h"

int readfd(int fd, char *buffer, int *state)
{
    int readsize = 0;

    memset(buffer, 0, BUFFERSIZE);
    readsize = read(fd, buffer, BUFFERSIZE);
    if (readsize == -1)
        perror("reader.c:: Read from client's fd");
    if (readsize <= BUFFERSIZE) {
        buffer[readsize - 1] = '\0';
        printf("<< %s\n", buffer);
    }
    if (!strncmp(buffer, "221", 3))
        *state = CLOSE;
    return (readsize);
}

int loop(int fd)
{
    int state = OPEN;
    int readsize = 0;
    char buffer[BUFFERSIZE];

    if (readfd(fd, buffer, &state) == -1)
        return (84);
    while (state == OPEN) {
        if (write(1, ">> ", 4) == -1)
            return (84);
        readsize = read_stdin((char *)buffer);
        if (readsize == -1)
            return (84);
        if (write(fd, buffer, readsize) == -1) {
            perror("client.c:: Write to Server");
            return (84);
        }
        if (readfd(fd, buffer, &state) == -1)
            return (84);
    }
    return (0);
}

int client(char *addr, int port)
{
    int fd = create_socket();
    struct sockaddr_in server;

    if (fd == -1)
        return (84);
    if (init_server(addr, &server, port) == 84)
        return (84);
    if (connect_client(fd, &server) == 84)
        return (84);
    return (loop(fd));
}