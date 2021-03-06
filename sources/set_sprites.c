/*
** EPITECH PROJECT, 2021
** B-MUL-100-LYN-1-1-myrunner-allan.branco
** File description:
** set_sprites
*/

#include "../my.h"

sfVector2f init_vect(int x, int y)
{
    sfVector2f vec;

    vec.x = x;
    vec.y = y;
    return (vec);
}

sfIntRect init_rect(int x, int y, int height, int width)
{
    sfIntRect rect;

    rect.left = x;
    rect.top = y;
    rect.height = height;
    rect.width = width;
    return (rect);
}

play_t init_rect_player(int x, int y, int height, int width)
{
    play_t character;

    character.rect.left = x;
    character.rect.top = y;
    character.rect.width = width;
    character.rect.height = height;
    character.sprite = sfSprite_create();
    return (character);
}

void *move_player(play_t *character)
{
    if (character[0].rect.left == 67)
        character[0].rect.left += 64;
    else if (character[0].rect.left == 198)
        character[0].rect.left = 0;
    else
        character[0].rect.left += 67;
}

void *move_opponent(opp_t *enemy, int i)
{
    if (enemy[i].rect.left == 67)
        enemy[i].rect.left += 64;
    else if (enemy[i].rect.left == 198)
        enemy[i].rect.left = 0;
    else
        enemy[i].rect.left += 67;
}
