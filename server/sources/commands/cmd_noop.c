/*
** EPITECH PROJECT, 2019
** SERVER // SOURCES // COMMANDS
** File description:
** cmd_noop.c
*/

#include "execute.h"

int cmd_noop(server_t *server, client_t *client)
{
    (void)server;
    if (dprintf(client->fd, COMMANDOK) < 0) {
        perror("cmd_noop.c :: Send 200 Replay-code");
        return (84);
    }
    return (0);
}