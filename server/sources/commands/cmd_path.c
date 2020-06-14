/*
** EPITECH PROJECT, 2019
** SERVER // SOURCES // COMMANDS
** File description:
** cmd_path.c
*/

#include "execute.h"
#include "arguments_handler.h"

int cwd(server_t *server, int index)
{
    char path[BUFFERSIZE];

    if (server->clients[index].state == DISCONNECTED)
        return (write_to(server->clients[index].sockfd, NOTLOGGEDIN));
    else if (checkpath((server->buffer + strlen("CWD "))) == 84) {
        write_to(server->clients[index].sockfd, WRONGARGUMENTS);
    } else {
        memset(path, 0, BUFFERSIZE);
        strcpy(path, (server->buffer + strlen("CWD ")));
        if (chdir(path) == -1)
            write_to(server->clients[index].sockfd, WRONGARGUMENTS);
        else
            write_to(server->clients[index].sockfd, ACTIONOK);
    }
    return (0);
}

int cdup(server_t *server, int index)
{
    if (server->clients[index].state == false)
        return (write_to(server->clients[index].sockfd, NOTLOGGEDIN));
    return (write_to(server->clients[index].sockfd, NOTIMPLEMENTED));
}

int pwd(server_t *server, int index)
{
    char path[BUFFERSIZE];
    char output[BUFFERSIZE];

    if (server->clients[index].state == DISCONNECTED)
        return (write_to(server->clients[index].sockfd, NOTLOGGEDIN));
    if (!memset(output, 0, BUFFERSIZE) || !memset(path, 0, BUFFERSIZE))
        return (84);
    if (!getcwd(path, BUFFERSIZE))
        return (84);
    strcpy(output, PATHNAMECREATED);
    strcat(output, path);
    if (write_to(server->clients[index].sockfd, output) == 84)
        return (84);
    return (0);
}