/*
** EPITECH PROJECT, 2021
** my_getnbr
** File description:
** Returns a number sent as a string
*/
#include "../my.h"

int my_getnbr(char const *str)
{
    int i = 0;
    int prev = 0;
    int dash = 0;

    while ((str[i] >= '0' && str[i] <= '9') || str[i] == '-') {
        if ((str[i] >= '0') && (str[i] <= '9')) {
            prev = prev * 10 + str[i] - 48;
            i = i + 1;
        }
        if (str[i] == '-') {
            dash++;
            i++;
        }
    }
    if (dash % 2 == 0 || dash == 0)
        return (prev);
    if (dash % 2 != 0)
        return (prev * - 1);
}
