/*
** EPITECH PROJECT, 2019
** SERVER // SOURCES // COMMANDS
** File description:
** cmd_path.c
*/

#include "protocol.h"
#include "server.h"

int cmd_help(server_t *server, client_t *client)
{
    printf("HELP\n");
    (void)server;
    (void)client;    
    return (0);
}