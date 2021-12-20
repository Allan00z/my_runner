/*
** EPITECH PROJECT, 2021
** B-MUL-100-LYN-1-1-myrunner-allan.branco
** File description:
** window
*/
#include "../my.h"

void close_window(sfRenderWindow* window, sfEvent event)
{
    if (event.type == sfEvtClosed)
        sfRenderWindow_close(window);
}

game_t map_init(game_t map, sfVideoMode mode)
{
    map.sky.r = 120;
    map.sky.g = 220;
    map.sky.b = 252;
    map.sky.a = 1;
    map.sprites = sfTexture_createFromFile("sprite/sprites.png", NULL);
    map.window = sfRenderWindow_create(mode, "Goal Hero", sfClose, NULL);
    map.foreground = init_rect(0, 1889, 271, 800);
    map.foreground.vec = init_vect(0, 329);
    map.background = init_rect(0, 0 , 101, 3840);
    map.background.vec = init_vect(0, 0);
    map.midground = init_rect(0, 131, 270, 1232);
    map.midground.vec = init_vect(0, 80);
    sfSprite_setTexture(map.foreground.sprite, map.sprites, sfFalse);
    sfSprite_setTexture(map.background.sprite, map.sprites, sfFalse);
    sfSprite_setTexture(map.midground.sprite, map.sprites, sfFalse);
    sfSprite_setTextureRect(map.midground.sprite, map.midground.rect);
    sfSprite_setTextureRect(map.background.sprite, map.background.rect);
    sfSprite_setTextureRect(map.foreground.sprite, map.foreground.rect);
    map.clock = sfClock_create();
    return (map);
}

play_t *player_init(game_t map)
{
    play_t *charac = malloc(sizeof(play_t));

    charac[0] = init_rect_player(0, 406, 64, 41);
    charac[0].vec = init_vect(0, 400);
    charac[0].is_jumping = 0;
    sfSprite_setTexture(charac[0].sprite, map.sprites, sfFalse);
    sfSprite_setTextureRect(charac[0].sprite, charac[0].rect);
    sfSprite_scale(charac[0].sprite, (sfVector2f) {2, 2});
    sfRenderWindow_setFramerateLimit(map.window, 60);

    return (charac);
}

int runner_main(void)
{
    game_t map;
    sfVideoMode mode = {800, 600, 32};
    play_t *character = malloc(sizeof(play_t));

    map = map_init(map, mode);
    character = player_init(map);
    while (sfRenderWindow_isOpen(map.window)) {
        sfRenderWindow_clear(map.window, map.sky);
        while (sfRenderWindow_pollEvent(map.window, &map.event)) {
            jump_character(character, map);
            close_window(map.window, map.event);
        }
        map = paralax_map(map, character);
        move_jump(character);
        sfRenderWindow_display(map.window);
    }
    sfSprite_destroy(map.background.sprite);
    sfSprite_destroy(map.midground.sprite);
    sfSprite_destroy(character[0].sprite);
    sfSprite_destroy(map.foreground.sprite);
    sfTexture_destroy(map.sprites);
    sfRenderWindow_destroy(map.window);
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