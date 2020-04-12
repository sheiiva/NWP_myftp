/*
** EPITECH PROJECT, 2019
** INCLUDE FILES
** File description:
** sources.h
*/

#ifndef SOURCE_H_
    #define SOURCE_H_

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
    int connect_client(int fd, struct sockaddr_in *server);
    int init_server(char *addr, struct sockaddr_in *server, int port);

#endif /* !SOURCE_H_ */