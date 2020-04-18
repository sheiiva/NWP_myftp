/*
** EPITECH PROJECT, 2019
** SERVER // SOURCES // COMMANDS
** File description:
** cmd_datatransfer.c
*/

#include "execute.h"

int cmd_retr(server_t *server, client_t *client)
{
    printf("RETR\n");
    (void)server;
    (void)client;
    return (0);
}

int cmd_stor(server_t *server, client_t *client)
{
    printf("STOR\n");
    (void)server;
    (void)client;
    return (0);
}

int cmd_list(server_t *server, client_t *client)
{
    printf("LIST\n");
    (void)server;
    (void)client;
    return (0);
}