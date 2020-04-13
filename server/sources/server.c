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

static int loop(int fd_server, sockaddr_in_t server)
{
    int ret = 0;
    int fd_client = 0;
    sockaddr_in_t client;
    pid_t child = 0;

    while (1) {
        fd_client = accept_connection(fd_server, (sockaddr_t *)&client);
        if (fd_client == -1)
            ret = 84;
        else if ((child = fork()) == -1) {
            perror("server.c:: Fork");
            ret = 84;
        } else if (!child) {
            if (execute(fd_client, fd_server, client, server) == 84)
                ret = 84;
        }
    }
    if (close_server(fd_server) == 84)
        ret = 84;
    return (ret);
}

static int init_server(int fd_server, sockaddr_in_t *server, int port)
{
    (*server).sin_family = AF_INET;
    (*server).sin_port = htons(port);
    (*server).sin_addr.s_addr = INADDR_ANY;
    bzero(&((*server).sin_zero), 8);
    if (bind(fd_server, (sockaddr_t*)server, sizeof(sockaddr_t)) == -1) {
        perror("socket_manager.c:: Bind server");
        return (84);
    }
    return (0);
}

int server(int port)
{
    int fd_server = create_socket();
    sockaddr_in_t server;

    if (fd_server == -1)
        return (84);
    if (init_server(fd_server, &server, port) == 84) {
        close_server(fd_server);
        return (84);
    }
    if (listen_socket(fd_server, BACKLOG) == 84) {
        close_server(fd_server);
        return (84);
    }
    return loop(fd_server, server);
}