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
    if (dprintf(client->fd, "%s\n", USERNAMEOK) < 0) {
        perror("cmd_connect.c :: Send 331 Reply-code");
        return (84);
    }
    return (0);
}

int cmd_pass(server_t *server, client_t *client)
{
    // if (!strcmp(server->buffer, "PASS "))
        // printf("Passwork ok. %s logged in.");

    printf("PASS\n");
    (void)server;
    (void)client;
   return (0);
}