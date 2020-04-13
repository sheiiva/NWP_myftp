/*
** EPITECH PROJECT, 2019
** SERVER // SOURCES
** File description:
** create_socket.c
*/

#include <strings.h>
#include "server.h"

int create_socket(void)
{
    int sck = socket(AF_INET, SOCK_STREAM, 0);

    if (sck == -1)
        perror("socket_manager.c:: Create socket");
    return (sck);
}

int listen_socket(int fd, int backlog)
{
    if (listen(fd, backlog) == -1) {
        perror("socket_manager.c:: Listen");
        return (84);
    }
    return (0);
}

int accept_connection(int fd_server, struct sockaddr *addr, int *addrlen)
{
    int fd_client = 0;

    if ((fd_client = accept(fd_server, addr, (socklen_t *)addrlen)) == -1) {
        perror("socket_manager.c:: Accept connection");
        return (-1);
    }
    return (fd_client);
}