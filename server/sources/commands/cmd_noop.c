/*
** EPITECH PROJECT, 2019
** SERVER // SOURCES // COMMANDS
** File description:
** cmd_noop.c
*/

#include "protocol.h"
#include "server.h"

int cmd_noop(server_t *server, client_t *client)
{
    (void)server;
    if (dprintf(client->fd, READYFORNEWUSER) < 0) {
        perror("cmd_noop.c :: Send 220 Replay-code");
        return (84);
    }
    return (0);
}