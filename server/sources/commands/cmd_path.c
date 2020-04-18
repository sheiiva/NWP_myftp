/*
** EPITECH PROJECT, 2019
** SERVER // SOURCES // COMMANDS
** File description:
** cmd_path.c
*/

#include "protocol.h"
#include "server.h"

int cmd_cwd(server_t *server, client_t *client)
{
    printf("CWD\n");
    (void)client;
    (void)server;
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
    printf("%s\n", client->path);
    if (dprintf(client->fd, "%s\n", PATHNAMECREATED) < 0) {
        perror("cmd_help.c :: Send 257 Reply-code");
        return (84);
    }
    return (0);
}