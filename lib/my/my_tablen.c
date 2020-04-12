/*
** EPITECH PROJECT, 2018
** LIBRARY
** File description:
** my_tablen.c
*/

#include <stddef.h>

size_t my_tablen(char **tab)
{
    size_t i = 0;

    if (tab != NULL) {
        while (tab[i] != NULL)
            i = i + 1;
    }
    return (i);
}