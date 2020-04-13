/*
** EPITECH PROJECT, 2019
** CLIENT // SOURCES
** File description:
** main.c
*/

#include "client.h"

int main(int ac, char **av)
{
    if (ac != 3 || ((ac == 3) && (!atoi(av[2])))) {
        write(2, "Wrong argument.", 16);
        write(1, "Please enter the server's port.", 32);
        return (84);
    }
    return client(av[1], atoi(av[2]));
}