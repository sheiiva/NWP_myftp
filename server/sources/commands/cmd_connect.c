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
    if (!strcmp(server->buffer + strlen("USER "), "Anonymous")) {
        if (dprintf(client->fd, "%s\n", USERNAMEOK) < 0) {
            perror("cmd_connect.c :: Send 331 Reply-code");
            return (84);
        }
    } else {
        if (dprintf(client->fd, "%s\n", ERROR) < 0) {
            perror("cmd_connect.c :: Send ERROR Reply-code");
            return (84);
        }
    }
    return (0);
}

int cmd_pass(server_t *server, client_t *client)
{
    (void)server;
    if (!strcmp(server->buffer, "PASS ")) {
        if (dprintf(client->fd, "%s\n", LOGGEDIN) < 0) {
            perror("cmd_connect.c :: Send 331 Reply-code");
            return (84);
        } else
        client->connected = true;
    } else {
        if (dprintf(client->fd, "%s\n", ERROR) < 0) {
            perror("cmd_connect.c :: Send ERROR Reply-code");
            return (84);
        }
    }
    return (0);
}