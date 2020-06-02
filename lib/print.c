/*
** EPITECH PROJECT, 2019
** 103cipher_2019
** File description:
** print.c
*/

#include <math.h>
#include <stdio.h>
#include <unistd.h>
#include "103cipher.h"

void print_encrypt(cipher_t *encrypt, float **output)
{
    write(0, "\e[1;32m", 7);
    printf("Key matrix:\n");
    for (int i = 0; i < encrypt->x; i++) {
        for (int j = 0; j < encrypt->x; j++) {
            if (j != 0)
                printf("\t");
            printf("%0.f", encrypt->key[i][j]);
        }
        printf("\n");
    }
    printf("\nEncrypted message:\n");
    for (int i = 0; i < encrypt->y; i++)
        for (int j = 0; j < encrypt->x; j++) {
            printf("%.0f", output[i][j]);
            if (!(i == encrypt->y - 1 && j == encrypt->x - 1))
                printf(" ");
        }
    printf("\n");
    write(0, "\e[0m", 4);
}

void print_decrypt(cipher_t *encrypt, float **output)
{
    write(0, "\e[1;32m", 7);
    printf("Key matrix:\n");
    for (int i = 0; i < encrypt->x; i++) {
        for (int j = 0; j < encrypt->x; j++) {
            if (j != 0)
                printf("\t");
            if (encrypt->key[i][j] > 0.001 || encrypt->key[i][j] < -0.001)
                printf("%.3f", encrypt->key[i][j]);
            else
                printf("0.0");
        }
        printf("\n");
    }
    printf("\nDecrypted message:\n");
    for (int i = 0; i < encrypt->y; i++)
        for (int j = 0; j < encrypt->x &&
        (char)(round(output[i][j])) != 0; j++)
            printf("%c", (char)(round(output[i][j])));
    printf("\n");
    write(0, "\e[0m", 4);
}