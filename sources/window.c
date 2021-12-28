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
    sfSprite_destroy(menu[0].exit.sprite);
    free(menu);
    sfClock_destroy(map.clock);
    sfClock_destroy(character[0].jump_clock);
    sfClock_destroy(character[0].run_clock);
    for (int i = 0; i < map.nb_enemy; i++) {
        sfClock_destroy(enemy[i].opp_clock);
        sfSprite_destroy(enemy[i].sprite);
    }
    sfSprite_destroy(map.background.sprite);
    sfSprite_destroy(map.midground.sprite);
    sfSprite_destroy(character[0].sprite);
    sfSprite_destroy(map.foreground.sprite);
    sfTexture_destroy(map.sprites);
    sfRenderWindow_destroy(map.window);
    sfView_destroy(map.view);
}

int display_help(void)
{
    write(1, "Welcome in Goal Hero !\n\nThe goal : ", 35);
    write(1, "reach the end of the field by passing the opposing", 50);
    write(1, " defense and jumping over the opponent.\n\n", 41);
    write(1, "Controls :\n     SPACEBAR -> jump\n", 33);
    return (0);
}

int runner_main(char *file)
{
    char **level = file_read(file);
    sfVideoMode mode = {800, 600, 32};
    game_t map = map_init(map, mode);
    menu_t *menu = main_menu_init(map);
    play_t *character = player_init(map);
    opp_t *enemy = oppenent_init(map, level);

    if (main_menu_display(menu, map) == 1) {
        destroyer(map, character, enemy, menu);
        return (0);
    }
    map.x = 0;
    map.nb_enemy = level_generator(level, map, enemy);
    while (sfRenderWindow_isOpen(map.window)) {
        sfRenderWindow_clear(map.window, map.sky);
        while (sfRenderWindow_pollEvent(map.window, &map.event))
            jump_character(character, map);
        map = paralax_map(map, character, enemy, file);
        move_jump(character, map, file);
    }
    destroyer(map, character, enemy, menu);
    free(enemy);
    free(character);
    return (0);
}

int main(int argc, char **argv)
{
    if (argc == 2)
        return (check_args(argc, argv));
    else
        return (84);
}