/*
** EPITECH PROJECT, 2019
** SERVER // SOURCES // COMMANDS
** File description:
** cmd_path.c
*/

#include "execute.h"

int cmd_cwd(server_t *server, client_t *client)
{
    if (client->connected == false) {
        if (write_to(client->fd, ERROR, "Not logged in.") == 84)
            return (84);
    } else if (checkpath(server->buffer + strlen("CWD ")) == 84) {
        if (write_to(client->fd, ERROR, "No such directory.") == 84)
            return (84);
    } else {
        memset(client->path, 0, PATHSIZE);
        strcpy(client->path, server->buffer + strlen("CWD "));
        if (write_to(client->fd, ACTIONOK,
                    "Requested file action completed.") == 84)
            return (84);
    }
    return (0);
}

int cmd_cdup(server_t *server, client_t *client)
{
    printf("CDUP\n");
    (void)client;
    (void)server;
    return (0);
}

int cmd_pwd(server_t *server, client_t *client)
{
    (void)server;
    if (client->connected) {
        if (write_to(client->fd, PATHNAMECREATED, client->path) == 84)
            return (84);
    } else {
        if (write_to(client->fd, ERROR, "Not logged in.") == 84)
            return (84);
    }
    return (0);
}