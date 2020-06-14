/*
** EPITECH PROJECT, 2019
** SERVER // SOURCES
** File description:
** io_handler.c
*/

#include "io_handler.h"

int write_to(int fd, char *message)
{
    if (write(fd, message, strlen(message)) == -1) {
        perror("write to");
        return (FAILURE);
    }
    return (SUCCESS);
}

int read_input(int fd, char *buffer)
{
    int readsize = 0;

    if (!memset(buffer, 0, BUFFERSIZE)) {
        perror("memset");
        return (-1);
    }
    readsize = read(fd, buffer, BUFFERSIZE);
    if (readsize == -1)
        perror("read");
    return (readsize);
}
