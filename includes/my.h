/*
** EPITECH PROJECT, 2026
** G-ING-200
** File description:
** my_world
*/

#ifndef MY_H_
    #define MY_H_

    #include <SFML/Graphics.h>
    #include <stdio.h>
    #include <unistd.h>
    #include <stdlib.h>
    #include <math.h>
    #include <string.h>

typedef struct graph_s {
    int length_max;
    float zoom;
    sfVector2f pos_view;
    float range;
    float world_angle;
    sfFont *font;
} graph_t;

typedef struct buttons_s {
    sfBool state_lower_raise;
    sfSprite *sprite_lower;
    sfTexture *texture_lower_off;
    sfTexture *texture_lower_on;
    sfSprite *sprite_raise;
    sfTexture *texture_raise_off;
    sfTexture *texture_raise_on;
    sfSprite *sprite_minus;
    sfTexture *texture_minus_off;
    sfTexture *texture_minus_on;
    sfSprite *sprite_more;
    sfTexture *texture_more_off;
    sfTexture *texture_more_on;
    sfText *range_text;
} buttons_t;

typedef struct click_s {
    graph_t *conf;
    int ***tab;
    sfVector2f **map;
    sfVector2f mouse;
    buttons_t buttons;
} click_t;

//   Project

void free_list(int ***tab);
int **init_map(graph_t *conf);
void free_2d_map(sfVector2f **map, graph_t *conf);
void free_2d_tab(int **tab, graph_t *conf);
int draw_2d_map(sfRenderWindow *window,
    sfVector2f **map, graph_t *conf, int **tab);
sfVertexArray *create_line(sfVector2f *point1, sfVector2f *point2, int z);
sfVector2f **create_2d_map(int **map_3d, graph_t *conf);
sfVector2f project_iso_point(int x, int y, int z, graph_t *conf);
void manage_events(sfRenderWindow *window, graph_t *conf, click_t *clicks);
void manage_click_on_map(sfRenderWindow *window, sfView *view, click_t *click);
void update_map(sfVector2f ***map_2d, graph_t *conf, int **tab, sfView **view);
int init_struct(graph_t *conf, sfRenderWindow **window, int ***tab,
    sfVector2f ***map_2d);
void load_click_struct(click_t *click, int ***tab, graph_t *conf,
    sfVector2f **map_2d);
int init_views(sfView **view, sfRenderWindow **window);
void clear_disp(sfRenderWindow *window, sfView *view);
void update_disp(sfRenderWindow *window, sfVector2f **map_2d, graph_t *conf,
    int **tab, click_t *clicks, sfView *world_view);
void managed_button(sfRenderWindow *window, click_t *clicks, sfEvent event);

//   LIB

char *my_itoa(int n);

#endif
