/*
** EPITECH PROJECT, 2018
** LIBRARY
** File description:
** my_str_to_wordarray.c
*/

#include "my.h"

char **my_str_to_wordarray(char *buffer, char **tab, char c)
{
    int i = 0;
    int j = 0;
    int x = 0;
    int size = my_strlen(buffer, '\0');

    while ((tab) && (x < size)) {
        if (buffer[x] == c) {
            tab[j][i] = '\0';
            i = 0;
            j = j + 1;
            x = x + 1;
        }
        if (!tab[j])
            return (NULL);
        tab[j][i++] = buffer[x++];
    }
    return (tab);
}
