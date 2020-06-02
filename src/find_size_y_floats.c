/*
** EPITECH PROJECT, 2019
** find_size_y_floats.c
** File description:
** find_size_y_floats
*/

#include "103cipher.h"

int find_size_y_floats(char *phrase, int x)
{
    int element = 1;
    int space_count = 1;

    for (int i = 0; phrase[i] != 0; i++)
        if (phrase[i] == 32)
            space_count++;
    while (x * element < space_count)
        element++;
    return (element);
}
