/*
** EPITECH PROJECT, 2019
** SERVER // SOURCES // COMMANDS
** File description:
** cmd_mode.c
*/

#include "execute.h"

int pasv(server_t *server, int index)
{
    if (server->clients[index].state == DISCONNECTED)
        return (write_to(server->clients[index].sockfd, NOTLOGGEDIN));
    return (write_to(server->clients[index].sockfd, PASSIVEMODE));
}

int port(server_t *server, int index)
{
    if (server->clients[index].state == DISCONNECTED)
        return (write_to(server->clients[index].sockfd, NOTLOGGEDIN));
    return (write_to(server->clients[index].sockfd, COMMANDOK));
}