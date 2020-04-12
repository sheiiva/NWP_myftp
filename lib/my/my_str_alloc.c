/*
** EPITECH PROJECT, 2018
** LIBRARY
** File description:
** my_alloc.c
*/

#include <stdlib.h>
#include <stddef.h>

char *my_strset(char *str, int n, char c)
{
    int i = 0;

    if (str == NULL || n <= 0)
        return (NULL);
    while (i < n) {
        str[i] = c;
        i = i + 1;
    }
    return (str);
}

char *my_str_alloc(char *str, int size)
{
    char *tmp = NULL;
    int i = 0;

    if ((tmp = malloc(sizeof(char) * (size + 1))) == NULL)
        return (NULL);
    tmp = my_strset(tmp, (size + 1), '\0');
    if (str != NULL) {
        while ((str[i] != '\0') && (i < size)) {
            tmp[i] = str[i];
            i = i + 1;
        }
    }
    return (tmp);
}