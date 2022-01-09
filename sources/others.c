/*
** EPITECH PROJECT, 2022
** B-MUL-100-LYN-1-1-myrunner-allan.branco
** File description:
** others
*/
#include "../my.h"

int menu_start_press(menu_t *menu)
{
    menu[0].is_playing = 1;
    menu[0].is_menu = 0;
    return (0);
}

void set_position_option(game_t map, op_menu_t options, menu_t *menu)
{
    sfSprite_setPosition(map.background.sprite, map.background.vec);
    sfSprite_setPosition(map.foreground.sprite, map.foreground.vec);
    sfSprite_setPosition(map.midground.sprite, map.midground.vec);
    sfSprite_setPosition(options.one.sprite, options.one.vec);
    sfSprite_setPosition(options.two.sprite, options.two.vec);
    sfSprite_setPosition(options.three.sprite, options.three.vec);
    sfSprite_setPosition(options.back.sprite, options.back.vec);
    sfSprite_setPosition(options.op_one.sprite, options.op_one.vec);
    sfSprite_setPosition(options.op_two.sprite, options.op_two.vec);
    sfSprite_setPosition(options.op_three.sprite, options.op_three.vec);
    sfSprite_setPosition(options.no_sound.sprite, options.no_sound.vec);
    sfSprite_setPosition(options.sound.sprite, options.sound.vec);
}

void postion_option_check(menu_t *menu, op_menu_t opt, sfMouseButtonEvent mse)
{
    if (position_check(opt.one.vec, mse, 72, 112) == 1)
        menu[0].team_char = 1;
    if (position_check(opt.two.vec, mse, 72, 112) == 1)
        menu[0].team_char = 2;
    if (position_check(opt.three.vec, mse, 72, 112) == 1)
        menu[0].team_char = 3;
    if (position_check(opt.op_one.vec, mse, 72, 112) == 1)
        menu[0].team_opp = 1;
    if (position_check(opt.op_two.vec, mse, 72, 112) == 1)
        menu[0].team_opp = 2;
    if (position_check(opt.op_three.vec, mse, 72, 112) == 1)
        menu[0].team_opp = 3;
    if (position_check(opt.no_sound.vec, mse, 122, 96) == 1) {
        if (menu[0].sound == 0)
            menu[0].sound = 1;
        else if (menu[0].sound == 1)
            menu[0].sound = 0;
    }
}

void paralax_displa(play_t *character, opp_t *enemy, game_t map, menu_t *menu)
{
    sfText_setPosition(character[0].text_score, (sfVector2f) {map.x + 725,0});
    sfText_setString(character[0].text_score, my_nbr_str(character[0].score));
    sfRenderWindow_drawText(map.window, character[0].text_score, NULL);
    sfSprite_setPosition(character[0].sprite, character[0].vec);
    sfRenderWindow_drawSprite(map.window, character[0].sprite, NULL);
    sfRenderWindow_setView(map.window, map.view);
    enemy_hit(character, map, enemy, menu);
    sfRenderWindow_display(map.window);
}