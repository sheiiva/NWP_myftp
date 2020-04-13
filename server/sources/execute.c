/*
** EPITECH PROJECT, 2019
** SERVER // SOURCES
** File description:
** execute.c
*/

#include "server.h"

int execute(int fd_client, int fd_server, struct sockaddr_in client, struct sockaddr_in server)
{
    (void)server;
    (void)fd_server;
    // WRITE TO THE CLIENT
    if (write(fd_client, "Welcom to the server!\n", 23) == -1)
        return (84);
    printf("CLIENT:\n  .address: %s\n  .port: %d\n", inet_ntoa(client.sin_addr), client.sin_port);
    // CLOSE THE CONNECTION
    if (close(fd_client) == -1) {
        perror(NULL);
        return (84);
    }
    // break; // NEED TO KILL THE CHILD
    return (0);
}