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
    if (map.seconds >= 0.05)
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
    if (map.seconds >= 0.05)
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
    if (map.seconds >= 0.05)
        map.midground.vec.x -= 1237;
    else
        map.midground.vec.x -= 1232;
    return (map);
}

game_t paralax_map(game_t map, play_t *character)
{
    map = paralax_back(map);
    map = paralax_ground(map);
    map = paralax_mid(map);
    sfSprite_setPosition(character[0].sprite, character[0].vec);
    sfRenderWindow_drawSprite(map.window, character[0].sprite, NULL);
    if (map.seconds >= 0.15 && character[0].is_jumping == 0) {
        if (character[0].vec.y >= 400) {
            move_player(character);
            sfClock_restart(map.clock);
        }
    }
    sfSprite_setTextureRect(character[0].sprite, character[0].rect);
    return (map);
}