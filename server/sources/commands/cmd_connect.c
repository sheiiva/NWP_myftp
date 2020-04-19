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
        if (write_to(client->fd, USERNAMEOK,
                    "User name okay, need password.") == 84)
            return (84);
    } else {
        if (write_to(client->fd, ERROR, "Wrong username") == 84)
            return (84);
    }
    return (0);
}

int cmd_pass(server_t *server, client_t *client)
{
    (void)server;
    if (!strcmp(server->buffer, "PASS ")) {
        if (write_to(client->fd, LOGGEDIN,
                    "User logged in, proceed.") == 84)
            return (84);
        client->connected = true;
    } else {
        if (write_to(client->fd, ERROR, "Wrong password.") == 84)
            return (84);
    }
    return (0);
}