/*
** EPITECH PROJECT, 2021
** B-MUL-100-LYN-1-1-myrunner-allan.branco
** File description:
** move
*/

#include "../my.h"

void jump_character(play_t *character, game_t map)
{
    sfEvent event = map.event;

    if (event.type == sfEvtKeyPressed && event.key.code == sfKeySpace) {
        if (character[0].is_jumping == 0 && character[0].vec.y >= 400) {
            character[0].is_jumping = 1;
            character[0].high_jump = 22;
            character[0].rect.left = 67;
        }
    }
    close_window(map.window, map.event);
}

void move_jump(play_t *character, game_t map)
{
    character[0].time = sfClock_getElapsedTime(character[0].jump_clock);
    character[0].seconds = character[0].time.microseconds / 1000000.0;
    if (character[0].is_jumping == 1 && character[0].vec.y > 390) {
        if (character[0].seconds >= 0.03) {
            character[0].vec.y -= character[0].high_jump;
            sfClock_restart(character[0].jump_clock);
        }
    }
    if (character[0].is_jumping == 1 || character[0].vec.y <= 390) {
        if (character[0].vec.y <= 390 && character[0].seconds >= 0.03) {
            character[0].is_jumping = 0;
            sfClock_restart(character[0].jump_clock);
        }
    }
    fall_jump(character);
    sfRenderWindow_display(map.window);
}

void fall_jump(play_t *character)
{
    if (character[0].is_jumping == 0 && character[0].vec.y < 400) {
        if (character[0].seconds >= 0.03) {
            character[0].vec.y -= character[0].high_jump;
            character[0].high_jump -= 2;
            sfClock_restart(character[0].jump_clock);
        }
    }
    if (character[0].is_jumping == 0) {
        if (character[0].vec.y - character[0].high_jump >= 400)
            character[0].vec.y = 400;
    }
}

game_t move_run(play_t *character, game_t map)
{
    sfSprite_setPosition(character[0].sprite, character[0].vec);
    sfRenderWindow_drawSprite(map.window, character[0].sprite, NULL);
    character[0].time = sfClock_getElapsedTime(character[0].run_clock);
    character[0].seconds = character[0].time.microseconds / 1000000.0;
    if (character[0].seconds >= 0.15 && character[0].is_jumping == 0) {
        if (character[0].vec.y >= 400.0)

            move_player(character);
            sfClock_restart(character[0].run_clock);
    }
    sfSprite_setTextureRect(character[0].sprite, character[0].rect);
    return (map);
}

void display_sprite_menu(game_t map, menu_t *menu)
{
    sfRenderWindow_clear(map.window, map.sky);
    sfSprite_setPosition(map.background.sprite, map.background.vec);
    sfSprite_setPosition(map.foreground.sprite, map.foreground.vec);
    sfSprite_setPosition(map.midground.sprite, map.midground.vec);
    sfRenderWindow_drawSprite(map.window, map.background.sprite, NULL);
    sfRenderWindow_drawSprite(map.window, map.foreground.sprite, NULL);
    sfRenderWindow_drawSprite(map.window, map.midground.sprite, NULL);
    sfRenderWindow_drawSprite(map.window, menu[0].start.sprite, NULL);
    sfRenderWindow_drawSprite(map.window, menu[0].options.sprite, NULL);
    sfRenderWindow_drawSprite(map.window, menu[0].exit.sprite, NULL);
}