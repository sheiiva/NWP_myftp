/*
** EPITECH PROJECT, 2019
** SERVER // SOURCES // COMMANDS
** File description:
** cmd_mode.c
*/

#include "execute.h"

int cmd_pasv(server_t *server, client_t *client)
{
    (void)server;
    if (client->connected == false)
        return (write_to(client->fd, NOTLOGGEDIN));
    return (write_to(client->fd, NOTIMPLEMENTED));
}

int cmd_port(server_t *server, client_t *client)
{
    (void)server;
    if (client->connected == false)
        return (write_to(client->fd, NOTLOGGEDIN));
    return (write_to(client->fd, NOTIMPLEMENTED));
}