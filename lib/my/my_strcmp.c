/*
** EPITECH PROJECT, 2018
** LIBRARY
** File description:
** my_strcmp.c
*/

#include "my.h"

size_t my_strcmp(char *to_compare, char *compared)
{
    size_t i = 0;

    if ((to_compare == NULL || compared == NULL)
        || (my_strlen(to_compare, '\0') != my_strlen(compared, '\0')))
        return (84);
    while (to_compare[i] != '\0') {
        if (to_compare[i] != compared[i])
            return (84);
        i = i + 1;
    }
    return (0);
}