/*
** EPITECH PROJECT, 2019
** INCLUDE FILES
** File description:
** sources.h
*/

#ifndef SOURCE_H_
    #define SOURCE_H_

    #include <arpa/inet.h>
    #include <netinet/in.h>
    #include <sys/select.h>
    #include <sys/socket.h>
    #include <sys/time.h>
    #include <sys/types.h>
    #include <signal.h>
    #include <stdlib.h>
    #include <stdio.h>
    #include <unistd.h>

    int accept_connection(int fd_server, struct sockaddr *addr, int *addrlen);
    int listen_socket(int fd, int backlog);
    int create_socket(void);
    void bind_socket(struct sockaddr_in *struc, int fd,
                        sa_family_t family, in_port_t port, in_addr_t addr);

#endif /* !SOURCE_H_ */