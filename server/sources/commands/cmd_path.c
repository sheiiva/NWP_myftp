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
    printf("PWD\n");
    (void)client;
    (void)server;
    return (0);
}