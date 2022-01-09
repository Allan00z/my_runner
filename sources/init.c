/*
** EPITECH PROJECT, 2021
** B-MUL-100-LYN-1-1-myrunner-allan.branco
** File description:
** init
*/
#include "../my.h"

game_t map_init(game_t map, sfRenderWindow *window, char *file)
{
    map.sky.r = 120;
    map.sky.g = 220;
    map.sky.b = 252;
    map.sky.a = 0;
    map.nb_enemy = 0;
    map.sprites = sfTexture_createFromFile("sprite/sprites.png", NULL);
    map.window = window;
    sfRenderWindow_setFramerateLimit(map.window, 60);
    map = objects_init(map);
    map.view = sfView_createFromRect((sfFloatRect) {0, 0, 800, 600});
    map.clock = sfClock_create();
    sfRenderWindow_setMouseCursorVisible(map.window, sfTrue);
    map.is_finish = 0;
    map.font = sfFont_createFromFile("sprite/Minecraft.ttf");
    map.file = file;
    map = sound_init(map);
    map.nb = 0;
    return (map);
}

play_t *player_init(game_t map, char *file)
{
    play_t *character = malloc(sizeof(play_t));
    char *buffer = malloc(sizeof(char) * 12);
    int fd = open("highscore.txt", O_RDWR);

    character[0] = init_rect_player(0, 406, 64, 41);
    character[0].vec = init_vect(5, 400);
    character = character_jump_init(character);
    sfSprite_setTexture(character[0].sprite, map.sprites, sfFalse);
    sfSprite_setTextureRect(character[0].sprite, character[0].rect);
    sfSprite_scale(character[0].sprite, (sfVector2f) {2, 2});
    character[0].run_clock = sfClock_create();
    read(fd, buffer, 12);
    character[0].high_score = my_getnbr(buffer);
    character[0].text_score = sfText_create();
    sfText_setScale(character[0].text_score, (sfVector2f) {2, 2});
    sfText_setPosition(character[0].text_score, (sfVector2f) {725,0});
    sfText_setFont(character[0].text_score, map.font);
    sfText_setColor(character[0].text_score, sfRed);
    close(fd);
    return (character);
}

opp_t *oppenent_init(game_t map, char **level)
{
    opp_t *enemy;

    for (int i = 0; i < my_strlen(level[0]); i++) {
        if (level[0][i] == '2')
            map.nb_enemy += 1;
    }
    enemy = malloc(sizeof(opp_t) * map.nb_enemy - 1);
    for (int i = 0; i < map.nb_enemy; i++) {
        enemy[i].character = '2';
        enemy[i].rect = init_rect(0, 471, 64, 41);
        enemy[i].sprite = sfSprite_create();
        enemy[i].vec = init_vect(850, 400);
        sfSprite_setTexture(enemy[i].sprite, map.sprites, sfFalse);
        sfSprite_setTextureRect(enemy[i].sprite, enemy[i].rect);
        sfSprite_scale(enemy[i].sprite, (sfVector2f) {-2, 2});
        enemy[i].opp_clock = sfClock_create();
    }
    return (enemy);
}

obj_t start_init(game_t map)
{
    obj_t object;

    object.rect = init_rect(0, 698, 128, 256);
    object.vec = init_vect(250, 75);
    object.sprite = sfSprite_create();
    object.press = 0;
    sfSprite_setTexture(object.sprite, map.sprites, sfFalse);
    sfSprite_setTextureRect(object.sprite, object.rect);
    sfSprite_setPosition(object.sprite, object.vec);
    sfRenderWindow_drawSprite(map.window, object.sprite, NULL);
    return (object);
}

obj_t exit_init(game_t map)
{
    obj_t object;

    object.press = 0;
    object.rect = init_rect(0, 980, 128, 256);
    object.vec = init_vect(250, 375);
    object.sprite = sfSprite_create();
    sfSprite_setTexture(object.sprite, map.sprites, sfFalse);
    sfSprite_setTextureRect(object.sprite, object.rect);
    sfSprite_setPosition(object.sprite, object.vec);
    sfRenderWindow_drawSprite(map.window, object.sprite, NULL);
    return (object);
}
