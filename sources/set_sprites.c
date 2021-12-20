/*
** EPITECH PROJECT, 2021
** B-MUL-100-LYN-1-1-myrunner-allan.branco
** File description:
** set_sprites
*/

#include "../my.h"

sfVector2f init_vect(int x, int y)
{
    sfVector2f vec;

    vec.x = x;
    vec.y = y;
    return (vec);
}

obj_t init_rect(int x, int y, int height, int width)
{
    obj_t object;

    object.rect.left = x;
    object.rect.top = y;
    object.rect.height = height;
    object.rect.width = width;
    object.sprite = sfSprite_create();
    return (object);
}

play_t init_rect_player(int x, int y, int height, int width)
{
    play_t character;

    character.rect.left = x;
    character.rect.top = y;
    character.rect.width = width;
    character.rect.height = height;
    character.sprite = sfSprite_create();
    return (character);
}

void *move_player(play_t *character)
{
    if (character[0].rect.left == 67)
        character[0].rect.left += 64;
    else if (character[0].rect.left == 198)
        character[0].rect.left = 0;
    else
        character[0].rect.left += 67;
}

int display_help(void)
{
    write(1, "Welcome in Goal Hero !\n\n", 24);
    write(1, "The goal : reach the end of the field by ", 43);
    write(1, "passing the opposing defense.\n\nControls :\n", 42);
    return (0);
}