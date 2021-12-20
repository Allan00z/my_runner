/*
** EPITECH PROJECT, 2021
** B-MUL-100-LYN-1-1-myrunner-allan.branco
** File description:
** my
*/

#ifndef MY_H_
    #define MY_H_
    #include <SFML/Graphics.h>
    #include <stdlib.h>
    #include <SFML/Window.h>
    #include <SFML/System/Time.h>
    #include <SFML/System/Time.h>
    #include <SFML/System/Types.h>

typedef struct player
{
    sfIntRect rect;
    sfSprite *sprite;
    sfVector2f vec;
    int speed;
    int is_jumping;
    int high_jump;
} play_t;

typedef struct object_game
{
    sfIntRect rect;
    sfSprite *sprite;
    sfVector2f vec;
    int speed;
} obj_t;

typedef struct game
{
    float seconds;
    sfRenderWindow* window;
    sfEvent event;
    sfColor sky;
    sfTexture *sprites;
    obj_t background;
    obj_t midground;
    obj_t foreground;
    sfClock *clock;
    sfTime time;
} game_t;

int my_strcmp(char const *s1, char const *s2);
int display_help(void);
obj_t init_rect(int x, int y, int height, int width);
obj_t init_object(void);
game_t map_init(game_t map, sfVideoMode mode);
game_t paralax_ground(game_t map);
game_t paralax_back(game_t map);
game_t paralax_mid(game_t map);
game_t paralax_map(game_t map, play_t *character);
play_t init_rect_player(int x, int y, int height, int width);
void *move_player(play_t *character);
void jump_character(play_t *character, game_t map);
void move_jump(play_t *character);
sfVector2f init_vect(int x, int y);
int my_strlen(char const *str);

#endif /* !MY_H_ */
