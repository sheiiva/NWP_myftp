/*
** EPITECH PROJECT, 2019
** SERVER // INCLUDE
** File description:
** io_handler.h
*/

#ifndef _IO_HANDLER_H_
    #define _IO_HANDLER_H_

    #include <unistd.h>
    #include <stdio.h>
    #include <errno.h>
    #include <string.h>
    #include "macro.h"

    int read_input(int fd, char *buffer);
    int write_to(int fd, char *message);

#endif /* !_IO_HANDLER_H_ */