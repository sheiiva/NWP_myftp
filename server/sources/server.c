/*
** EPITECH PROJECT, 2019
** SERVER // SOURCES
** File description:
** server.c
*/

#include "server.h"

static int close_server(int fd)
{
    if (close(fd) == -1) {
        perror("server.c:: Close socket");
        return (84);
    }
    if (write(1, "Server closed\n", 15) == -1) {
        perror("server.c:: Write closed state");
        return (84);
    }
    return (0);
}

static int loop(server_t server, client_t *clients, char *path)
{
    int fdmax = 0;
    int ret = 0;
    fd_set readfds;

    (void)path; // TO DEL
    while (!ret) {
        init_fds(&readfds, server, clients, &fdmax);
        if (select(fdmax+1 , &readfds , NULL , NULL , NULL) == -1)
            perror("server.c:: Select");
        if (FD_ISSET(server.fd, &readfds)) {
            ret = add_client(clients, server.fd);
            if (!ret)
                printf("execute\n");
            //     ret = execute(&status, server, *clients);
        }
        if (!ret)
            ret = check_each_fds(clients, &readfds);
    }
    if (close_server(server.fd) == 84)
        ret = 84;
    return ((ret == 84) ? 84 : 0);
}

static int init_server(server_t *server, int port)
{
    int opt = OPEN;

    if (setsockopt((*server).fd, SOL_SOCKET, SO_REUSEADDR,
                    (char *)&opt, sizeof(opt)) == -1 ) {
        perror("socket_manager.c:: Set socket options");
        return (84);
    }
    (*server).socket.sin_family = AF_INET;
    (*server).socket.sin_port = htons(port);
    (*server).socket.sin_addr.s_addr = INADDR_ANY;
    bzero(&((*server).socket.sin_zero), 8);
    if (bind((*server).fd, (sockaddr_t*)&(*server).socket,
            sizeof(sockaddr_t)) == -1) {
        perror("socket_manager.c:: Bind server");
        return (84);
    }
    return (0);
}

int server(int port, char *path)
{
    server_t server;
    client_t *client = NULL;

    server.port = port;
    server.fd = create_socket();
    if (server.fd == -1)
        return (84);
    if ((write(1, "Welcome on server!\n", 19) == -1)
    || (init_server(&server, port) == 84)
    || (listen_socket(server.fd, BACKLOG) == 84)) {
        close_server(server.fd);
        return (84);
    }
    return loop(server, client, path);
}