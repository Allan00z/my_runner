/*
** EPITECH PROJECT, 2021
** B-MUL-100-LYN-1-1-myrunner-allan.branco
** File description:
** menu
*/
#include "../my.h"

int check_args(int argc, char **argv)
{
    sfRenderWindow *window;
    sfVideoMode mode = {800, 600, 32};
    int x = 84;

    if (my_strcmp(argv[1], "-h") == 0)
        return (display_help());
    if (my_strcmp(argv[1], "lvl1.txt") == 0) {
        window = sfRenderWindow_create(mode, "Goal Hero", sfClose, NULL);
        x = runner_main(argv[1], window);
    }
    if (my_strcmp(argv[1], "lvl2.txt") == 0) {
        window = sfRenderWindow_create(mode, "Goal Hero", sfClose, NULL);
        x = runner_main(argv[1], window);
    }
    if (my_strcmp(argv[1], "lvl3.txt") == 0) {
        window = sfRenderWindow_create(mode, "Goal Hero", sfClose, NULL);
        x = runner_main(argv[1], window);
    }
    sfRenderWindow_destroy(window);
    return (x);
}

int end_pressed(sfMouseButtonEvent mse, game_t map)
{
    if (mse.button != sfMouseLeft)
        return (0);
    if (mse.x >= 275 && mse.x <= 531) {
        if (mse.y >= 250 && mse.y <= 378)
            return (1);
    }
    return (0);
}

void set_sprite(sfSprite *sprite, sfVector2f vec, sfRenderWindow *wind, int x)
{
    sfSprite_setPosition(sprite, vec);
    sfRenderWindow_drawSprite(wind, sprite, NULL);
    vec.x += x;
    sfSprite_setPosition(sprite, vec);
    sfRenderWindow_drawSprite(wind, sprite, NULL);
    vec.x -= x;
}

int press_menu(menu_t *menu, game_t map, play_t *character)
{
    sfMouseButtonEvent mse = map.event.mouseButton;

    if (mse.button != sfMouseLeft)
        return (0);
    if (mse.x >= 275 && mse.x <= 275 + 256) {
        if (mse.y >= 250 && mse.y <= 250 + 128) {
            map.foreground.vec = init_vect(map.x, 329);
            map.background.vec = init_vect(map.x, 0);
            map.midground.vec = init_vect(map.x, 80);
            main_menu_display(menu, map, map.x, character);
            return (1);
        }
    }
    return (0);
}