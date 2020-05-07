/*
** EPITECH PROJECT, 2019
** SERVER // SOURCES // COMMANDS
** File description:
** cmd_list.c
*/

#include "execute.h"

static void getpath(server_t *server, client_t *client, char *path)
{
    char *ptrpath = server->buffer + strlen(LIST) + 1;

    memset(path, 0, PATHSIZE);
    if (!strcmp(server->buffer, LIST))
        strcpy(path, "./");
    else if (ptrpath[0] == '/' || ptrpath[0] == '~')
        strcpy(path, ptrpath);
    else {
        strcpy(path, client->path);
        if (client->path[strlen(client->path) - 1] != '/')
            strcat(path, "/");
        strcat(path, ptrpath);
    }
}

int lsdir(client_t *client, char *path)
{
    DIR *dir = NULL;
    struct dirent *openeddir;

    if (!(dir = opendir(path))) {
        perror("cmd_datatransfer.c :: Open working directory");
        return (84);
    }
    if (write_to(client->fd, OPENDATACONNECT) == 84)
        return (84);
    memset(path, 0, PATHSIZE);
    while ((openeddir = readdir(dir))) {
        if (openeddir->d_name[0] != '.') {
            strcat(path, openeddir->d_name);
            strcat(path, " ");
        }
    }
    if (closedir(dir) == -1)
        perror("cmd_list.c :: Close directory");
    return (write_to(client->fd, path));
}

int cmd_list(server_t *server, client_t *client)
{
    char buffer[strlen(CLOSEDATACONNECT) + PATHSIZE + 1];

    if (client->connected == false)
        return (write_to(client->fd, NOTLOGGEDIN));
    getpath(server, client, buffer);
    if (lsdir(client, buffer) == 84)
        return (write_to(client->fd, WRONGARGUMENTS));
    if (write_to(client->fd, CLOSEDATACONNECT) == 84)
        return (84);
    return (0);
}