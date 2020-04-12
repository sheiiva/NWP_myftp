/*
** EPITECH PROJECT, 2018
** LIBRARY
** File description:
** my_tab_alloc.c
*/

#include <unistd.h>
#include <stdlib.h>

char **my_tab_alloc(int size)
{
    char **tmp = NULL;
    int j = 0;

    if ((tmp = malloc(sizeof(char *) * (size + 1))) == NULL)
        return (NULL);
    while (j < size)
        tmp[j++] = NULL;
    tmp[j] = NULL;
    return (tmp);
}