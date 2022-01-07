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

int display_help(void)
{
    write(1, "Welcome in Goal Hero !\n\nThe goal : ", 35);
    write(1, "reach the end of the field by passing the opposing", 50);
    write(1, " defense and jumping over the opponent.\n\n", 41);
    write(1, "Controls :\n     SPACEBAR -> jump\n", 33);
    return (0);
}

int runner_main(char *file, sfRenderWindow *window)
{
    char **level = file_read(file);
    int is_menu = 0;
    game_t map = map_init(map, window, file);
    menu_t *menu = main_menu_init(map);
    play_t *character = player_init(map, file);
    opp_t *enemy = oppenent_init(map, level);

    if (main_menu_display(menu, map, 0, character) == 1) {
        destroyer(map, character, enemy, menu);
        return (0);
    }
    map.x = 0;
    map = level_generator(level, map, enemy, menu);
    while (sfRenderWindow_isOpen(map.window) && menu[0].is_playing == 1) {
        sfRenderWindow_clear(map.window, map.sky);
        while (sfRenderWindow_pollEvent(map.window, &map.event))
            jump_character(character, menu, map);
        map = paralax_map(map, character, enemy, menu);
        move_jump(character, map, menu, file);
    }
    if (menu[0].is_menu == 1)
        is_menu = 1;
    destroyer(map, character, enemy, menu);
    if (is_menu == 1)
        runner_main(file, map.window);
    free_all(enemy, character, level);
    return (0);
}

int main(int argc, char **argv)
{
    int ret = 84;

    if (argc == 2)
        ret = check_args(argc, argv);
    return (ret);
}