/*
** EPITECH PROJECT, 2018
** LIBRARY
** File description:
** my_putchar.c
*/

#include <unistd.h>

size_t my_putchar(char c, int fd)
{
    if (write(fd, &c, 1) == -1)
        return (84);
    return (0);
}
