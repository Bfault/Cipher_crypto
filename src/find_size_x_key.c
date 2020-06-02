/*
** EPITECH PROJECT, 2019
** find_size_x_key.c
** File description:
** find_size_x_key
*/

#include "103cipher.h"

int find_size_x_key(char *key)
{
    int size = my_strlen(key);
    int pow = 1;

    while (my_compute_power_rec(pow, 2) < size)
        pow++;
    return (pow);
}
