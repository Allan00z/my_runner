/*
** EPITECH PROJECT, 2021
** B-MUL-100-LYN-1-1-myrunner-allan.branco
** File description:
** paralax
*/
#include "../my.h"

game_t paralax_ground(game_t map)
{
    if (map.foreground.vec.x <= -723)
        map.foreground.vec.x = 0;
    sfSprite_setPosition(map.foreground.sprite, map.foreground.vec);
    sfRenderWindow_drawSprite(map.window, map.foreground.sprite, NULL);
    map.foreground.vec.x += 723;
    sfSprite_setPosition(map.foreground.sprite, map.foreground.vec);
    sfRenderWindow_drawSprite(map.window, map.foreground.sprite, NULL);
    map.time = sfClock_getElapsedTime(map.clock);
    map.seconds = map.time.microseconds / 1000000.0;
    if (map.seconds >= 0.03)
        map.foreground.vec.x -= 728;
    else
        map.foreground.vec.x -= 723;
    return (map);
}

game_t paralax_back(game_t map)
{
    if (map.background.vec.x <= -3840)
        map.background.vec.x = 0;
    sfSprite_setPosition(map.background.sprite, map.background.vec);
    sfRenderWindow_drawSprite(map.window, map.background.sprite, NULL);
    map.background.vec.x += 3840;
    sfSprite_setPosition(map.background.sprite, map.background.vec);
    sfRenderWindow_drawSprite(map.window, map.background.sprite, NULL);
    map.time = sfClock_getElapsedTime(map.clock);
    map.seconds = map.time.microseconds / 1000000.0;
    if (map.seconds >= 0.03)
        map.background.vec.x -= 3843;
    else
        map.background.vec.x -= 3840;
    return (map);
}

game_t paralax_mid(game_t map)
{
    if (map.midground.vec.x <= -1232)
        map.midground.vec.x = 0;
    sfSprite_setPosition(map.midground.sprite, map.midground.vec);
    sfRenderWindow_drawSprite(map.window, map.midground.sprite, NULL);
    map.midground.vec.x += 1232;
    sfSprite_setPosition(map.midground.sprite, map.midground.vec);
    sfRenderWindow_drawSprite(map.window, map.midground.sprite, NULL);
    map.time = sfClock_getElapsedTime(map.clock);
    map.seconds = map.time.microseconds / 1000000.0;
    if (map.seconds >= 0.03)
        map.midground.vec.x -= 1237;
    else
        map.midground.vec.x -= 1232;
    return (map);
}

game_t paralax_map(game_t map, play_t *character, opp_t *enemy)
{
    map = paralax_back(map);
    map = paralax_ground(map);
    map = paralax_mid(map);
    map = move_run(character, map);
    sfSprite_setPosition(enemy[0].sprite, enemy[0].vec);
    sfRenderWindow_drawSprite(map.window, enemy[0].sprite, NULL);
    enemy[0].time = sfClock_getElapsedTime(enemy[0].opp_clock);
    enemy[0].opp_seconds =  enemy[0].time.microseconds / 1000000.0;
    if (enemy[0].opp_seconds >= 0.15) {
        move_opponent(enemy);
        sfClock_restart(enemy[0].opp_clock);
    }
    if (map.seconds >= 0.03) {
        sfClock_restart(map.clock);
        enemy[0].vec.x -= 12;
        if (enemy[0].vec.x <= -50)
            enemy[0].vec.x = 850;
    }
    sfSprite_setTextureRect(enemy[0].sprite, enemy[0].rect);
    return (map);
}

int display_help(void)
{
    write(1, "Welcome in Goal Hero !\n\n", 24);
    write(1, "The goal : reach the end of the field by ", 43);
    write(1, "passing the opposing defense.\n\nControls :\n", 42);
    return (0);
}