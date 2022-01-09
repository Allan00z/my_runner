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
    #include <SFML/Audio/Music.h>
    #include <SFML/Audio/Sound.h>
    #include <SFML/Audio.h>
    #include <sys/types.h>
    #include <sys/stat.h>
    #include <fcntl.h>
    #include <unistd.h>
    #include <stdio.h>

typedef struct object_game {
    sfIntRect rect;
    sfSprite *sprite;
    sfVector2f vec;
    int speed;
    int press;
} obj_t;

typedef struct main_menu {
    obj_t start;
    obj_t options;
    obj_t exit;
    int is_playing;
    obj_t menu;
    int is_menu;
    int team_char;
    int team_opp;
    int sound;
} menu_t;

typedef struct option_menu {
    obj_t one;
    obj_t two;
    obj_t three;
    obj_t four;
    obj_t op_one;
    obj_t op_two;
    obj_t op_three;
    obj_t back;
    obj_t sound;
    obj_t no_sound;
} op_menu_t;

typedef struct oppenent {
    sfIntRect rect;
    sfSprite *sprite;
    sfVector2f vec;
    int speed;
    sfClock *opp_clock;
    float opp_seconds;
    sfTime time;
    char character;
    int team;
} opp_t;

typedef struct player {
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
    int team;
    int score;
    int high_score;
    sfText *text_score;
} play_t;

typedef struct game {
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
    char *file;
    sfMusic *music;
    sfSound *sound;
    sfSoundBuffer *buffer;
    int nb;
    sfText *score;
    sfText *sco;
    sfText *high_score;
} game_t;

int my_getnbr(char const *str);
int my_strcmp(char const *s1, char const *s2);
int display_help(void);
int my_strlen(char const *str);
int main_menu_display(menu_t *menu, game_t map, int x, play_t *character);
int position_check(sfVector2f vector, sfMouseButtonEvent mouse, int x, int y);
int close_window(sfRenderWindow* window, sfEvent event);
int my_get_size_nbr(int nbr);
int runner_main(char *file, sfRenderWindow *window);
int check_args(int argc, char **argv);
int lenght_reader(char *file);
int press_menu(menu_t *menu, game_t map, play_t *character);
int enemy_hit(play_t *character, game_t map, opp_t *enemy, menu_t *menu);
int end_pressed(sfMouseButtonEvent mse, game_t map);
int menu_start_press(menu_t *menu);
int destroyer(game_t map, play_t *character, opp_t *enemy, menu_t *menu);

sfIntRect init_rect(int x, int y, int height, int width);

obj_t init_object(void);
obj_t start_init(game_t map);
obj_t exit_init(game_t map);
obj_t menu_init(game_t map);
obj_t options_init(game_t map);
obj_t object_menu_init(game_t map, int height, int x, int y);

game_t sound_init(game_t map);
game_t ground_move(game_t map);
game_t level_generator(char **level, game_t map, opp_t *enemy, menu_t *menu);
game_t map_init(game_t map, sfRenderWindow *window, char *file);
game_t paralax_ground(game_t map);
game_t paralax_back(game_t map);
game_t paralax_mid(game_t map);
game_t move_run(play_t *character, game_t map);
game_t paralax_map(game_t map, play_t *character, opp_t *enemy, menu_t *menu);
game_t objects_init(game_t map);
game_t display_finish(game_t map, play_t *character, menu_t *menu);
game_t victory_end(game_t map, play_t *character, menu_t *menu);
game_t display_defeat(game_t map, play_t *character, menu_t *menu);
game_t defeat_end(game_t map, play_t *character, menu_t *menu);
game_t display_score(game_t map, play_t *character, int i);

play_t init_rect_player(int x, int y, int height, int width);
play_t *player_init(game_t map, char *file);
play_t *character_jump_init(play_t *character);

op_menu_t destroyer_option(op_menu_t options, menu_t *menu);
op_menu_t options_menu_init(game_t map, menu_t *menu);
op_menu_t option_press(op_menu_t options, game_t map, menu_t *menu);

opp_t *oppenent_init(game_t map, char **level);

void sound_jump(game_t map, menu_t *menu, int playing);
void *move_opponent(opp_t *enemy, int i);
void *move_player(play_t *character);
void jump_character(play_t *character, menu_t *menu, game_t map);
void move_jump(play_t *character, game_t map, menu_t *menu, char *file);
void display_sprite_menu(game_t map, menu_t *menu, int x);
void fall_jump(play_t *character, game_t map, menu_t *menu);
void set_sprite(sfSprite *sprite, sfVector2f vec, sfRenderWindow *wind, int x);
void free_all(opp_t *enemy, play_t *character, char **level);
void options_menu(menu_t *menu, game_t map, play_t *character);
void high_score_write(char *file, play_t *character);
void character_init(play_t *character);
void get_pressed(menu_t *menu, game_t map, int x);
void set_position_option(game_t map, op_menu_t options, menu_t *menu);
void postion_option_check(menu_t *menu, op_menu_t opt, sfMouseButtonEvent mse);
void paralax_displa(play_t *character, opp_t *enemy, game_t map, menu_t *menu);
void option_menu_display(game_t map, op_menu_t options, menu_t *menu);

menu_t *main_menu_init(game_t map);

sfVector2f init_vect(int x, int y);

char *my_nbr_str(int nb);

char **file_read(char *file);

#endif /* !MY_H_ */
