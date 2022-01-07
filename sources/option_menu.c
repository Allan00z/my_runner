/*
** EPITECH PROJECT, 2022
** B-MUL-100-LYN-1-1-myrunner-allan.branco
** File description:
** option_menu
*/
#include "../my.h"

obj_t sound_menu_init(game_t map, int x)
{
    obj_t obj;

    obj.vec = init_vect(270, 420);
    obj.rect = init_rect(0 + x, 1800, 96, 122);
    obj.sprite = sfSprite_create();
    sfSprite_setTexture(obj.sprite, map.sprites, sfFalse);
    sfSprite_setTextureRect(obj.sprite, obj.rect);
    sfSprite_setPosition(obj.sprite, obj.vec);
    return (obj);
}

obj_t back_menu_init(game_t map)
{
    obj_t obj;

    obj.vec = init_vect(0, 0);
    obj.rect = init_rect(0, 1704, 89, 79);
    obj.sprite = sfSprite_create();
    sfSprite_setTexture(obj.sprite, map.sprites, sfFalse);
    sfSprite_setTextureRect(obj.sprite, obj.rect);
    sfSprite_setPosition(obj.sprite, obj.vec);
    sfRenderWindow_drawSprite(map.window, obj.sprite, NULL);
    return (obj);
}

void option_menu_display(game_t map, op_menu_t options, menu_t *menu)
{
    sfRenderWindow_clear(map.window, map.sky);
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
    sfRenderWindow_drawSprite(map.window, map.background.sprite, NULL);
    sfRenderWindow_drawSprite(map.window, map.foreground.sprite, NULL);
    sfRenderWindow_drawSprite(map.window, map.midground.sprite, NULL);
    sfRenderWindow_drawSprite(map.window, options.one.sprite, NULL);
    sfRenderWindow_drawSprite(map.window, options.two.sprite, NULL);
    sfRenderWindow_drawSprite(map.window, options.three.sprite, NULL);
    sfRenderWindow_drawSprite(map.window, options.back.sprite, NULL);
    sfRenderWindow_drawSprite(map.window, options.op_two.sprite, NULL);
    sfRenderWindow_drawSprite(map.window, options.op_three.sprite, NULL);
    sfRenderWindow_drawSprite(map.window, options.op_one.sprite, NULL);
    if (menu[0].sound == 0)
        sfRenderWindow_drawSprite(map.window, options.no_sound.sprite, NULL);
    else
        sfRenderWindow_drawSprite(map.window, options.sound.sprite, NULL);
}

op_menu_t option_press(op_menu_t options, game_t map, menu_t *menu)
{
    sfMouseButtonEvent mse;

    if (map.event.mouseButton.type != sfEvtMouseButtonPressed) {
        if (map.event.mouseButton.button != sfMouseLeft)
            return (options);
    }
    mse = map.event.mouseButton;
    if (position_check(options.one.vec, mse, 72, 112) == 1)
        menu[0].team_char = 1;
    if (position_check(options.two.vec, mse, 72, 112) == 1)
        menu[0].team_char = 2;
    if (position_check(options.three.vec, mse, 72, 112) == 1)
        menu[0].team_char = 3;
    if (position_check(options.op_one.vec, mse, 72, 112) == 1)
        menu[0].team_opp = 1;
    if (position_check(options.op_two.vec, mse, 72, 112) == 1)
        menu[0].team_opp = 2;
    if (position_check(options.op_three.vec, mse, 72, 112) == 1)
        menu[0].team_opp = 3;
    if (position_check(options.no_sound.vec, mse, 122, 96) == 1) {
        if (menu[0].sound == 0)
            menu[0].sound = 1;
        else if (menu[0].sound == 1)
            menu[0].sound = 0;
    }
    while (map.event.mouseButton.type != sfEvtMouseButtonReleased)
        sfRenderWindow_pollEvent(map.window, &map.event);
    options.back.press = position_check(options.back.vec, mse, 79, 89);
    return (options);
}

op_menu_t options_menu_init(game_t map, menu_t *menu)
{
    op_menu_t options;

    menu[0].is_menu = 2;
    options.one = object_menu_init(map, 406, 200, 100);
    options.two = object_menu_init(map, 471, 300, 100);
    options.three = object_menu_init(map, 536, 400, 100);
    options.op_one = object_menu_init(map, 406, 200, 300);
    options.op_two = object_menu_init(map, 471, 300, 300);
    options.op_three = object_menu_init(map, 536, 400, 300);
    options.sound = sound_menu_init(map, 0);
    options.no_sound = sound_menu_init(map, 145);
    options.back = back_menu_init(map);
    sfRenderWindow_drawSprite(map.window, options.sound.sprite, NULL);
    return (options);
}

void options_menu(menu_t *menu, game_t map, play_t *character)
{
    op_menu_t options = options_menu_init(map, menu);

    while (menu[0].is_menu == 2 && close_window(map.window, map.event) == 0) {
        option_menu_display(map, options, menu);
        while (sfRenderWindow_pollEvent(map.window, &map.event))
            options = option_press(options, map, menu);
        if (options.back.press == 1)
            menu[0].is_menu = 1;
        sfRenderWindow_display(map.window);
    }
    if (sfRenderWindow_isOpen(map. window) == sfTrue) {
        while (map.event.mouseButton.type != sfEvtMouseButtonReleased)
            sfRenderWindow_pollEvent(map.window, &map.event);
    }
    options = destroyer_option(options, menu);
    character[0].rect.top = 341 + (65 * menu[0].team_char);
}