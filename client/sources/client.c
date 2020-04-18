/*
** EPITECH PROJECT, 2019
** CLIENT // SOURCES
** File description:
** client.c
*/

#include "client.h"

static int close_client(int fd)
{
    if (close(fd) == -1) {
        perror("client.c:: Close socket");
        return (84);
    }
    if (write(1, "Client closed\n", 15) == -1) {
        perror("client.c:: Write closed state");
        return (84);
    }
    return (0);
}

static int readfd(int fd, char *buffer, int *state)
{
    int readsize = 0;

    memset(buffer, 0, BUFFERSIZE);
    readsize = read(fd, buffer, BUFFERSIZE);
    if (readsize == -1)
        perror("reader.c:: Read from client's fd");
    if (readsize <= BUFFERSIZE) {
        buffer[readsize - 1] = '\0';
        printf("received: %s\n", buffer);
    }
    if (!strcmp(buffer, "221"))
        *state = CLOSE;
    return (readsize);
}

static int loop(int fd)
{
    int state = OPEN;
    int ret = 0;
    int readsize = 0;
    char buffer[BUFFERSIZE];

    while (state == OPEN && !ret) {
        if (readfd(fd, buffer, & state) == -1)
            return (84);
        else if (state && write(1, ">> ", 4) == -1) {
            ret = 84;
        } else if (state && (readsize = read_stdin((char *)buffer)) == -1) {
            ret = 84;
        } else if (state && (write(fd, buffer, readsize) == -1)) {
            perror("client.c:: Write to Server");
            ret = 84;
        }
    }
    if (close_client(fd) == 84)
        ret = 84;
    return (ret);
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
    return loop(fd);
}