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
    char *username = server->buffer + strlen("USER ");

    printf("User name :: %s: ok\nNeed password.\n", username);
    if (dprintf(client->fd, "%s\n", USERNAMEOK) < 0) {
        perror("cmd_noop.c :: Send 220 Replay-code");
        return (84);
    }
    return (0);
}

int cmd_pass(server_t *server, client_t *client)
{
    printf("PASS\n");
    (void)server;
    (void)client;
   return (0);
}