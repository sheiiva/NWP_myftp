/*
** EPITECH PROJECT, 2019
** SERVER // SOURCES
** File description:
** main.c
*/

#include "server.h"

int main(int ac, char **av)
{
    if (ac != 2 || ((ac == 2) && (!atoi(av[1])))) {
        write(2, "Wrong argument.\n", 17);
        write(1, "Please enter a port for your server.\n", 38);
        return (84);
    }
    return server(atoi(av[1]));
}
