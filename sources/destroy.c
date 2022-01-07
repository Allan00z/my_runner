/*
** EPITECH PROJECT, 2022
** B-MUL-100-LYN-1-1-myrunner-allan.branco
** File description:
** destroy
*/
#include "../my.h"

void destroyer_menu_charac(menu_t *menu, play_t *character)
{
    sfSprite_destroy(menu[0].start.sprite);
    sfSprite_destroy(menu[0].exit.sprite);
    sfSprite_destroy(menu[0].menu.sprite);
    sfSprite_destroy(character[0].sprite);
    sfClock_destroy(character[0].jump_clock);
    sfClock_destroy(character[0].run_clock);
    free(menu);
}

void destroyer(game_t map, play_t *character, opp_t *enemy, menu_t *menu)
{
    high_score_write(map.file, character);
    sfClock_destroy(map.clock);
    destroyer_menu_charac(menu, character);
    for (int i = 0; i < map.nb_enemy; i++) {
        sfClock_destroy(enemy[i].opp_clock);
        sfSprite_destroy(enemy[i].sprite);
    }
    sfView_destroy(map.view);
    sfSprite_destroy(map.background.sprite);
    sfSprite_destroy(map.midground.sprite);
    sfSprite_destroy(map.foreground.sprite);
    sfTexture_destroy(map.sprites);
    sfFont_destroy(map.font);
    sfSprite_destroy(map.finish.sprite);
    sfRenderWindow_clear(map.window, map.sky);
    sfMusic_destroy(map.music);
    sfSound_destroy(map.sound);
    sfSoundBuffer_destroy(map.buffer);
}

op_menu_t destroyer_option(op_menu_t options, menu_t *menu)
{
    sfSprite_destroy(options.one.sprite);
    sfSprite_destroy(options.op_one.sprite);
    sfSprite_destroy(options.two.sprite);
    sfSprite_destroy(options.op_two.sprite);
    sfSprite_destroy(options.three.sprite);
    sfSprite_destroy(options.op_three.sprite);
    sfSprite_destroy(options.back.sprite);
    menu[0].options.press = 0;
    return (options);
}

void free_all(opp_t *enemy, play_t *character, char **level)
{
    free(enemy);
    free(character);
    free(level[0]);
    free(level[1]);
    free(level);
}