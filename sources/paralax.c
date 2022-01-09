/*
** EPITECH PROJECT, 2021
** B-MUL-100-LYN-1-1-myrunner-allan.branco
** File description:
** paralax
*/
#include "../my.h"

game_t paralax_ground(game_t map)
{
    if (map.foreground.vec.x <= -723 + map.x)
        map.foreground.vec.x = 0 + map.x;
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
    if (map.background.vec.x <= -3840 + map.x)
        map.background.vec.x = 0 + map.x;
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
    if (map.midground.vec.x <= map.x - 1232)
        map.midground.vec.x = 0 + map.x;
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

void enemy_move(opp_t *enemy, play_t *character, game_t map, int i)
{
    sfSprite_setPosition(enemy[i].sprite, enemy[i].vec);
    enemy[i].time = sfClock_getElapsedTime(enemy[i].opp_clock);
    enemy[i].opp_seconds =  enemy[i].time.microseconds / 1000000.0;
    if (enemy[i].opp_seconds >= 0.15) {
        move_opponent(enemy, i);
        sfClock_restart(enemy[i].opp_clock);
    }
    if (enemy[i].vec.x <= map.x - 50)
        character[0].score += 1;
    if (character[0].high_score < character[0].score)
        character[0].high_score = character[0].score;
    sfSprite_setTextureRect(enemy[i].sprite, enemy[i].rect);
    sfRenderWindow_drawSprite(map.window, enemy[i].sprite, NULL);
}

game_t paralax_map(game_t map, play_t *character, opp_t *enemy, menu_t *menu)
{
    map = move_run(character, map);
    if (map.x >= lenght_reader(map.file) * 40)
        return (display_finish(map, character, menu));
    map = paralax_back(map);
    map = ground_move(map);
    map = paralax_mid(map);
    sfRenderWindow_drawSprite(map.window, map.finish.sprite, NULL);
    for (int i = map.nb; i < map.nb_enemy; i++) {
        enemy_move(enemy, character, map, i);
        if (enemy[i].vec.x <= map.x -50)
            map.nb = map.nb + 1;
    }
    if (map.seconds >= 0.03) {
        map.x += 10;
        character[0].vec.x += 10;
        sfView_move(map.view, (sfVector2f) {10, 0});
        sfClock_restart(map.clock);
    }
    paralax_displa(character, enemy, map, menu);
    return (map);
}
