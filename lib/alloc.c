/*
** EPITECH PROJECT, 2019
** 103cipher_2019
** File description:
** alloc.c
*/

#include <stdlib.h>
#include "103cipher.h"

void free_it(cipher_t *cipher)
{
    for (int i = 0; i < cipher->x; i++)
        free(cipher->key[i]);
    free(cipher->key);
    for (int i = 0; i < cipher->y; i++)
        free(cipher->phrase[i]);
    free(cipher->phrase);
}

void malloc_it(cipher_t *cipher)
{
    cipher->key = malloc(sizeof(float *) * cipher->x);
    for (int i = 0; i < cipher->x; i++)
        cipher->key[i] = malloc(sizeof(float) * cipher->x);
    cipher->phrase = malloc(sizeof(float *) * cipher->y);
    for (int i = 0; i < cipher->y; i++)
        cipher->phrase[i] = malloc(sizeof(float) * cipher->x);
}
