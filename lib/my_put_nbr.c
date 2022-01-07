/*
** EPITECH PROJECT, 2021
** my_put_nbr
** File description:
** Change nbr into char
*/
#include <unistd.h>
#include "../my.h"

void my_putchar(char c)
{
    write(1, &c, 1);
}

char *my_nbr_str(int nb)
{
    int mod;
    int len = my_get_size_nbr(nb) - 1;
    char *number = malloc(sizeof(char) * len + 1);
    for (int i = len; i >= 0; i--) {
        mod = nb % 10;
        number[i] = mod + '0';
        nb = nb / 10;
    }
    number[len + 1] = '\0';
    return (number);
}
