/*
** EPITECH PROJECT, 2026
** G-ING-200
** File description:
** my_world
*/

#include "my.h"

void clear_disp(sfRenderWindow *window, sfView *view)
{
    sfRenderWindow_setView(window, view);
    sfRenderWindow_clear(window, sfBlack);
}

void update_disp(sfRenderWindow *window, sfVector2f **map_2d, graph_t *conf,
    int **tab, click_t *clicks, sfView *world_view)
{
    const sfView *gui_view = sfRenderWindow_getDefaultView(window);
    char *range_txt = NULL;

    sfRenderWindow_clear(window, sfBlack);
    sfRenderWindow_setView(window, world_view);
    draw_2d_map(window, map_2d, conf, tab);
    sfRenderWindow_setView(window, gui_view);
    if (clicks->buttons.state_lower_raise == -1) {
        sfSprite_setTexture(clicks->buttons.sprite_lower,
            clicks->buttons.texture_lower_on, sfTrue);
        sfSprite_setTexture(clicks->buttons.sprite_raise,
            clicks->buttons.texture_raise_off, sfTrue);
    } else {
        sfSprite_setTexture(clicks->buttons.sprite_lower,
            clicks->buttons.texture_lower_off, sfTrue);
        sfSprite_setTexture(clicks->buttons.sprite_raise,
            clicks->buttons.texture_raise_on, sfTrue);
    }
    range_txt = malloc(strlen("Range : ") + strlen(my_itoa(conf->range)) + 1);
    strcpy(range_txt, "Range : ");
    strcat(range_txt, my_itoa(conf->range));
    sfText_setString(clicks->buttons.range_text, range_txt);
    sfText_setFont(clicks->buttons.range_text, conf->font);
    sfText_setCharacterSize(clicks->buttons.range_text, 30);
    sfText_setPosition(clicks->buttons.range_text, (sfVector2f){500, 20});
    sfRenderWindow_drawText(window, clicks->buttons.range_text, NULL);
    sfRenderWindow_drawSprite(window, clicks->buttons.sprite_lower, NULL);
    sfRenderWindow_drawSprite(window, clicks->buttons.sprite_raise, NULL);
    sfRenderWindow_display(window);
}
