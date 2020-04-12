/*
** EPITECH PROJECT, 2018
** LIBRARY
** File description:
** my_strncmp.c
*/

#include <stddef.h>
#include "my.h"

int my_strncmp(char *to_compare, char *compared, size_t n)
{
    size_t i = 0;

    if (to_compare == NULL || compared == NULL || n <= 0)
        return (84);
    while ((to_compare[i] != '\0')  && (compared[i] != '\0') && (i < n)) {
        if (to_compare[i] != compared[i])
            return (84);
        i = i + 1;
    }
    if (((to_compare[i] == '\0') || compared[i] == '\0') && (i != n))
            return (84);
    return (0);
}