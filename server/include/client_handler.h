/*
** EPITECH PROJECT, 2019
** SERVER // INCLUDE
** File description:
** client_handler.h
*/

#ifndef _CLIENT_HANDLER_H_
    #define _CLIENT_HANDLER_H_

    #include "structures.h"
    #include "io_handler.h"
    #include "protocol.h"

    int accept_newclient(server_t *server);
    int select_newclient(server_t *server);

#endif /* !_CLIENT_HANDLER_H_ */