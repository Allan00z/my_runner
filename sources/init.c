/*
** EPITECH PROJECT, 2021
** B-MUL-100-LYN-1-1-myrunner-allan.branco
** File description:
** init
*/
#include "../my.h"

game_t map_init(game_t map, sfVideoMode mode)
{
    map.sky.r = 120;
    map.sky.g = 220;
    map.sky.b = 252;
    map.sky.a = 1;
    map.sprites = sfTexture_createFromFile("sprite/sprites.png", NULL);
    map.window = sfRenderWindow_create(mode, "Goal Hero", sfClose, NULL);
    map.foreground = init_rect(0, 1889, 271, 800);
    map.foreground.vec = init_vect(0, 329);
    map.background = init_rect(0, 0, 101, 3840);
    map.background.vec = init_vect(0, 0);
    map.midground = init_rect(0, 131, 270, 1232);
    map.midground.vec = init_vect(0, 80);
    sfSprite_setTexture(map.foreground.sprite, map.sprites, sfFalse);
    sfSprite_setTexture(map.background.sprite, map.sprites, sfFalse);
    sfSprite_setTexture(map.midground.sprite, map.sprites, sfFalse);
    sfSprite_setTextureRect(map.midground.sprite, map.midground.rect);
    sfSprite_setTextureRect(map.background.sprite, map.background.rect);
    sfSprite_setTextureRect(map.foreground.sprite, map.foreground.rect);
    map.clock = sfClock_create();
    return (map);
}

play_t *player_init(game_t map)
{
    play_t *character = malloc(sizeof(play_t));

    character[0] = init_rect_player(0, 406, 64, 41);
    character[0].vec = init_vect(0, 400);
    character[0].is_jumping = 0;
    character[0].jump_clock = sfClock_create();
    sfSprite_setTexture(character[0].sprite, map.sprites, sfFalse);
    sfSprite_setTextureRect(character[0].sprite, character[0].rect);
    sfSprite_scale(character[0].sprite, (sfVector2f) {2, 2});
    character[0].run_clock = sfClock_create();
    return (character);
}

opp_t *oppenent_init(game_t map)
{
    opp_t *enemy = malloc(sizeof(opp_t));

    enemy[0].rect.left = 0;
    enemy[0].rect.top = 471;
    enemy[0].rect.width = 41;
    enemy[0].rect.height = 64;
    enemy[0].sprite = sfSprite_create();
    enemy[0].vec = init_vect(850, 400);
    sfSprite_setTexture(enemy[0].sprite, map.sprites, sfFalse);
    sfSprite_setTextureRect(enemy[0].sprite, enemy[0].rect);
    sfSprite_scale(enemy[0].sprite, (sfVector2f) {-2, 2});
    enemy[0].opp_clock = sfClock_create();
    return (enemy);
}

obj_t start_init(game_t map)
{
    obj_t object;

    object = init_rect(0, 546, 128, 256);
    object.vec = init_vect(250, 50);
    object.sprite = sfSprite_create();
    object.press = 0;
    sfSprite_setTexture(object.sprite, map.sprites, sfFalse);
    sfSprite_setTextureRect(object.sprite, object.rect);
    sfSprite_setPosition(object.sprite, object.vec);
    sfRenderWindow_drawSprite(map.window, object.sprite, NULL);
    return (object);
}

obj_t exit_init(game_t map)
{
    obj_t object;

    object.press = 0;
    object = init_rect(0, 828, 128, 256);
    object.vec = init_vect(250, 350);
    object.sprite = sfSprite_create();
    sfSprite_setTexture(object.sprite, map.sprites, sfFalse);
    sfSprite_setTextureRect(object.sprite, object.rect);
    sfSprite_setPosition(object.sprite, object.vec);
    sfRenderWindow_drawSprite(map.window, object.sprite, NULL);
    return (object);
}
