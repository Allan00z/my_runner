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
    menu[0].options = options_init(map);
    menu[0].exit = exit_init(map);
    menu[0].menu = menu_init(map);
    menu[0].is_menu = 0;
    menu[0].team_char = 1;
    menu[0].team_opp = 2;
    menu[0].sound = 1;
    return (menu);
}

int position_check(sfVector2f vector, sfMouseButtonEvent mouse, int x, int y)
{
    if (mouse.x >= vector.x && mouse.x <= vector.x + x) {
        if (mouse.y >= vector.y && mouse.y <= vector.y + y)
            return (1);
    }
    return (0);
}

void get_pressed(menu_t *menu, game_t map, int x)
{
    sfMouseButtonEvent mse;

    if (map.event.mouseButton.type != sfEvtMouseButtonPressed) {
        if (map.event.mouseButton.button != sfMouseLeft)
            return;
    }
    mse = map.event.mouseButton;
    menu[0].exit.vec.x += x;
    menu[0].start.vec.x += x;
    menu[0].options.vec.x += x;
    menu[0].start.press = position_check(menu[0].start.vec, mse, 256, 128);
    menu[0].options.press = position_check(menu[0].options.vec, mse, 256, 128);
    menu[0].exit.press = position_check(menu[0].exit.vec, mse, 256, 128);
}

int main_menu_display(menu_t *menu, game_t map, int x, play_t *character)
{
    sfView_reset(map.view, (sfFloatRect) {0, 0, 800, 600});
    sfRenderWindow_setView(map.window, map.view);
    menu[0].is_playing = 0;
    menu[0].is_menu = 1;
    while (menu[0].is_playing != 1) {
        display_sprite_menu(map, menu, x);
        while (sfRenderWindow_pollEvent(map.window, &map.event))
            get_pressed(menu, map, x);
        if (menu[0].start.press == 1) {
            menu[0].is_playing = 1;
            menu[0].is_menu = 0;
            return (0);
        }
        if (menu[0].options.press == 1)
            options_menu(menu, map, character);
        if (menu[0].exit.press == 1) {
            sfRenderWindow_close(map.window);
            return (1);
        }
        if (sfRenderWindow_isOpen(map.window) == sfFalse)
            return (1);
        close_window(map.window, map.event);
    }
}
