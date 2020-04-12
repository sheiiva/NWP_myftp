/*
** EPITECH PROJECT, 2018
** LIBRARY
** File description:
** my_tabcpy.c
*/

#include <stdlib.h>
#include <stddef.h>
#include "my.h"

char **my_tabcpy(char **to, char **from)
{
    int j = 0;
    int size = my_tablen(from);

    to = my_tab_alloc(size);
    while (j < size) {
        to[j] = my_strcpy(from[j], to[j]);
        j = j + 1;
    }
    return (to);
}