/*
** EPITECH PROJECT, 2021
** B-PSU-100-LYN-1-1-myls-allan.branco
** File description:
** my_strcmp
*/
#include "../my.h"

int my_strcmp(char const *s1, char const *s2)
{
    int i = 0;

    while (s1[i] == s2[i]) {
        if (s1[i] == '\0' && s2[i] == '\0')
            return (0);
        i++;
    }
    if (s1[i] < s2[i])
        return (1);
    else
        return (2);
}