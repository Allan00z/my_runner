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
            character[0].high_jump = 15;
            character[0].rect.left = 67;
        }
    }
}

void move_jump(play_t *character)
{
    if (character[0].is_jumping == 1 && character[0].vec.y > 300) {
        character[0].vec.y -= character[0].high_jump;
        character[0].high_jump -= 1;
        return;
    }
    if (character[0].is_jumping == 1 || character[0].vec.y <= 300) {
        if (character[0].vec.y <= 300) {
            character[0].vec.y -= character[0].high_jump;
            character[0].high_jump -= 1;
            character[0].is_jumping = 0;
        }
    }
    if (character[0].is_jumping == 0 && character[0].vec.y < 400) {
        character[0].vec.y -= character[0].high_jump;
        character[0].high_jump -= 1;
    }
    if (character[0].is_jumping == 0 && character[0].vec.y >= 400)
        character[0].vec.y = 400;
}