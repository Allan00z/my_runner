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
    map.nb_enemy = 0;
    map.sprites = sfTexture_createFromFile("sprite/sprites.png", NULL);
    map.window = sfRenderWindow_create(mode, "Goal Hero", sfClose, NULL);
    sfRenderWindow_setFramerateLimit(map.window, 60);
    map = objects_init(map);
    map.view = sfView_create();
    map.view = sfView_createFromRect((sfFloatRect) {0, 0, 800, 600});
    map.clock = sfClock_create();
    sfRenderWindow_setMouseCursorVisible(map.window, sfTrue);
    map.is_finish = 0;
    map.font = sfFont_createFromFile("sprite/Minecraft.ttf");
    return (map);
}

play_t *player_init(game_t map)
{
    play_t *character = malloc(sizeof(play_t));

    character[0] = init_rect_player(0, 406, 64, 41);
    character[0].vec = init_vect(5, 400);
    character[0].is_jumping = 0;
    character[0].jump_clock = sfClock_create();
    character[0].high_jump = 0;
    sfSprite_setTexture(character[0].sprite, map.sprites, sfFalse);
    sfSprite_setTextureRect(character[0].sprite, character[0].rect);
    sfSprite_scale(character[0].sprite, (sfVector2f) {2, 2});
    character[0].run_clock = sfClock_create();
    return (character);
}

opp_t *oppenent_init(game_t map, char **level)
{
    opp_t *enemy;

    for (int i = 0; i < my_strlen(level[0]); i++) {
        if (level[0][i] == '2')
            map.nb_enemy += 1;
    }
    enemy = malloc(sizeof(opp_t) * map.nb_enemy);
    for (int i = 0; i < map.nb_enemy; i++) {
        enemy[i].character = '2';
        enemy[i].rect = init_rect(0, 471, 64, 41);
        enemy[i].sprite = sfSprite_create();
        enemy[i].vec = init_vect(850, 400);
        sfSprite_setTexture(enemy[i].sprite, map.sprites, sfFalse);
        sfSprite_setTextureRect(enemy[i].sprite, enemy[i].rect);
        sfSprite_scale(enemy[i].sprite, (sfVector2f) {-2, 2});
        enemy[i].opp_clock = sfClock_create();
    }
    return (enemy);
}

obj_t start_init(game_t map)
{
    obj_t object;

    object.rect = init_rect(0, 546, 128, 256);
    object.vec = init_vect(250, 150);
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
    object.rect = init_rect(0, 828, 128, 256);
    object.vec = init_vect(250, 350);
    object.sprite = sfSprite_create();
    sfSprite_setTexture(object.sprite, map.sprites, sfFalse);
    sfSprite_setTextureRect(object.sprite, object.rect);
    sfSprite_setPosition(object.sprite, object.vec);
    sfRenderWindow_drawSprite(map.window, object.sprite, NULL);
    return (object);
}
