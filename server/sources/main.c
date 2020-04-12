/*
** EPITECH PROJECT, 2019
** SERVER // SOURCES
** File description:
** main.c
*/

#include "server.h"

#define BACKLOG 2

static int server(int port)
{
    int fd_client = 0;
    int fd_server = 0;
    int sin_size = sizeof(struct sockaddr_in);
    struct sockaddr_in server;
    struct sockaddr_in client;
    pid_t child = 0;

    // CREATE A SOCKET
    if ((fd_server = create_socket()) == -1)
        return (84);
    // CONFIGURE THE SOCKET
    bind_socket(&server, fd_server, AF_INET, port, INADDR_ANY);
    // INITIALIZE THE QUEUE
    if (listen_socket(fd_server, BACKLOG) == 84)
        return (84);
    while (1) {
        // WAIT FOR CLIENT CONNECTION
        if ((fd_client = accept_connection(fd_server,(struct sockaddr *)&client, &sin_size)) == 84)
            return (84);
        // CREATE A THREAD
        if ((child = fork()) == -1) {
            perror(NULL);
            return (84);
        } else if (!child) {
            // WRITE TO THE CLIENT
            if (write(fd_client, "Welcom to the server!\n", 23) == -1)
                return (84);
            printf("CLIENT:\n  .address: %s\n  .port: %d\n", inet_ntoa(client.sin_addr), client.sin_port);
            // CLOSE THE CONNECTION
            if (close(fd_client) == -1) {
                perror(NULL);
                return (84);
            }
            break; // NEED TO KILL THE CHILD
        }
    }
    // if (close(fd_server) == -1) {
    //     perror(NULL);
    //     return (84);
    // }
    // printf("Server closed\n");
    return (0);
}

int main(int ac, char **av)
{
    int port = 0;
    
    if (ac != 2 || ((ac == 2) && (!atoi(av[1])))) {
        fprintf(stderr, "Wrong argument.");
        printf("Please enter a port for your server.");
        return (84);
    }
    port = atoi(av[1]);
    if (!port)
        return (84);
    return server(port);
}
