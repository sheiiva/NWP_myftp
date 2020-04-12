/*
** EPITECH PROJECT, 2019
** SERVER // SOURCES
** File description:
** create_socket.c
*/

#include <strings.h>
#include "server.h"

int create_socket(void)
{
    int sck = socket(AF_INET, SOCK_STREAM, 0);

    if (sck == -1)
        perror(NULL);
    return sck;
}

void bind_socket(struct sockaddr_in *struc, int fd, sa_family_t family, in_port_t port, in_addr_t addr)
{
    (*struc).sin_family = family;
    (*struc).sin_port = htons(port);
    (*struc).sin_addr.s_addr = addr;
    bzero(&((*struc).sin_zero),8);
    if(bind(fd ,(struct sockaddr*)struc, sizeof(struct sockaddr)) == -1) {
        perror(NULL);
        exit(84);
    }
}

int listen_socket(int fd, int backlog)
{
    if (listen(fd, backlog) == -1) {
        perror(NULL);
        return (84);
    }
    return (0);
}

int accept_connection(int fd_server, struct sockaddr *addr, int *addrlen)
{
    int fd_client = 0;

    if ((fd_client = accept(fd_server, addr, (socklen_t *)addrlen)) == -1) {
        perror(NULL);
        return (84);
    }
    return (fd_client);
}