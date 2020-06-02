/*
** EPITECH PROJECT, 2019
** 103cipher.h
** File description:
** Header file for 103cipher
*/

#ifndef _103CIPHER_H_
#define _103CIPHER_H_

typedef struct cipher
{
    int x;
    int y;
    float **key;
    float **phrase;
    int error;
} cipher_t;

int my_strlen(char *);
int error(char *, int);
int cipher(char **);
int encrypt(char *, char *);
int decrypt(char *, char *);
int my_compute_power_rec(int, int);
int find_size_x_key(char *);
int find_size_y_phrase(char *, int);
int find_size_y_floats(char *, int);
void fill_phrase(cipher_t *, char *);
void fill_in_ascii(cipher_t *, char *, char *);
void fill_key(cipher_t *, char *);
float **multiply_matrices(cipher_t *);
int invert_key(cipher_t *);
void print_decrypt(cipher_t *, float **);
void print_encrypt(cipher_t *, float **);
void free_it(cipher_t *);
void malloc_it(cipher_t *);

#endif
