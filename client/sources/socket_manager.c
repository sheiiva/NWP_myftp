/*
** EPITECH PROJECT, 2019
** CLIENT // SOURCES
** File description:
** create_socket.c
*/

#include "client.h"

int create_socket(void)
{
    int sck = socket(AF_INET, SOCK_STREAM, 0);

    if (sck == -1)
        perror("socket_manager.c:: Create socket");
    return (sck);
}

int connect_client(int fd, struct sockaddr_in *server)
{
    if (connect(fd, (sockaddr_t *)server, sizeof(sockaddr_t)) == -1) {
        perror("socket_manager.c:: Connect to server");
        return (84);
    }
    return (0);
}

int init_server(char *addr, struct sockaddr_in *server, int port)
{
    struct in_addr ipaddr;

    if (!inet_aton(addr, &ipaddr))
        return (84);
    (*server).sin_family = AF_INET;
    (*server).sin_port = htons(port);
    (*server).sin_addr = ipaddr;
    bzero(&((*server).sin_zero), 8);
    return (0);
}