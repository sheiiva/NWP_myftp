/*
** EPITECH PROJECT, 2019
** SERVER // INCLUDE
** File description:
** arguments_handler.h
*/

#ifndef ARGUMENTS_HANDLER_H_
    #define ARGUMENTS_HANDLER_H_

    #include <dirent.h>
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include <sys/types.h>
    #include <unistd.h>

    #include "macro.h"

    int checkpath(char *path);
    int check_args(int ac, char **av, char *path);

#endif /* !ARGUMENTS_HANDLER_H_ */