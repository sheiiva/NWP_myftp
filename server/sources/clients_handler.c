/*
** EPITECH PROJECT, 2019
** SERVER // SOURCES
** File description:
** server.c
*/

#include "protocol.h"
#include "server.h"

void initclients(client_t *clients)
{
    int index = 0;

    while (index < MAX_CLIENTS) {
        clients[index].fd = 0;
        clients[index].connected = false;
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
        fprintf(stderr, "Cannot connect more clients.\n");
        *last_client = -1;
    } else {
        if (accept_connection(fdserver, &clients[index]) == 84)
            return (84);
        if (dprintf(clients[index].fd, "%s\n", READYFORNEWUSER) < 0)
            return (84);
        *last_client = index;
        strcpy(clients[index].path, path);
    }
    return (0);
}

int close_client(client_t *clients, int index)
{
    printf("Close client from port %d\n", clients[index].socket.sin_port);
    if (dprintf(clients[index].fd, LOGOUT) < 0) {
        perror("clients_handler.c :: Send closing protocol to client");
        return (84);
    }
    if (close(clients[index].fd) == -1) {
        perror("clients_handler.c :: Close client");
        return (84);
    }
    memset(clients[index].path, '\0', PATHSIZE);
    clients[index].fd = 0;
    clients[index].connected = false;
    return (0);
}