/*
** EPITECH PROJECT, 2018
** LIBRARY
** File description:
** my_freetab.c
*/

#include <stdlib.h>
#include <stddef.h>

void my_freetab(char **tofree)
{
    size_t j = 0;

    if (tofree != NULL) {
        while (tofree[j] != NULL)
            free(tofree[j++]);
        free(tofree[j]);
        free(tofree);
    }
}
