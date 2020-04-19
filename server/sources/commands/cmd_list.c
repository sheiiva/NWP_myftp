/*
** EPITECH PROJECT, 2019
** SERVER // SOURCES // COMMANDS
** File description:
** cmd_list.c
*/

#include "execute.h"

static void getPath(server_t *server, client_t *client, char *path)
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

static int lsdir(char *path)
{
    DIR *dir = NULL;
    struct dirent *openeddir;

    if (!(dir = opendir(path))) {
        perror("cmd_datatransfer.c :: Open working directory");
        return (84);
    }
    memset(path, 0, PATHSIZE);
    while ((openeddir = readdir(dir))) {
        if (openeddir->d_name[0] != '.') {
            strcat(path, openeddir->d_name);
            strcat(path, " ");
        }
    }
    if (closedir(dir) == -1)
        perror("cmd_list.c :: Close directory");
    return (0);
}

int cmd_list(server_t *server, client_t *client)
{
    char buffer[PATHSIZE];

    if (client->connected == false) {
        if (dprintf(client->fd, "%s Not Logged in.\n", ERROR) < 0) {
            perror("cmd_help.c :: Send ERROR Reply-code");
            return (84);
        }
        return (0);
    }
    getPath(server, client, buffer);
    if (lsdir(buffer) == 84) {
        if (dprintf(client->fd, "%s Wrong path.\n", ERROR) < 0) {
            perror("cmd_help.c :: Send ERROR Reply-code");
            return (84);
        }
    } else if (dprintf(client->fd, "%s %s\n", CLOSEDATACONNECT, buffer) < 0) {
        perror("cmd_datatransfer.c :: Send 26 Reply-code");
        return (84);
    }
    return (0);
}