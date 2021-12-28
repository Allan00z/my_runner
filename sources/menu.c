/*
** EPITECH PROJECT, 2021
** B-MUL-100-LYN-1-1-myrunner-allan.branco
** File description:
** menu
*/
#include "../my.h"

int check_args(int argc, char **argv)
{
    if (my_strcmp(argv[1], "-h") == 0)
        return (display_help());
    if (my_strcmp(argv[1], "lvl1.txt") == 0)
        return (runner_main(argv[1]));
    if (my_strcmp(argv[1], "lvl2.txt") == 0)
        return (runner_main(argv[1]));
    if (my_strcmp(argv[1], "lvl3.txt") == 0)
        return (runner_main(argv[1]));
    return (84);
}

game_t display_finish(game_t map, play_t *character)
{
    sfSprite_setPosition(map.background.sprite, map.background.vec);
    sfRenderWindow_drawSprite(map.window, map.background.sprite, NULL);
    map.background.vec.x += 3840;
    sfSprite_setPosition(map.background.sprite, map.background.vec);
    sfRenderWindow_drawSprite(map.window, map.background.sprite, NULL);
    map.background.vec.x -= 3840;
    sfSprite_setPosition(map.foreground.sprite, map.foreground.vec);
    sfRenderWindow_drawSprite(map.window, map.foreground.sprite, NULL);
    map.foreground.vec.x += 723;
    sfSprite_setPosition(map.foreground.sprite, map.foreground.vec);
    sfRenderWindow_drawSprite(map.window, map.foreground.sprite, NULL);
    sfSprite_setPosition(map.midground.sprite, map.midground.vec);
    sfRenderWindow_drawSprite(map.window, map.midground.sprite, NULL);
    map.midground.vec.x += 1232;
    sfSprite_setPosition(map.midground.sprite, map.midground.vec);
    sfRenderWindow_drawSprite(map.window, map.midground.sprite, NULL);
    map.midground.vec.x -= 1232;
    sfRenderWindow_drawSprite(map.window, map.finish.sprite, NULL);
    sfSprite_setPosition(character[0].sprite, character[0].vec);
    sfRenderWindow_drawSprite(map.window, character[0].sprite, NULL);
    map = victory_end(map, character);
    sfRenderWindow_display(map.window);
    return (map);
}