/*
** EPITECH PROJECT, 2019
** SERVER // SOURCES
** File description:
** arguments_hanlder.c
*/

#include "arguments_handler.h"

static int isnum(char *arg)
{
    if (!atoi(arg)) {
        fprintf(stderr, "Wrong argument.\n");
        printf("Please enter a valid port for your server.\n");
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

int check_args(int ac, char **av, char *path)
{
    if (ac != 3) {
        fprintf(stderr, "Wrong arguments number.\n");
        return (84);
    }
    if (!isnum(av[1]))
        return (84);
    if ((getpath(av[2], path) == 84) || (checkpath(path) == 84))
        return (84); 
    return (0);
}