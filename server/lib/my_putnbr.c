/*
** EPITECH PROJECT, 2019
** SERVER // LIB
** File description:
** my_putnbr.c
*/

#include <unistd.h>
#include <stddef.h>

int my_putnbr(int nb)
{
    char c = 0;
    size_t power = 1;

    if (nb < 0) {
        if (write(1, "-", 1) == -1)
            return (84);
        nb = (-1) * nb;
    }
    while ((nb / power) >= 10)
        power = power * 10;
    while (power > 0) {
        c = (nb - (nb % power)) / power + '0';
        if (write(1, &c, 1) == -1)
            return (84);
        nb = nb % power;
        power = power / 10;
    }
    return (0);
}