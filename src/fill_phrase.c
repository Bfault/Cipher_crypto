/*
** EPITECH PROJECT, 2019
** fill_phrase.c
** File description:
** fill phrase
*/

#include <stdlib.h>
#include "103cipher.h"

int len_space(char *str)
{
    int i = 0;
    int count = 0;

    while (str[i] == 32)
        i++;
    while (str[i] != 32) {
        count++;
        i++;
    }
    return (count);
}

void fill_phrase(cipher_t *cipher, char *phrase)
{
    int final_size = my_strlen(phrase);
    int chunk = 0;
    int x = 0;
    int y = 0;

    for (int i = 0; i < final_size; i++) {
        chunk = len_space(phrase);
        cipher->phrase[y][x] = (float)atoi(phrase);
        x++;
        if (x % cipher->x == 0) {
            x = 0;
            y++;
        }
        for (int j = i; j < i + chunk; j++)
            phrase[j] = 32;
        i += chunk;
    }
}
