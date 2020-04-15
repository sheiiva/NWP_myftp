/*
** EPITECH PROJECT, 2019
** SERVER // SOURCES
** File description:
** main.c
*/

#include "server.h"
#include "entities.h"

int main(int ac, char **av)
{
    char path[PATHSIZE];

    if (ac != 3) {
        write(2, "Wrong arguments number.\n", 25);
        return (84);
    }
    if (!atoi(av[1])) {
        write(2, "Wrong argument.\n", 17);
        write(1, "Please enter a valid port for your server.\n", 38);
        return (84);
    }
    if (getcwd(path, PATHSIZE) == NULL) {
        perror("main.c :: getcwd");
        return (84);
    }
    return server(atoi(av[1]), strcat(path, av[2]));
}
