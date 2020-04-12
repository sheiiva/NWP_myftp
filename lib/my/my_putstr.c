/*
** EPITECH PROJECT, 2018
** LIBRARY
** File description:
** my_putstr.c
*/

#include <unistd.h>
#include "my.h"

size_t my_putstr(char *str, int fd)
{
    if (!str
    || (write(fd, str, my_strlen(str, '\0')) == -1))
        return (84);
    return (0);
}