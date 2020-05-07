/*
** EPITECH PROJECT, 2019
** SERVER // SOURCES // COMMANDS
** File description:
** cmd_connect.c
*/

#include "execute.h"

int cmd_user(server_t *server, client_t *client)
{
    (void)server;
    if (strlen(server->buffer) <= strlen(USER) + 1) {
        if (write_to(client->fd, WRONGARGUMENTS) == 84)
            return (84);
    } else {
        strcpy(client->name, server->buffer + strlen(USER) + 1);
        if (write_to(client->fd, USERNAMEOK) == 84)
            return (84);
        if (printf("client's username: %s\n\t(at port %d)\n",
                    client->name, client->socket.sin_port) < 0)
            return (84);
    }
    return (0);
}

int cmd_pass(server_t *server, client_t *client)
{
    (void)server;
    if (strcmp(client->name, "Anonymous") != 0) {
        if (write_to(client->fd, NOTLOGGEDIN) == 84)
            return (84);
    } else {
        if (write_to(client->fd, LOGGEDIN) == 84)
            return (84);
        client->connected = true;
    }
    return (0);
}