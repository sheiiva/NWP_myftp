/*
** EPITECH PROJECT, 2019
** SOURCES // ROOT
** File description:
** main.c
*/

#include "sources.h"

#define BUFFERSIZE 100

static int client(char *addr, int port)
{
    int fd = 0;
    char buffer[BUFFERSIZE];
    struct sockaddr_in server;

    if ((fd = create_socket()) == -1)
        return (84);
    if (init_server(addr, &server, port) == 84)
        return (84);
    if (connect_client(fd, &server) == 84)
        return (84);
    memset(buffer, 0, BUFFERSIZE);
    if (read(fd, buffer, BUFFERSIZE) == -1) {
        perror(NULL);
        return (84);
    }
    printf("Server said: %s\n", buffer);
    if (close(fd) == -1) {
        perror(NULL);
        return (84);
    }
    printf("Client closed\n");
    return (0);
}

int main(int ac, char **av)
{
    int port = 0;
    
    if (ac != 3 || ((ac == 3) && (!atoi(av[2])))) {
        fprintf(stderr, "Wrong argument.");
        printf("Please enter a port for your client.");
        return (84);
    }
    port = atoi(av[2]);
    if (!port)
        return (84);
    return client(av[1], port);
}