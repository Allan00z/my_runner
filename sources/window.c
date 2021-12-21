/*
** EPITECH PROJECT, 2021
** B-MUL-100-LYN-1-1-myrunner-allan.branco
** File description:
** window
*/
#include "../my.h"

int close_window(sfRenderWindow* window, sfEvent event)
{
    if (event.type == sfEvtClosed) {
        sfRenderWindow_close(window);
        return (1);
    }
    return (0);
}

void destroyer(game_t map, play_t *character, opp_t *enemy, menu_t *menu)
{
    sfSprite_destroy(menu[0].start.sprite);
    sfSprite_destroy(menu[0].options.sprite);
    sfSprite_destroy(menu[0].exit.sprite);
    sfClock_destroy(map.clock);
    sfClock_destroy(character[0].jump_clock);
    sfClock_destroy(enemy[0].opp_clock);
    sfSprite_destroy(enemy[0].sprite);
    sfSprite_destroy(map.background.sprite);
    sfSprite_destroy(map.midground.sprite);
    sfSprite_destroy(character[0].sprite);
    sfSprite_destroy(map.foreground.sprite);
    sfTexture_destroy(map.sprites);
    sfRenderWindow_destroy(map.window);
}

int runner_main(void)
{
    sfVideoMode mode = {800, 600, 32};
    game_t map = map_init(map, mode);
    menu_t *menu = main_menu_init(map);
    play_t *character = player_init(map);
    opp_t *enemy = oppenent_init(map);

    if (main_menu_display(menu, map) == 1) {
        destroyer(map, character, enemy, menu);
        return (0);
    }
    while (sfRenderWindow_isOpen(map.window)) {
        sfRenderWindow_clear(map.window, map.sky);
        while (sfRenderWindow_pollEvent(map.window, &map.event))
            jump_character(character, map);
        map = paralax_map(map, character, enemy);
        move_jump(character, map);
    }
    destroyer(map, character, enemy, menu);
    free(enemy);
    free(character);
    return (0);
}

int main(int argc, char **argv)
{
    int i;

    if (argc == 2 && my_strcmp(argv[1], "-h") == 0)
        display_help();
    else if (argc == 1)
         return (runner_main());
    else
        return (84);
    return (0);
}