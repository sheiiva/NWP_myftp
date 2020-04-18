/*
** EPITECH PROJECT, 2019
** SERVER // INCLUDE
** File description:
** execute.h
*/

#ifndef EXECUTE_H_
    #define EXECUTE_H_

    #include <stdio.h>
    #include <string.h>
    #include <unistd.h>

    #include "clients_handler.h"

    typedef struct commands_s {
        char *cmd;
        int (*function)(server_t *, client_t *);
    } commands_t;

    int execute(server_t *server, client_t *clients, int index);
    int show_usage(void);

    int cmd_user(server_t *server, client_t *client);
    int cmd_pass(server_t *server, client_t *client);
    int cmd_cwd(server_t *server, client_t *client);
    int cmd_cdup(server_t *server, client_t *client);
    int cmd_pwd(server_t *server, client_t *client);
    int cmd_pasv(server_t *server, client_t *client);
    int cmd_port(server_t *server, client_t *client);
    int cmd_help(server_t *server, client_t *client);
    int cmd_noop(server_t *server, client_t *client);
    int cmd_retr(server_t *server, client_t *client);
    int cmd_stor(server_t *server, client_t *client);
    int cmd_list(server_t *server, client_t *client);

#endif /* !EXECUTE_H_ */