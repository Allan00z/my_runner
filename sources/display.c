/*
** EPITECH PROJECT, 2022
** B-MUL-100-LYN-1-1-myrunner-allan.branco
** File description:
** display
*/
#include "../my.h"
game_t display_finish(game_t map, play_t *character, menu_t *menu)
{
    sound_jump(map, menu, 3);
    while (menu[0].is_menu == 0 && close_window(map.window, map.event) == 0) {
        sfRenderWindow_clear(map.window, map.sky);
        menu[0].is_playing = 0;
        set_sprite(map.background.sprite, map.background.vec, map.window, 3840);
        set_sprite(map.foreground.sprite, map.foreground.vec, map.window, 723);
        set_sprite(map.midground.sprite, map.midground.vec, map.window, 1232);
        map = victory_end(map, character, menu);
        sfRenderWindow_pollEvent(map.window, &map.event);
        menu[0].is_menu = end_pressed(map.event.mouseButton, map);
        sfRenderWindow_display(map.window);
    }
    if (sfRenderWindow_isOpen(map. window) == sfTrue) {
        while (map.event.mouseButton.type != sfEvtMouseButtonReleased)
            sfRenderWindow_pollEvent(map.window, &map.event);
    }
    return (map);
}

game_t display_defeat(game_t map, play_t *character, menu_t *menu)
{
    while (menu[0].is_menu == 0 && close_window(map.window, map.event) == 0) {
        sfRenderWindow_clear(map.window, map.sky);
        menu[0].is_playing = 0;
        set_sprite(map.background.sprite, map.background.vec, map.window, 3840);
        set_sprite(map.foreground.sprite, map.foreground.vec, map.window, 723);
        set_sprite(map.midground.sprite, map.midground.vec, map.window, 1232);
        map = defeat_end(map, character, menu);
        sfRenderWindow_pollEvent(map.window, &map.event);
        menu[0].is_menu = end_pressed(map.event.mouseButton, map);
        sfRenderWindow_display(map.window);
    }
    if (sfRenderWindow_isOpen(map. window) == sfTrue) {
        while (map.event.mouseButton.type != sfEvtMouseButtonReleased)
            sfRenderWindow_pollEvent(map.window, &map.event);
    }
    return (map);
}

game_t display_score(game_t map, play_t *character)
{
    sfText_setFont(map.text, map.font);
    sfText_setFont(map.score, map.font);
    sfText_setString(map.score, "SCORE : \nHIGHSCORE :");
    sfText_setString(map.text, "DEFEAT");
    sfText_setFont(map.sco, map.font);
    sfText_setString(map.sco, my_nbr_str(character[0].score));
    sfText_setPosition(map.sco, (sfVector2f) {map.x + 400, 375});
    sfText_setFillColor(map.sco, sfWhite);
    sfText_setCharacterSize(map.sco, 64);
    sfRenderWindow_drawText(map.window, map.sco, sfFalse);
    sfText_setFont(map.high_score, map.font);
    sfText_setString(map.high_score, my_nbr_str(character[0].high_score));
    sfText_setPosition(map.high_score, (sfVector2f) {map.x + 550, 450});
    sfText_setFillColor(map.high_score, sfWhite);
    sfText_setCharacterSize(map.high_score, 64);
    sfText_setPosition(map.text, (sfVector2f) {map.x + 200, 100});
    sfText_setPosition(map.score, (sfVector2f) {map.x + 100, 375});
    return (map);
}

game_t defeat_end(game_t map, play_t *character, menu_t *menu)
{
    map.text = sfText_create();
    map.high_score = sfText_create();
    map.score = sfText_create();
    map.sco = sfText_create();
    display_score(map, character);
    sfText_setFillColor(map.text, sfRed);
    sfText_setFillColor(map.score, sfWhite);
    sfText_setCharacterSize(map.text, 64);
    sfText_setCharacterSize(map.score, 64);
    sfText_setScale(map.text, (sfVector2f) {1.5, 1.5});
    sfRenderWindow_drawText(map.window, map.score, sfFalse);
    sfRenderWindow_drawText(map.window, map.text, sfFalse);
    sfSprite_setPosition(menu[0].menu.sprite, (sfVector2f) {map.x + 275, 250});
    sfRenderWindow_drawSprite(map.window, menu[0].menu.sprite, NULL);
    sfRenderWindow_drawText(map.window, map.high_score, sfFalse);
    sfText_destroy(map.text);
    sfText_destroy(map.score);
    sfText_destroy(map.sco);
    sfText_destroy(map.high_score);
    return (map);
}