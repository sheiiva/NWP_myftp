/*
** EPITECH PROJECT, 2018
** LIBRARY
** File description:
** my_realloc.c
*/

#include <stdlib.h>
#include <stddef.h>
#include "my.h"

char *my_realloc(char *str, char c)
{
    size_t size = my_strlen(str, '\0') + 1;
    char *tmp = my_str_alloc(NULL, size);
    size_t i = 0;

    while ((str != NULL) && (i < size)) {
        tmp[i] = str[i];
        i++;
    }
    if (str == NULL)
        tmp[0] = c;
    else
        tmp[i - 1] = c;
    if (str != NULL)
        free(str);
    return (tmp);
}