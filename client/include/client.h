/*
** EPITECH PROJECT, 2019
** CLIENT // INCLUDE
** File description:
** client.h
*/

#ifndef SOURCE_H_
    #define SOURCE_H_
    
    #define BUFFERSIZE 100
    #define OPEN    1
    #define CLOSE   0

    #include <arpa/inet.h>
    #include <sys/types.h>
    #include <sys/socket.h>
    #include <stddef.h>
    #include <stdio.h>
    #include <stdlib.h>
    #include <strings.h>
    #include <string.h>
    #include <unistd.h>

    int create_socket(void);
    int client(char *addr, int port);
    int connect_client(int fd, struct sockaddr_in *server);
    int init_server(char *addr, struct sockaddr_in *server, int port);
    int read_stdin(char *buffer);

#endif /* !SOURCE_H_ */