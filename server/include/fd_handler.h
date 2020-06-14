/*
** EPITECH PROJECT, 2019
** SERVER // INCLUDE
** File description:
** fd_handler.h
*/

#ifndef _FD_HANDLER_H_
    #define _FD_HANDLER_H_

    #include "structures.h"
    #include "server.h"

    int check_fds(server_t *server);
    void initfds(server_t *server);

#endif /* !_FD_HANDLER_H_ */