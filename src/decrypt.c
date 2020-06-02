/*
** EPITECH PROJECT, 2019
** decrypt.c
** File description:
** decrypt
*/

#include <stdlib.h>
#include "103cipher.h"

int decrypt(char *phrase, char *key)
{
    cipher_t decrypt;
    float **output;
    int code = 0;

    decrypt.x = find_size_x_key(key);
    decrypt.y = find_size_y_floats(phrase, decrypt.x);
    malloc_it(&decrypt);
    fill_key(&decrypt, key);
    fill_phrase(&decrypt, phrase);
    code = invert_key(&decrypt);
    if (code == 84)
        return (84);
    output = multiply_matrices(&decrypt);
    print_decrypt(&decrypt, output);
    free(output);
    free_it(&decrypt);
    return (0);
}
