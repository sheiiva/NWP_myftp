/*
** EPITECH PROJECT, 2019
** SERVER // SOURCES
** File description:
** main.c
*/

#include "arguments_handler.h"
#include "server.h"
#include "macro.h"

int main(int ac, char **av)
{
    char path[BUFFERSIZE];

    if (ac == 2 && !strcmp(av[1], "-help"))
        return (write(1, USAGE, strlen(USAGE)) == -1 ? FAILURE : SUCCESS);
    else if (check_args(ac, av, path) == FAILURE)
        return (FAILURE);
    return (server(atoi(av[1]), path));
}