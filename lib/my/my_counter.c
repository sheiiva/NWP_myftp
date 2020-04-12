/*
** EPITECH PROJECT, 2018
** LIBRARY
** File description:
** my_counter.c
*/

#include <stddef.h>

size_t my_counter(char *buffer, char c)
{
    size_t i = 0;

    if (!buffer)
        return (0);
    while (*buffer != '\0') {
        if (*buffer == c)
            i = i + 1;
        buffer = buffer + 1;
    }
    return (i);
}
