/*
** EPITECH PROJECT, 2021
** B-MUL-100-LYN-1-1-myrunner-allan.branco
** File description:
** victory_or_defeat
*/
#include "../my.h"

game_t victory_end(game_t map, play_t *character, menu_t *menu)
{
    map.text = sfText_create();
    map.score = sfText_create();
    map.sco = sfText_create();
    map.high_score = sfText_create();
    map = display_score(map, character, 1);
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

game_t ground_move(game_t map)
{
    if (map.x + 800 <= map.finish.vec.x)
        map = paralax_ground(map);
    else {
        if (map.foreground.vec.x <= -723 + map.x)
            map.foreground.vec.x = 0 + map.x;
        if (map.foreground.vec.x > -723 + map.x) {
            sfSprite_setPosition(map.foreground.sprite, map.foreground.vec);
            sfRenderWindow_drawSprite(map.window, map.foreground.sprite, NULL);
            map.foreground.vec.x += 723;
            sfSprite_setPosition(map.foreground.sprite, map.foreground.vec);
            sfRenderWindow_drawSprite(map.window, map.foreground.sprite, NULL);
            map.foreground.vec.x -= 723;
        }
        sfSprite_setPosition(map.foreground.sprite, map.foreground.vec);
        sfRenderWindow_drawSprite(map.window, map.foreground.sprite, NULL);
    }
    return (map);
}

int enemy_hit(play_t *character, game_t map, opp_t *enemy, menu_t *menu)
{
    float x = character[0].vec.x + character[0].rect.width + 4;
    float y_max = character[0].vec.y + character[0].rect.height;

    for (int i = 0; i < map.nb_enemy; i++) {
        if (x <= enemy[i].vec.x && x >= enemy[i].vec.x - 70 &&
        y_max >= enemy[i].vec.y) {
            menu[0].is_playing = 0;
            map = display_defeat(map, character, menu);
        }
    }
    return (0);
}

void high_score_write(char *file, play_t *character)
{
    int fd = open(file, O_RDWR);
    char *high = malloc(sizeof(char) * 12);

    fd = open("highscore.txt", O_RDWR);
    high = my_nbr_str(character[0].high_score);
    write(fd, high, my_get_size_nbr(character[0].high_score));
    close(fd);
    free(high);
}

game_t sound_init(game_t map)
{
    map.music = sfMusic_createFromFile("sprite/stade.ogg");
    map.buffer = sfSoundBuffer_createFromFile("sprite/jump.ogg");
    map.sound = sfSound_create();
    sfSound_setBuffer(map.sound, map.buffer);
    return (map);
}