/*
** EPITECH PROJECT, 2019
** find_size_y_phrase.c
** File description:
** find_size_y_phrase
*/

#include "103cipher.h"

int find_size_y_phrase(char *phrase, int x)
{
    int size = my_strlen(phrase);
    int element = 1;

    while (x * element < size)
        element++;
    return (element);
}
