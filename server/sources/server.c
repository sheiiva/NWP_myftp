/*
** EPITECH PROJECT, 2019
** SERVER // SOURCES
** File description:
** server.c
*/

#include "server.h"

int init_server(server_t *server, int port)
{
    server->socket.sin_family = AF_INET;
    server->socket.sin_port = htons(port);
    server->socket.sin_addr.s_addr = INADDR_ANY;
    bzero(&(server->socket.sin_zero), 8);
    if (bind(server->fd, (sockaddr_t *)&server->socket,
            sizeof(server->socket)) == -1) {
        perror("socket_manager.c:: Bind server");
        return (84);
    }
    return (0);
}

int close_server(int fd)
{
    if (close(fd) == -1) {
        perror("server.c:: Close socket");
        return (84);
    }
    if (write(1, "Server closed\n", 15) == 84)
        return (84);
    return (0);
}

int loop(server_t server, client_t *clients, char *path)
{
    int fdmax = 0;
    int ret = 0;
    fd_set readfds;

    while (!ret) {
        initfds(&readfds, server, clients, &fdmax);
        if (select((fdmax + 1), &readfds , NULL , NULL , NULL) == -1) {
            perror("server.c:: Select");
            ret = 84;
        } else {
            if (FD_ISSET(server.fd, &readfds))
                ret = add_client(clients, server.fd, path);
            ret = checkfds(&server, clients, &readfds);
        }
    }
    if (close_server(server.fd) == 84)
        ret = 84;
    return (ret);
}

int server(int port, char *path)
{
    server_t server;
    client_t clients[FD_SETSIZE];

    server.port = port;
    server.fd = create_socket();
    if (server.fd == -1)
        return (84);
    if ((write(1, "Welcome on server!\n", 20) == -1)
    || (init_server(&server, port) == 84)
    || (listen_socket(server.fd) == 84)) {
        close_server(server.fd);
        return (84);
    }
    initclients(clients, path);
    return loop(server, (client_t *)clients, path);
}