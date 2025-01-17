/*
** EPITECH PROJECT, 2019
** SERVER // INCLUDE
** File description:
** execute.h
*/

#ifndef _EXECUTE_H_
    #define _EXECUTE_H_

    #include <string.h>
    #include "protocol.h"
    #include "structures.h"
    #include "io_handler.h"

    #define NBCOMMANDS 12

    typedef struct command_s {
        char *cmd;
        int (*function)(server_t *, int);
    } command_t;

    void remove_extra_spaces(char *str);
    void clean_input(char *buffer);
    int execute(server_t *server, int index);

    int cdup(server_t *server, int index);
    int cwd(server_t *server, int index);
    int dele(server_t *server, int index);
    int help(server_t *server, int index);
    int list(server_t *server, int index);
    int noop(server_t *server, int index);
    int user(server_t *server, int index);
    int pass(server_t *server, int index);
    int pasv(server_t *server, int index);
    int port(server_t *server, int index);
    int pwd(server_t *server, int index);
    int quit(server_t *server, int index);

#endif /* !_EXECUTE_H_ */