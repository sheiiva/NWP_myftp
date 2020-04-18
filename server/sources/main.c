/*
** EPITECH PROJECT, 2019
** SERVER // SOURCES
** File description:
** main.c
*/

#include "arguments_handler.h"
#include "server.h"

int main(int ac, char **av)
{
    char path[PATHSIZE];

    if (ac == 2 && !strcmp(av[1], "-help"))
        return (show_usage());
    else if (check_args(ac, av, path) == 84)
        return (84);
    return (server(atoi(av[1]), path));
}