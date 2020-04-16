/*
** EPITECH PROJECT, 2019
** SERVER // SOURCES
** File description:
** create_socket.c
*/

#include <strings.h>
#include "lib.h"
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

static int print_connection(client_t *client)
{
    if (write(client->fd, "Welcom to the server!\n", 23) == -1)
        return (84);
    if (write(1, "CLIENT:\n  .address: ", 21) == -1)
        return (84);
    if (write(1, inet_ntoa(client->socket.sin_addr), 16) == -1)
        return (84);
    if (write(1, "\n  .port: ", 11) == -1)
        return (84);
    if (my_putnbr(client->socket.sin_port) == 84)
        return (84);
    if (write(1, "\n", 1) == -1)
        return (84);
    return (0);
}

int accept_connection(int fd_server, client_t *client)
{
    socklen_t addrlen = (socklen_t)sizeof(sockaddr_in_t);

    client->fd = accept(fd_server, (sockaddr_t *)&client->socket, &addrlen);
    if (client->fd == -1) {
        perror("socket_manager.c:: Accept connection");
        return (84);
    }
    if (print_connection(client) == 84)
        return (84);
    return (0);
}