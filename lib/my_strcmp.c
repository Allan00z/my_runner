/*
** EPITECH PROJECT, 2021
** my_strcmp
** File description:
** return if the s1 and s2 are equal or not
*/
#include <stdio.h>
#include "../my.h"

int my_strcmp(char const *s1, char const *s2)
{
    int i = 0;
    int length1 = my_strlen(s1);
    int length2 = my_strlen(s2);

    while (s1[i] != '\0') {
        if (s1[i] > s2[i]) {
            return (1);
        }
        if (s1[i] < s2[i]) {
            return (-1);
        }
        i = i + 1;
    }
    if (length1 > length2) {
        return (1);
    }
    if (length2 > length1) {
        return (-1);
    }
    return (0);
}
