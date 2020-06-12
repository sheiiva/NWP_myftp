/*
** EPITECH PROJECT, 2019
** SERVER // SOURCES // COMMANDS
** File description:
** cmd_path.c
*/

#include "execute.h"

int cmd_cwd(server_t *server, client_t *client)
{
    if (client->connected == false)
        return (write_to(client->fd, NOTLOGGEDIN));
    else if (checkpath((server->buffer + strlen("CWD "))) == 84) {
        write_to(client->fd, WRONGARGUMENTS);
    } else {
        memset(client->path, 0, BUFFERSIZE);
        strcpy(client->path, (server->buffer + strlen("CWD ")));
        write_to(client->fd, ACTIONOK);
    }
    return (0);
}

int cmd_cdup(server_t *server, client_t *client)
{
    printf("CDUP\n");
    (void)server;
    if (client->connected == false)
        return (write_to(client->fd, NOTLOGGEDIN));
    return (write_to(client->fd, NOTIMPLEMENTED));
}

int cmd_pwd(server_t *server, client_t *client)
{
    size_t pathlen = strlen(PATHNAMECREATED) + strlen(client->path) + 1;
    char *output = NULL;

    (void)server;
    if (client->connected == false)
        return (write_to(client->fd, NOTLOGGEDIN));
    output = malloc(sizeof(char) * pathlen);
    if (!output || !memset(output, 0, pathlen))
        return (84);
    strcpy(output, PATHNAMECREATED);
    strcat(output, client->path);
    write_to(client->fd, output);
    free(output);
    return (0);
}