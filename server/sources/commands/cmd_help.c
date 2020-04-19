/*
** EPITECH PROJECT, 2019
** SERVER // SOURCES // COMMANDS
** File description:
** cmd_path.c
*/

#include "execute.h"

static int show_command(client_t *client)
{
    if (dprintf(client->fd,
        "USER <SP> <username> <CRLF>   : Specify user for authentication\n"
        "PASS <SP> <password> <CRLF>   : Specify password to login\n\n"
        "CWD  <SP> <pathname> <CRLF>   : Change working directory\n"
        "CDUP <CRLF>                   : CWD to parent directory\n\n"
        "QUIT <CRLF>                   : Disconnection\n\n"
        "DELE <SP> <pathname> <CRLF>   : Delete file on the server\n\n"
        "PWD  <CRLF>                   : Print working directory\n\n"
        "PASV <CRLF>                   : 'passive' mode for data transfer\n"
        "PORT <SP> <host-port> <CRLF>  : 'active' mode for data transfer\n"
        "HELP [<SP> <string>] <CRLF>   : List available commands\n\n"
        "NOOP <CRLF>                   : Do nothing\n\n"
        "(the following are commands using data transfer )\n"
        "RETR <SP> <pathname> <CRLF>   : Download file from server\n"
        "STOR <SP> <pathname> <CRLF>   : Upload file from client to server\n"
        "LIST [<SP> <pathname>] <CRLF> : Files in the current directory\n\n")
        < 0)
        return (84);
    return (0);
}

int show_usage(client_t *client)
{
    int fd = 1;

    if (client)
        fd = client->fd;
    if (dprintf(fd, "USAGE: ./myftp port path\n"
        "\tport\tis the port number on which the server socket listens\n"
        "\tpath\tis the path to the home directory for the Anonymous user\n"
        ) < 0)
        return (84);
    return (0);
}

int cmd_help(server_t *server, client_t *client)
{
    (void)server;
    if (dprintf(client->fd, "%s\n", HELP_MESSAGE) < 0) {
        perror("cmd_help.c :: Send HELP Reply-code");
        return (84);
    if (show_usage(client) == 84 || dprintf(client->fd, "\n") < 0
            || show_command(client) == 84)
        return (84);
    }
    return (0);
}