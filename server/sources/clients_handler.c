/*
** EPITECH PROJECT, 2019
** SERVER // SOURCES
** File description:
** server.c
*/

#include "server.h"

static void link_nodes(client_t *clients, client_t *new)
{
    if (!clients) {
        clients = new;
        clients->next = NULL;
        clients->prev = NULL;
    } else {
        clients->prev = new;
        new->next = clients;
        new->prev = NULL;
    }
}

int add_client(client_t *clients, int fdserver)
{
    client_t *new = malloc(sizeof(client_t));

    if (!new) {
        perror("server.c:: Malloc new client");
        return (84);
    }
    if (accept_connection(fdserver, *new) == 84) {
        free(new);
        return (84);
    }
    link_nodes(clients, new);
    return (0);
}

int close_client(client_t *clients)
{
    if (clients->next)
        clients->next->prev = clients->prev;
    if (clients->prev)
        clients->prev->next = clients->next;
    if (close(clients->fd) == -1) {
        perror("clients_handler.c :: Close client");
        return (84);
    }
    free(clients);
    return (0);
}

void free_clients_list(client_t *clients)
{
    client_t *tmp = clients;

    while (tmp && tmp->next) {
        tmp = tmp->next;
        free(tmp->prev);
    }
    if (tmp)
        free(tmp);
}