/*
** EPITECH PROJECT, 2021
** B-MUL-100-LYN-1-1-myrunner-allan.branco
** File description:
** main_menu
*/
#include "../my.h"

menu_t *main_menu_init(game_t map)
{
    menu_t *menu = malloc(sizeof(menu_t));

    menu[0].is_playing = 0;
    menu[0].start = start_init(map);
    menu[0].exit = exit_init(map);
    return (menu);
}

int position_check(sfVector2f vector, sfMouseButtonEvent mouse, int x, int y)
{
    if (mouse.x >= vector.x && mouse.x <= vector.x + x) {
        if (mouse.y >= vector.y && mouse.y <= vector.y + y) {
            return (1);
        }
    }
    return (0);
}

void get_pressed(menu_t *menu, game_t map)
{
    sfMouseButtonEvent mse;

    sfRenderWindow_pollEvent(map.window, &map.event);
    if (map.event.mouseButton.type != sfEvtMouseButtonPressed) {
        if (map.event.mouseButton.button != sfMouseLeft)
            return;
    }
    mse = map.event.mouseButton;
    menu[0].start.press = position_check(menu[0].start.vec, mse, 256, 128);
    menu[0].exit.press = position_check(menu[0].exit.vec, mse, 256, 128);
}

int main_menu_display(menu_t *menu, game_t map)
{
    while (menu[0].is_playing != 1) {
        display_sprite_menu(map, menu);
        while (sfRenderWindow_pollEvent(map.window, &map.event))
            get_pressed(menu, map);
        sfRenderWindow_setView(map.window, map.view);
        sfRenderWindow_display(map.window);
        if (menu[0].start.press == 1) {
            menu[0].is_playing = 1;
            return (0);
        }
        if (menu[0].exit.press == 1) {
            sfRenderWindow_close(map.window);
            return (1);
        }
        if (close_window(map.window, map.event) == 1)
            return (1);
    }
}