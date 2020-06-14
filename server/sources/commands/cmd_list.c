/*
** EPITECH PROJECT, 2019
** SERVER // SOURCES // COMMANDS
** File description:
** cmd_list.c
*/

#include <sys/types.h>
#include <dirent.h>
#include "execute.h"

static int lsdir(int sockfd, char *buffer)
{
    DIR *dir = NULL;
    struct dirent *openeddir;

    if (!(dir = opendir("."))) {
        perror("cmd_datatransfer.c :: Open working directory");
        return (84);
    }
    if (write_to(sockfd, OPENDATACONNECT) == 84)
        return (84);
    memset(buffer, 0, BUFFERSIZE);
    while ((openeddir = readdir(dir))) {
        if (openeddir->d_name[0] != '.') {
            strcat(buffer, openeddir->d_name);
            strcat(buffer, " ");
        }
    }
    if (closedir(dir) == -1)
        perror("cmd_list.c :: Close directory");
    strcat(buffer, "\r\n");
    return (write_to(sockfd, buffer));
}

int list(server_t *server, int index)
{
    char buffer[BUFFERSIZE];

    if (server->clients[index].state == DISCONNECTED)
        return (write_to(server->clients[index].sockfd, NOTLOGGEDIN));
    if (!memset(buffer, 0, BUFFERSIZE)) {
        perror("memset");
        return (84);
    }
    if (!getcwd(buffer, BUFFERSIZE))
        return (84);
    if (lsdir(server->clients[index].sockfd, buffer) == 84)
        return (write_to(server->clients[index].sockfd, WRONGARGUMENTS));
    if (write_to(server->clients[index].sockfd, CLOSEDATACONNECT) == 84)
        return (84);
    return (0);
}