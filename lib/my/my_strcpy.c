/*
** EPITECH PROJECT, 2018
** LIBRARY
** File description:
** my_strcpy.c
*/

#include <stddef.h>
#include "my.h"

char *my_strcpy(char *from, char *to)
{
    int i = 0;
    int size = my_strlen(from, '\0');

    if (from == NULL)
        return (NULL);
    to = my_str_alloc(NULL, size);
    while (i < size) {
        to[i] = from[i];
        i = i + 1;
    }
    return (to);
}