/*
** EPITECH PROJECT, 2019
** 103cipher_2019
** File description:
** error.c
*/

#include <unistd.h>
#include "103cipher.h"

int error(char *str, int len)
{
    write(2, "\e[1;31m", 7);
    write(2, str, len);
    write(2, "\e[0m", 4);
    return (84);
}