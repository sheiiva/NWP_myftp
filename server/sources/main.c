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

    if (ac == 2 && !strcmp(av[1], "-help"))
        return (show_usage());
    else if (ac != 3) {
        fprintf(stderr, "Wrong arguments number.\n");
        return (84);
    } else {
        if (!atoi(av[1])) {
            fprintf(stderr, "Wrong argument.\n");
            printf("Please enter a valid port for your server.\n");
            return (84);
        }
        if (getcwd(path, PATHSIZE) == NULL) {
            perror("main.c :: getcwd");
            return (84);
        }
        return server(atoi(av[1]), strcat(path, av[2]));
    }
}