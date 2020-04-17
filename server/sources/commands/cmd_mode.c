/*
** EPITECH PROJECT, 2019
** SERVER // SOURCES // COMMANDS
** File description:
** cmd_mode.c
*/

#include "protocol.h"
#include "server.h"

int cmd_pasv(server_t *server, client_t *client)
{
    printf("PASV\n");
    (void)server;
    (void)client;
    return (0);
}

int cmd_port(server_t *server, client_t *client)
{
    printf("PORT\n");
    (void)server;
    (void)client;
    return (0);
}