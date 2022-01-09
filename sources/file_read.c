/*
** EPITECH PROJECT, 2021
** B-MUL-100-LYN-1-1-myrunner-allan.branco
** File description:
** file_read
*/
#include "../my.h"

int lenght_reader(char *file)
{
    int fd = open(file, O_RDONLY);
    char *buffer = malloc(sizeof(char) * 11);
    int lenght;

    read(fd, buffer, 11);
    lenght = my_getnbr(buffer);
    close(fd);
    free(buffer);
    return (lenght);
}

int height_reader(char *file, int lenght)
{
    int fd = open(file, O_RDONLY);
    char *buffer = malloc(sizeof(char) * 11);
    int height;

    fd = open(file, O_RDONLY);
    read(fd, buffer, my_get_size_nbr(lenght) + 1);
    read(fd, buffer, 11);
    height = my_getnbr(buffer);
    close(fd);
    free(buffer);
    return (height);
}

char **file_read(char *file)
{
    int fd = open(file, O_RDONLY);
    int lenght = lenght_reader(file);
    int height = height_reader(file, lenght);
    char **level = malloc(sizeof(char *) * height);
    char *buffer = malloc(sizeof(char) * 11);

    level[0] = malloc(sizeof(char) * lenght);
    level[1] = malloc(sizeof(char) * lenght);
    read(fd, buffer, my_get_size_nbr(lenght) + 1);
    read(fd, buffer, my_get_size_nbr(height) + 1);
    for (int i = 0; buffer[0] != '\n'; i++)
        read(fd, buffer, 1);
    read(fd, level[0], lenght);
    read(fd, level[1], lenght);
    free(buffer);
    close(fd);
    return (level);
}

game_t level_generator(char **level, game_t map, opp_t *enemy, menu_t *menu)
{
    int nb = 0;

    map.x = 0;
    for (int i = 0; i < my_strlen(level[0]); i++) {
        if (level[0][i] == '2') {
            enemy[nb].rect.top = 341 + (65 * menu[0].team_opp);
            enemy[nb].vec.x = i * 40;
            sfSprite_setPosition(enemy[nb].sprite, enemy[nb].vec);
            nb += 1;
        }
        if (level[0][i] == '3') {
            map.finish.vec = init_vect(i * 40, 176);
            sfSprite_setPosition(map.finish.sprite, map.finish.vec);
        }
    }
    map.nb_enemy = nb;
    sound_jump(map, menu, 2);
    return (map);
}

void sound_jump(game_t map, menu_t *menu, int playing)
{
    if (menu[0].sound == 1 && playing == 0)
        sfSound_play(map.sound);
    if (menu[0].sound == 1 && playing == 1)
        sfSound_stop(map.sound);
    if (menu[0].sound == 1 && playing == 2)
        sfMusic_play(map.music);
    if (menu[0].sound == 1 && playing == 3)
        sfMusic_stop(map.music);
}