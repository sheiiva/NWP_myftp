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
        fprintf(stderr, "Wrong argument.");
        printf("Please enter the server's port.");
        return (84);
    }
    return client(av[1], atoi(av[2]));
}