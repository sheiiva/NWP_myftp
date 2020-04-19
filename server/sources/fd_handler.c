/*
** EPITECH PROJECT, 2019
** SERVER // SOURCES
** File description:
** fd_handler.c
*/

#include "fd_handler.h"

int write_to(int fd, char *errorcode, char *comment)
{
    size_t size = strlen(errorcode) + strlen(comment) + 3;
    char *output = malloc(sizeof(char) * size);
    
    if (!output)
        return (84);
    memset(output, 0, size);
    strcpy(output, errorcode);
    if (strlen(comment) != 0) {
        strcat(output, " ");
        strcat(output, comment);
    }
    strcat(output, "\n");
    if (write(fd, output, strlen(output)) < 0) {
        perror(NULL);
        free(output);
        return (84);
    }
    free(output);
    return (0);
}

void initfds(fd_set *readfds, server_t server, client_t *clients, int *fdmax)
{
    int index = 0;

    FD_ZERO(readfds);
    FD_SET(server.fd, readfds);
    *fdmax = server.fd;
    while (index < MAX_CLIENTS) {
        if (clients[index].fd > 0)
            FD_SET(clients[index].fd, readfds);
        if (clients[index].fd > *fdmax)
            *fdmax = clients[index].fd;
        index += 1;
    }
}

int checkfds(server_t *server, client_t *clients, fd_set *readfds)
{
    int index = 0;

    while (index < MAX_CLIENTS) {
        if ((FD_ISSET(clients[index].fd, readfds))
            && (execute(server, clients, index) == 84))
            return (84);
        index += 1;
    }
    return (0);
}