/*
** EPITECH PROJECT, 2019
** main.c
** File description:
** Main file for 103cipher
*/

#include <unistd.h>
#include "103cipher.h"

int usage(void)
{
    write(1, "\e[1;35m", 7);
    write(1, "USAGE\n   ./103cipher message key flag\nDESCRIPTION\n   me", 55);
    write(1, "ssage\ta message, made of ASCII characters\n   key\t\tthe ", 54);
    write(1, "encryption key, made of ASCII characters\n   flag\t\t0 for", 55);
    write(1, " the message to be encrypted, 1 to be decrypted\n", 48);
    write(1, "\e[0m", 4);
    return (0);
}

int main(int argc, char **argv)
{
    if (argc != 2 && argc != 4)
        return (error("Usage -> ./103cipher -h.\n", 26));
    if (argv[1][0] == '-' && argv[1][1] == 'h' && my_strlen(argv[1]) == 2)
        return (usage());
    return (cipher(argv));
}
