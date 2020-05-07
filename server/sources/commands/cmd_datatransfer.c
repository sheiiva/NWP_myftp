/*
** EPITECH PROJECT, 2019
** SERVER // SOURCES // COMMANDS
** File description:
** cmd_datatransfer.c
*/

#include "execute.h"

int cmd_retr(server_t *server, client_t *client)
{
    (void)server;
    if (client->connected == false)
        return (write_to(client->fd, NOTLOGGEDIN));
    return (write_to(client->fd, NOTIMPLEMENTED));
}

int cmd_stor(server_t *server, client_t *client)
{
    (void)server;
    if (client->connected == false)
        return (write_to(client->fd, NOTLOGGEDIN));
    return (write_to(client->fd, NOTIMPLEMENTED));
}