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
    #include <sys/types.h>
    #include <sys/stat.h>
    #include <fcntl.h>
    #include <unistd.h>
    #include <stdio.h>

typedef struct object_game
{
    sfIntRect rect;
    sfSprite *sprite;
    sfVector2f vec;
    int speed;
    int press;
} obj_t;

typedef struct main_menu
{
    obj_t start;
    obj_t exit;
    int is_playing;
} menu_t;

typedef struct oppenent
{
    sfIntRect rect;
    sfSprite *sprite;
    sfVector2f vec;
    int speed;
    sfClock *opp_clock;
    float opp_seconds;
    sfTime time;
    char character;
} opp_t;

typedef struct player
{
    float seconds;
    sfIntRect rect;
    sfSprite *sprite;
    sfVector2f vec;
    int speed;
    int is_jumping;
    float high_jump;
    sfTime time;
    sfClock *jump_clock;
    sfClock *run_clock;
} play_t;

typedef struct game
{
    sfView *view;
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
    int nb_enemy;
    int x;
    obj_t finish;
    int is_finish;
    sfText *text;
    sfFont *font;
} game_t;

int my_getnbr(char const *str);
int my_strcmp(char const *s1, char const *s2);
int display_help(void);
int my_strlen(char const *str);
int main_menu_display(menu_t *menu, game_t map);
int position_check(sfVector2f vector, sfMouseButtonEvent mouse, int x, int y);
int close_window(sfRenderWindow* window, sfEvent event);
int my_get_size_nbr(int nbr);
int level_generator(char **level, game_t map, opp_t *enemy);
int runner_main(char *file);
int check_args(int argc, char **argv);
int lenght_reader(char *file);

sfIntRect init_rect(int x, int y, int height, int width);

obj_t init_object(void);
obj_t start_init(game_t map);
obj_t exit_init(game_t map);

game_t map_init(game_t map, sfVideoMode mode);
game_t paralax_ground(game_t map);
game_t paralax_back(game_t map);
game_t paralax_mid(game_t map);
game_t move_run(play_t *character, game_t map);
game_t paralax_map(game_t map, play_t *character, opp_t *enemy, char *file);
game_t objects_init(game_t map);
game_t display_finish(game_t map, play_t *character);
game_t victory_end(game_t map, play_t *character);

play_t init_rect_player(int x, int y, int height, int width);
play_t *player_init(game_t map);

opp_t *oppenent_init(game_t map, char **level);

void *move_opponent(opp_t *enemy, int i);
void *move_player(play_t *character);
void jump_character(play_t *character, game_t map);
void move_jump(play_t *character, game_t map, char *file);
void destroyer(game_t map, play_t *character, opp_t *enemy, menu_t *menu);
void display_sprite_menu(game_t map, menu_t *menu);
void fall_jump(play_t *character);

menu_t *main_menu_init(game_t map);

sfVector2f init_vect(int x, int y);

char **file_read(char *file);

#endif /* !MY_H_ */
