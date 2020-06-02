/*
** EPITECH PROJECT, 2019
** cipher.c
** File description:
** cipher.c
*/

#include "103cipher.h"

int cipher(char **av)
{
    if (av[3][0] == '0' && my_strlen(av[3]) == 1)
        return (encrypt(av[1], av[2]));
    if (av[3][0] == '1' && my_strlen(av[3]) == 1)
        return (decrypt(av[1], av[2]));
    return (error("Please try with 0 or 1 at the flag position.\n", 46));
}
