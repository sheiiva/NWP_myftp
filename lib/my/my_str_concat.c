/*
** EPITECH PROJECT, 2018
** LIBRARY
** File description:
** my_str_concat.c
*/

#include <stddef.h>
#include "my.h"

char *my_str_concat(char *first, char *second)
{
    size_t i = 0;
    size_t x = 0;
    char *new = NULL;
    size_t size = my_strlen(first, '\0') + my_strlen(second, '\0');

    if ((first == NULL) && (second == NULL))
        return (NULL);
    new = my_str_alloc(NULL, size);
    while (x < my_strlen(first, '\0'))
        new[i++] = first[x++];
    x = 0;
    while (x < my_strlen(second, '\0'))
        new[i++] = second[x++];
    return (new);
}