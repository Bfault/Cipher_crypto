/*
** EPITECH PROJECT, 2019
** 103cipher_2019
** File description:
** fill_in_ascii.c
*/

#include "103cipher.h"

void fill_in_ascii(cipher_t *cipher, char *str_key, char *str_phrase)
{
    int len_key = my_strlen(str_key);
    int len_phrase = my_strlen(str_phrase);
    int count = 0;

    for (int x = 0; x < cipher->x; x++)
        for (int y = 0; y < cipher->x; y++) {
            if (y + x * (cipher->x) >= len_key)
                cipher->key[x][y] = 0;
            else
                cipher->key[x][y] = str_key[y + x * cipher->x];
        }
    for (int i = 0; i < cipher->y; i++)
        for (int j = 0; j < cipher->x; j++) {
            if (count > len_phrase)
                cipher->phrase[i][j] = 0;
            else
                cipher->phrase[i][j] = str_phrase[count];
            count++;
        }
}

void fill_key(cipher_t *cipher, char *key)
{
    int len_key = my_strlen(key);

    for (int x = 0; x < cipher->x; x++)
        for (int y = 0; y < cipher->x; y++)
        {
            if (y + x * (cipher->x) >= len_key)
                cipher->key[x][y] = 0;
            else
                cipher->key[x][y] = key[y + x * cipher->x];
        }
}