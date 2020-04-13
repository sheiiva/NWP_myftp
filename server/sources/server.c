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

static int loop(int fd_server, struct sockaddr_in server)
{
    int fd_client = 0;
    int sin_size = sizeof(struct sockaddr_in);
    struct sockaddr_in client;
    pid_t child = 0;

    (void)server;
    while (1) {
        // WAIT FOR CLIENT CONNECTION
        fd_client = accept_connection(fd_server, (sockaddr_t *)&client, &sin_size);
        if (fd_client == -1)
            return (84);
        // CREATE A THREAD
        if ((child = fork()) == -1) {
            perror(NULL);
            return (84);
        } else if (!child) {
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
        }
    }
    if (close(fd_server) == -1) {
        perror(NULL);
        return (84);
    }
    printf("Server closed\n");
    return (0);

}

static int init_server(int fd_server, struct sockaddr_in *server, int port)
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
    struct sockaddr_in server;

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