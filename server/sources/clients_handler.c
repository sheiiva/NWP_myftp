/*
** EPITECH PROJECT, 2019
** SERVER // SOURCES
** File description:
** clients_handler.c
*/

#include "clients_handler.h"

void initclients(client_t *clients, char *path)
{
    size_t index = 0;

    while (index < FD_SETSIZE) {
        clients[index].fd = 0;
        clients[index].connected = false;
        if (!memset(clients[index].path, 0, BUFFERSIZE)
        || !strcpy(clients[index].path, path)
        || !memset(clients[index].name, 0, BUFFERSIZE)) {
            perror("clients_handler.c :: initclients");
            return;
        }
        index += 1;
    }
}

int add_client(client_t *clients, int fdserver, char *path)
{
    int index = 0;

    while ((index < FD_SETSIZE) && (clients[index].fd > 0))
        index += 1;
    if (index == FD_SETSIZE) {
        if (write_to(clients[index].fd, INSUFSTORAGE) == -1)
            return (84);
    } else {
        if (accept_connection(fdserver, &clients[index]) == 84)
            return (84);
        if (!memset(clients[index].path, 0, BUFFERSIZE)
        || !strcpy(clients[index].path, path)) {
            perror("clients_handler.c :: add_client");
            return (84);
        }
    }
    return (0);
}

int close_client(client_t *clients, int index, bool interrupt)
{
    printf("Close client from port %d\n", clients[index].socket.sin_port);
    if (interrupt == false) {
        if (write_to(clients[index].fd, LOGOUT) < 0)
            return (84);
    }
    if (close(clients[index].fd) == -1)
        perror("clients_handler.c :: Close client");
    memset(clients[index].path, 0, BUFFERSIZE);
    memset(clients[index].name, 0, BUFFERSIZE);
    clients[index].fd = 0;
    clients[index].connected = false;
    return (0);
}