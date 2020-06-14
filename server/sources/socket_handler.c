/*
** EPITECH PROJECT, 2019
** SERVER // SOURCES
** File description:
** socket_handler.c
*/

#include "socket_handler.h"

int create_socket(void)
{
    int newsock = socket(AF_INET, SOCK_STREAM, 0);

    if (newsock == -1)
        perror("socket");
    return (newsock);
}

int listen_socket(int sockfd)
{
    if (listen(sockfd, BACKLOG) == -1) {
        perror("listen");
        return (FAILURE);
    }
    return (SUCCESS);
}

int server_socket(server_t *s, int port)
{
    s->addr.sin_family = AF_INET;
    s->addr.sin_addr.s_addr = htonl(INADDR_ANY);
    s->addr.sin_port = htons(port);
    if (bind(s->sockfd, (struct sockaddr *)&s->addr, sizeof(s->addr)) < 0) {
        perror("bind");
        return (FAILURE);
    }
    return (SUCCESS);
}
