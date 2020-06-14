/*
** EPITECH PROJECT, 2019
** SERVER // SOURCES // COMMANDS
** File description:
** cmd_log.c
*/

#include "execute.h"

int user(server_t *server, int index)
{
    size_t cmdlen = strlen("USER ");

    if (write_to(server->clients[index].sockfd, USERNAMEOK) == 84)
        return (FAILURE);
    if ((!memset(server->clients[index].name, 0, BUFFERSIZE))
    || (!strcpy(server->clients[index].name, server->buffer + cmdlen))) {
        perror("setting name");
        return (FAILURE);
    }
    return (SUCCESS);
}

int pass(server_t *server, int index)
{
    if (!strcmp(server->clients[index].name, "Anonymous")) {
        if (write_to(server->clients[index].sockfd, LOGGEDIN) == 84)
            return (FAILURE);
        server->clients[index].state = CONNECTED;
    } else {
        if (write_to(server->clients[index].sockfd, NOTLOGGEDIN) == 84)
            return (FAILURE);
    }
    return (SUCCESS);
}

int quit(server_t *server, int index)
{
    if (printf("CLIENT DISCONNECTED:\n  .address: %s\n  .port: %d\n",
            inet_ntoa(server->addr.sin_addr),
            server->addr.sin_port) < 0)
        return (FAILURE);
    if (write_to(server->clients[index].sockfd, LOGOUT) == 84)
        return (FAILURE);
    if (close(server->clients[index].sockfd) == -1) {
        perror("close");
        return (FAILURE);
    }
    server->clients[index].sockfd = 0;
    server->clients[index].state = DISCONNECTED;
    if (!memset(server->clients[index].name, 0, BUFFERSIZE)
    || !memset(server->clients[index].password, 0, BUFFERSIZE)) {
        perror("memset");
        return (FAILURE);
    }
    return (SUCCESS);
}