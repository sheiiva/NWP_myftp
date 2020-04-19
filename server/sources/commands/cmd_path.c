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
        if (dprintf(client->fd, "%s Not logged in.\n", ERROR) < 0) {
            perror("cmd_help.c :: Send ERROR Reply-code");
            return (84);
        }
    } else if (checkpath(server->buffer + strlen("CWD ")) == 84) {
        if (dprintf(client->fd, "%s No such directory.\n", ERROR) < 0) {
            perror("cmd_path.c :: Send ERROR Reply-code");
            return (84);
        }
    } else {
        memset(client->path, 0, PATHSIZE);
        strcpy(client->path, server->buffer + strlen("CWD "));
        if (dprintf(client->fd,
                "%s Requested file action completed.\n", ACTIONOK) < 0) {
            perror("cmd_help.c :: Send 257 Reply-code");
            return (84);
        }
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
        if (dprintf(client->fd, "%s %s\n",
                    PATHNAMECREATED, client->path) < 0) {
            perror("cmd_help.c :: Send 257 Reply-code");
            return (84);
        }
    } else {
        if (dprintf(client->fd, "%s Not logged in.\n", ERROR) < 0) {
            perror("cmd_help.c :: Send ERROR Reply-code");
            return (84);
        }
    }
    return (0);
}