/*
** EPITECH PROJECT, 2019
** SERVER // SOURCES
** File description:
** client_handler.c
*/

#include "client_handler.h"

int accept_newclient(server_t *server)
{
    socklen_t addrlen = sizeof(server->addr);

    server->new_sockfd = accept(server->sockfd,
        (struct sockaddr *)&(server->addr), &addrlen);
    if (server->new_sockfd == -1) {
        perror("accept");
        return (FAILURE);
    }
    if (write_to(server->new_sockfd, READYFORNEWUSER) == 84)
        return (FAILURE);
    if (printf("CLIENT:\n  .address: %s\n  .port: %d\n",
            inet_ntoa(server->addr.sin_addr),
            server->addr.sin_port) < 0)
        return (FAILURE);
    return (SUCCESS);
}

int select_newclient(server_t *server)
{
    size_t i = 0;

    if (select(server->max_sd + 1, &server->readfds, NULL, NULL, NULL) < 0) {
        perror("select");
        return (FAILURE);
    }
    if (FD_ISSET(server->sockfd, &server->readfds)) {
        if (accept_newclient(server) == 84)
            return (FAILURE);
        while (i < FD_SETSIZE) {
            if (server->clients[i].sockfd <= 0) {
                server->clients[i].sockfd = server->new_sockfd;
                break;
            }
            i += 1;
        }
    }
    return (SUCCESS);
}
