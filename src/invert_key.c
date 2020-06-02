/*
** EPITECH PROJECT, 2019
** invert_key.c
** File description:
** Invert matrix key
*/

#include <math.h>
#include "103cipher.h"
#include <stdlib.h>

float **normalization(cipher_t *cipher, float **matx_id, int i, float a)
{
    for (int j = 0; j < cipher->x; j++) {
        cipher->key[j][i] = cipher->key[j][i] / a;
        matx_id[j][i] = matx_id[j][i] / a;
    }
    return (matx_id);
}

float **diagonal_checking_and_normalization
(cipher_t *cipher, float **matx_id, int i)
{
    float a = cipher->key[i][i];
    int c = -1;
    int d = 0;

    while (fabsf(a) < 0.001) {
        c++;
        for (int j = 0; j < cipher->x; j++) {
            d = j + c - cipher->x;
            cipher->key[j][i] = j + c > cipher->x ? cipher->key[j][i] +
            cipher->key[j + 1][i + d] : cipher->key[j][i] +
            cipher->key[j][i + c];
            matx_id[j][i] = j + c >= matx_id[j][i] ? matx_id[j][i] +
            matx_id[j + 1][i + d] : matx_id[j][i] + matx_id[j][i + c];
        }
        a = cipher->key[i][i];
    }
    return (normalization(cipher, matx_id, i, a));
}

float **set_identity(cipher_t *cipher, float **matx_id)
{
    for (int i = 0; i < cipher->x; i++)
        matx_id[i] = malloc(sizeof(float) * cipher->x);
    for (int i = 0; i < cipher->x; i++)
        for (int j = 0; j < cipher->x; j++)
            matx_id[i][j] = i == j ? 1 : 0;
    return (matx_id);
}

float **gauss_reduction(cipher_t *cipher, float **matx_id, int i)
{
    float b = 0.0;
    for (int j = 0; j < cipher->x; j++) {
        b = cipher->key[i][j];
        if (j != i)
            for (int k = 0; k < cipher->x; k++) {
                cipher->key[k][j] = cipher->key[k][j] - b * cipher->key[k][i];
                matx_id[k][j] = matx_id[k][j] - b * matx_id[k][i];
                if (cipher->key[k][j] == 0 && k == j)
                    cipher->error = 84;
            }
    }
    return (matx_id);
}

int invert_key(cipher_t *cipher)
{
    cipher->error = 0;
    if (cipher->x < 1)
        return (84);
    float **matx_id = malloc(sizeof(float *) * cipher->x);
    matx_id = set_identity(cipher, matx_id);
    for (int i = 0; i < cipher->x; i++) {
        matx_id = diagonal_checking_and_normalization(cipher, matx_id, i);
        matx_id = gauss_reduction(cipher, matx_id, i);
        if (cipher->error == 84)
            return (error("unreversed matrix.\n", 20));
    }
    for (int i = 0; i < cipher->x; i++)
        for (int j = 0; j < cipher->x; j++)
            cipher->key[i][j] = matx_id[i][j];
    for (int i = 0; i < cipher->x; i++)
        free(matx_id[i]);
    free(matx_id);
    return (0);
}