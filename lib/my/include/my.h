/*
** EPITECH PROJECT, 2019
** LIB // MY // INCLUDE
** File description:
** my.h
*/

#ifndef MY_H
    #define MY_H

    #include <stddef.h>

    #ifndef PRINT_H
        #define PRINT_H

        size_t my_putchar(char c, int fd);
        size_t my_putstr(char *str, int fd);

    #endif /* !PRINT_H */

    #ifndef TAB_H
        #define TAB_H

        void my_freetab(char **tofree);
        char **my_tab_alloc(int size);
        char **my_tabcpy(char **to, char **from);
        int my_tablen(char **tab);

    #endif /* !COUNTER_H */

    #ifndef STRING_H
        #define STRING_H

        size_t my_counter(char *buffer, char c);
        char *my_realloc(char *str, char c);
        char *my_revstr(char *str);
        char *my_str_alloc(char *str, int size);
        size_t my_strcmp(char *to_compare, char *compared);
        int my_str_isletter(char *str);
        int my_strncmp(char *to_compare, char *compared, size_t n);
        char *my_str_concat(char *first, char *second);
        char *my_strcpy(char *from, char *to);
        size_t my_strlen(char const *src, char block);
        char *my_strset(char *str, int n, char c);
        char **my_str_to_wordarray(char *buffer, char **tab, char c);

    #endif /* !COUNTER_H */

    int my_getnbr(char *str);
    int my_isletter(char c);
    int my_isnum(char c);

#endif /* !MY_H */