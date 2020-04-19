/*
** EPITECH PROJECT, 2019
** SERVER // SOURCES // COMMANDS
** File description:
** cmd_datatransfer.c
*/

#include "execute.h"

int cmd_retr(server_t *server, client_t *client)
{
    printf("RETR\n");
    (void)server;
    (void)client;
    return (0);
}

int cmd_stor(server_t *server, client_t *client)
{
    printf("STOR\n");
    (void)server;
    (void)client;
    return (0);
}

int cmd_list(server_t *server, client_t *client)
{
    // char buffer[PATHSIZE];
    // DIR *dir = NULL;
    // struct dirent *openeddir;

    // if (client->connected == false) {
    //     printf("Please loggin to access data.\n");
    //     if (dprintf(client->fd, "%s\n", ERROR) < 0) {
    //         perror("cmd_help.c :: Send ERROR Reply-code");
    //         return (84);
    //     }   
    // } else {
    //     // memset(buffer, 0, PATHSIZE);
    //     // strcpy(buffer, client->path);
    //     // if (strncmp(server->buffer, LIST, strlen(LIST))) {
    //     //     if (server->buffer[strlen(server->buffer) - 1] != '/')
    //     //         strcat(buffer, "/");
    //     //     strcat(buffer, server->buffer);
    //     // }
    //     // if (!(dir = opendir(buffer))) {
    //     //     perror("cmd_datatransfer.c :: Open working directory");
    //     //     return (84);
    //     // }
    //     // memset(buffer, 0, PATHSIZE);
    //     // while ((openeddir = readdir(dir))) {
    //     //     if (openeddir->d_name[0] != '.') {
    //     //         strcat(buffer, openeddir->d_name);
    //     //         strcat(buffer, " ");
    //     //     }
    //     // }
    //     // printf("%s\n", buffer);
    //     // if (dprintf(client->fd, "%s\n", CLOSEDATACONNECT) < 0) {
    //     //     perror("cmd_datatransfer.c :: Send 26 Reply-code");
    //     //     return (84);
    //     // }
    //     if (closedir (dir) == -1)
    //         return (84);
    // }
    (void)client;
    (void)server;
    return (0);
}