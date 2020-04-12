/*
** EPITECH PROJECT, 2018
** LIBRARY
** File description:
** my_getnbr.c
*/

int my_isnum(char c)
{
    if (('0' <= c) && (c <= '9'))
        return (0);
    return (-1);
}

int my_getnbr(char *str)
{
    int i = 0;
    int nb = 0;
    int neg = 1;

    if (!str)
        return (0);
    while (str[i] == '-') {
        neg = neg * (-1);
        i = i + 1;
    }
    if (str[i] == '\0')
        return (0);
    while (str[i] != '\0') {
        if (my_isnum(str[i]) == -1)
            return (0);
        nb = (nb * 10) + (str[i] - '0');
        i = i + 1;
    }
    nb = nb * neg;
    return (nb);
}