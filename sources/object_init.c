/*
** EPITECH PROJECT, 2021
** B-MUL-100-LYN-1-1-myrunner-allan.branco
** File description:
** object_init
*/
#include "../my.h"

obj_t menu_init(game_t map)
{
    obj_t object;

    object.rect = init_rect(0, 838, 128, 256);
    object.vec = init_vect(map.x + 100, 150);
    object.sprite = sfSprite_create();
    object.press = 0;
    sfSprite_setTexture(object.sprite, map.sprites, sfFalse);
    sfSprite_setTextureRect(object.sprite, object.rect);
    return (object);
}

obj_t options_init(game_t map)
{
    obj_t object;

    object.rect = init_rect(0, 1116, 128, 256);
    object.vec = init_vect(250, 225);
    object.sprite = sfSprite_create();
    object.press = 0;
    sfSprite_setTexture(object.sprite, map.sprites, sfFalse);
    sfSprite_setTextureRect(object.sprite, object.rect);
    sfSprite_setPosition(object.sprite, object.vec);
    sfRenderWindow_drawSprite(map.window, object.sprite, NULL);
    return (object);
}


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

obj_t object_menu_init(game_t map, int height, int x, int y)
{
    obj_t obj;

    obj.vec = init_vect(x, y);
    obj.rect = init_rect(0, height, 64, 41);
    obj.sprite = sfSprite_create();
    sfSprite_scale(obj.sprite, (sfVector2f) {1.75, 1.75});
    sfSprite_setTexture(obj.sprite, map.sprites, sfFalse);
    sfSprite_setTextureRect(obj.sprite, obj.rect);
    sfSprite_setPosition(obj.sprite, obj.vec);
    sfRenderWindow_drawSprite(map.window, obj.sprite, NULL);
    return (obj);
}

void character_init(play_t *character)
{
    character[0] = init_rect_player(0, 406, 64, 41);
    character[0].vec = init_vect(5, 400);
    character[0].is_jumping = 0;
    character[0].jump_clock = sfClock_create();
    character[0].high_jump = 0;
}