/*
** EPITECH PROJECT, 2021
** B-MUL-100-LYN-1-1-myrunner-allan.branco
** File description:
** object_init
*/
#include "../my.h"

game_t objects_init(game_t map)
{
    map.finish.rect = init_rect(0, 1250, 424, 886);
    map.finish.sprite = sfSprite_create();
    sfSprite_setTexture(map.finish.sprite, map.sprites, sfFalse);
    sfSprite_setTextureRect(map.finish.sprite, map.finish.rect);
    map.foreground.rect = init_rect(0, 1889, 271, 800);
    map.foreground.sprite = sfSprite_create();
    map.midground.sprite = sfSprite_create();
    map.background.sprite = sfSprite_create();
    map.foreground.vec = init_vect(0, 329);
    map.background.rect = init_rect(0, 0, 101, 3840);
    map.background.vec = init_vect(0, 0);
    map.midground.rect = init_rect(0, 131, 270, 1232);
    map.midground.vec = init_vect(0, 80);
    sfSprite_setTexture(map.foreground.sprite, map.sprites, sfFalse);
    sfSprite_setTexture(map.background.sprite, map.sprites, sfFalse);
    sfSprite_setTexture(map.midground.sprite, map.sprites, sfFalse);
    sfSprite_setTextureRect(map.midground.sprite, map.midground.rect);
    sfSprite_setTextureRect(map.background.sprite, map.background.rect);
    sfSprite_setTextureRect(map.foreground.sprite, map.foreground.rect);
    return (map);
}