/*
** EPITECH PROJECT, 2019
** CLIENT // SOURCES
** File description:
** reader.c
*/

#include "client.h"

int read_stdin(char *buffer)
{
    int readsize = 0;

    memset(buffer, 0, BUFFERSIZE);
    readsize = read(1, buffer, BUFFERSIZE);
    if (readsize == -1)
        perror("reader.c:: Read from stdin");
    if (readsize <= BUFFERSIZE)
        buffer[readsize - 1] = '\0';
    return (readsize);
}