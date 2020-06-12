/*
** EPITECH PROJECT, 2019
** SERVER // SOURCES
** File description:
** arguments_hanlder.c
*/

#include "arguments_handler.h"

int isnum(char *arg)
{
    if (!atoi(arg)) {
        if ((write(2, "Wrong argument.\n", 17) < 0)
        || (write(2, "Please enter a valid port for your server.\n", 44) < 0))
            perror(NULL);
        return (0);
    }
    return (1);
}

int checkpath(char *path)
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

int getpath(char *argv, char *path)
{
    if (!memset(path, 0, BUFFERSIZE)) {
        perror("main.c :: memset");
        return (84);
    }
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

int check_args(int ac, char **av, char *path)
{
    if (ac != 3) {
        if (write(2, "Wrong arguments number.\n", 25) < 0)
            perror(NULL);
        return (84);
    }
    if (!isnum(av[1]))
        return (84);
    if ((getpath(av[2], path) == 84) || (checkpath(path) == 84))
        return (84);
    return (0);
}