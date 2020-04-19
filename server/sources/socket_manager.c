/*
** EPITECH PROJECT, 2019
** SERVER // SOURCES
** File description:
** socket_manager.c
*/

#include "socket_manager.h"

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

int accept_connection(int fd_server, client_t *client)
{
    socklen_t addrlen = (socklen_t)sizeof(sockaddr_in_t);

    client->fd = accept(fd_server, (sockaddr_t *)&client->socket, &addrlen);
    if (client->fd == -1) {
        perror("socket_manager.c:: Accept connection");
        return (84);
    }
    if (write_to(client->fd, READYFORNEWUSER,
                "Connection Established") == 84)
        return (84);
    if (printf("CLIENT:\n  .address: %s\n  .port: %d\n",
                inet_ntoa(client->socket.sin_addr),
                client->socket.sin_port) < 0)
        return (84);
    return (0);
}