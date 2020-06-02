/*
** EPITECH PROJECT, 2019
** multiply_matrices.c
** File description:
** Multiply matrices
*/

#include <stdlib.h>
#include "103cipher.h"

float **allocate_result(int x, int y)
{
    float **result = malloc(y * sizeof(float *));

    for (int i = 0; i < y; i++)
        result[i] = malloc(x * sizeof(float));
    return (result);
}

float **multiply_matrices(cipher_t *cipher)
{
    float **result = allocate_result(cipher->x, cipher->y);

    for (int k = 0; k < cipher->x; k++) {
        for (int i = 0; i < cipher->x; i++) {
            for (int j = 0; j < cipher->y; j++) {
                result[j][i] += (cipher->phrase[j][k] * cipher->key[k][i]);
            }
        }
    }
    return (result);
}
