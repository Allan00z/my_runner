/*
** EPITECH PROJECT, 2021
** my_strlen
** File description:
** Returns numbers of charact in a string
*/

int my_strlen(char const *str)
{
    int nb;

    nb = 0;
    while (str[nb] != '\0') {
        nb = nb + 1;
    }
    return (nb);
}
