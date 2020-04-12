/*
** EPITECH PROJECT, 2018
** LIBRARY
** File description:
** my_strlen.c
*/

#include <stddef.h>

size_t my_strlen(char const *src, char block)
{
    char const *ptr = src;

    if (!src)
        return (0);
    while ((*ptr != '\0') && (*ptr != block))
        ptr++;
    return (ptr - src);
}
