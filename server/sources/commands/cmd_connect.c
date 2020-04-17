/*
** EPITECH PROJECT, 2019
** SERVER // SOURCES // COMMANDS
** File description:
** cmd_connect.c
*/

#include "protocol.h"
#include "server.h"

int cmd_user(server_t *server, client_t *client)
{
    (void)server;

    printf("User name okay, need password.\n");
    if (dprintf(client->fd, "%s\n", USERNAMEOK) < 0) {
        perror("cmd_connect.c :: Send 331 Reply-code");
        return (84);
    }
    return (0);
}

int cmd_pass(server_t *server, client_t *client)
{
    (void)server;
    if (dprintf(client->fd, "%s\n", LOGGEDIN) < 0) {
        perror("cmd_connect.c :: Send 331 Reply-code");
        return (84);
    } else
    printf("User logged in, proceed.\n");
    client->connected = true;
    return (0);
}