/*
** EPITECH PROJECT, 2019
** SERVER // SOURCES
** File description:
** main.c
*/

#include "server.h"
#include "entities.h"

static int getpath(char *argv, char *path)
{
    memset(path, 0, PATHSIZE);
    if (getcwd(path, BUFFERSIZE) == NULL) {
        perror("main.c :: getcwd");
        return (84);
    }
    if (strcmp(argv, ".") && strcmp(argv, "./")) {
        strcat(path, "/");
        strcat(path, argv);
    }
    return (0);
}

static int checkpath(char *path)
{
    DIR *dir = opendir(path);
    
    if (!dir) {
        perror(path);
        return (84);
    }
    if (closedir(dir) == -1) {
        perror("main.c :: close directory");
        return (84);           
    }
    return (0);
}

int main(int ac, char **av)
{
    char path[PATHSIZE];

    if (ac == 2 && !strcmp(av[1], "-help"))
        return (show_usage());
    else if (ac != 3) {
        fprintf(stderr, "Wrong arguments number.\n");
        return (84);
    }
    if (!atoi(av[1])) {
        fprintf(stderr, "Wrong argument.\n");
        printf("Please enter a valid port for your server.\n");
        return (84);
    }
    if ((getpath(av[2], path) == 84) || (checkpath(path) == 84))
        return (84);
    return (server(atoi(av[1]), path));
}