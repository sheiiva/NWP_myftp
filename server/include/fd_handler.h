/*
** EPITECH PROJECT, 2019
** SERVER // INCLUDE
** File description:
** clients_handler.h
*/

#ifndef FD_HANDLER_H_
    #define FD_HANDLER_H_

    #include <sys/select.h>
    #include <sys/time.h>
    #include <sys/types.h>
    #include <unistd.h>

    #include "execute.h"

    int checkfds(server_t *server, client_t *clients, fd_set *readfds);
    void initfds(fd_set *readfds, server_t server,
                    client_t *clients, int *fdmax);
    int write_to(int fd, char *errorcode, char *comment);

#endif /* !FD_HANDLER_H_ */