/*
** EPITECH PROJECT, 2019
** SERVER // SOURCES
** File description:
** server.c
*/

#include "server.h"
#include "lib.h"

void initclients(client_t *clients)
{
    int index = 0;

    while (index < MAX_CLIENTS) {
        clients[index].fd = 0;
        memset(clients[index].path, 0, PATHSIZE);
        index += 1;
    }
}

int add_client(client_t *clients, int fdserver, char *path, int *last_client)
{
    int index = 0;

    while ((index < MAX_CLIENTS) && (clients[index].fd > 0))
        index += 1;
    if (index == MAX_CLIENTS) {
        if (write(2, "Cannot connect more clients.\n", 30) == -1)
            return (84);
        *last_client = -1;
    } else {
        if (accept_connection(fdserver, &clients[index]) == 84)
            return (84);
        *last_client = index;
        strcpy(clients[index].path, path);
    }
    return (0);
}

int close_client(client_t *clients, int index)
{
    if ((write(1, "Close client from port ", 24) == -1)
    || (my_putnbr(clients[index].socket.sin_port) == 84)
    || (write(1, "\n", 1) == -1))
        return (84);
    if (close(clients[index].fd) == -1) {
        perror("clients_handler.c :: Close client");
        return (84);
    }
    memset(clients[index].path, '\0', PATHSIZE);
    clients[index].fd = 0;
    return (0);
}