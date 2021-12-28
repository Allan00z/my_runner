/*
** EPITECH PROJECT, 2021
** Untitled (Workspace)
** File description:
** my_get_size_nbr
*/
#include "../my.h"

int my_get_size_nbr(int nbr)
{
    int size = 1;

    while (nbr >= 10) {
        nbr = nbr / 10;
        size++;
    }
    return (size);
}