/*
** EPITECH PROJECT, 2019
** SERVER // SOURCES // COMMANDS
** File description:
** cmd_connect.c
*/

#include "protocol.h"
#include "server.h"

int cmd_user(server_t *server, client_t *client)
{
    printf("USER\n");
    (void)server;
    (void)client;
    return (0);
}

int cmd_pass(server_t *server, client_t *client)
{
    printf("PASS\n");
    (void)server;
    (void)client;
   return (0);
}