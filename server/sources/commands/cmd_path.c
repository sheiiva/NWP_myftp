/*
** EPITECH PROJECT, 2019
** SERVER // SOURCES // COMMANDS
** File description:
** cmd_path.c
*/

#include "execute.h"

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
    if (client->connected) {
        printf("%s\n", client->path);
        if (dprintf(client->fd, "%s\n", PATHNAMECREATED) < 0) {
            perror("cmd_help.c :: Send 257 Reply-code");
            return (84);
        }
    } else {
        printf("Please loggin to access data.\n");
        if (dprintf(client->fd, "%s\n", ERROR) < 0) {
            perror("cmd_help.c :: Send ERROR Reply-code");
            return (84);
        } 
    }
    return (0);
}