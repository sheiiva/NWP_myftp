/*
** EPITECH PROJECT, 2018
** LIBRARY
** File description:
** my_str_is_num.c
*/

#include <stdlib.h>
#include "my.h"

int my_isletter(char c)
{
    if (((c >= 'A') && (c <= 'Z')) || ((c >= 'a') && (c <= 'z')))
        return (0);
    return (84);
}

int my_str_isletter(char *str)
{
    if (str == NULL)
        return (84);
    if (my_isletter(str[0]) == 84)
        return (84);
    return (0);
}