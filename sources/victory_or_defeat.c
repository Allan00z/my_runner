/*
** EPITECH PROJECT, 2021
** B-MUL-100-LYN-1-1-myrunner-allan.branco
** File description:
** victory_or_defeat
*/
#include "../my.h"

game_t victory_end(game_t map, play_t *character)
{
    map.text = sfText_create();
    sfText_setFont(map.text, map.font);
    sfText_setString(map.text, "VICTORY");
    sfText_setPosition(map.text, (sfVector2f) {map.x + 200, 100});
    sfText_setFillColor(map.text, sfRed);
    sfText_setCharacterSize(map.text, 64);
    sfText_setScale(map.text, (sfVector2f) {1.5, 1.5});
    sfRenderWindow_drawText(map.window, map.text, sfFalse);
    return (map);
}