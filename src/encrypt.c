/*
** EPITECH PROJECT, 2019
** encrypt.c
** File description:
** encrypt
*/

#include <stdlib.h>
#include "103cipher.h"

int encrypt(char *phrase, char *key)
{
    cipher_t encrypt;
    float **output;

    encrypt.x = find_size_x_key(key);
    encrypt.y = find_size_y_phrase(phrase, encrypt.x);
    malloc_it(&encrypt);
    fill_in_ascii(&encrypt, key, phrase);
    output = multiply_matrices(&encrypt);
    print_encrypt(&encrypt, output);
    free(output);
    free_it(&encrypt);
    return (0);
}
