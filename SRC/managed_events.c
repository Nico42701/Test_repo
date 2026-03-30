/*
** EPITECH PROJECT, 2026
** G-ING-200
** File description:
** my_world
*/

#include "my.h"

static void handle_zoom(graph_t *conf, float delta)
{
    if (delta > 0)
        conf->zoom *= 0.97f;
    else
        conf->zoom *= 1.03f;
}

static void handle_key(sfKeyCode code, click_t *clicks)
{
    if (code == sfKeySpace)
        clicks->buttons.state_lower_raise = -clicks->buttons.state_lower_raise;
}

static void handle_game_events(sfEvent *event, graph_t *conf, click_t *clicks)
{
    if (event->type == sfEvtKeyPressed)
        handle_key(event->key.code, clicks);
    if (event->type == sfEvtMouseWheelScrolled)
        handle_zoom(conf, event->mouseWheelScroll.delta);
}

static void handle_event(sfRenderWindow *window,
    sfEvent *event, graph_t *conf, click_t *clicks)
{
    if (event->type == sfEvtClosed)
        sfRenderWindow_close(window);
    if (event->type != sfEvtClosed)
        handle_game_events(event, conf, clicks);
}

static void manage_direct_keyboard(graph_t *conf)
{
    if (sfKeyboard_isKeyPressed(sfKeyRight))
        conf->pos_view.x += 10;
    if (sfKeyboard_isKeyPressed(sfKeyLeft))
        conf->pos_view.x -= 10;
    if (sfKeyboard_isKeyPressed(sfKeyDown))
        conf->pos_view.y += 10;
    if (sfKeyboard_isKeyPressed(sfKeyUp))
        conf->pos_view.y -= 10;
    if (sfKeyboard_isKeyPressed(sfKeyA))
        conf->world_angle -= 0.02f;
    if (sfKeyboard_isKeyPressed(sfKeyE))
        conf->world_angle += 0.02f;
    if (sfKeyboard_isKeyPressed(sfKeyP))
        conf->range += 10.0f;
    if (sfKeyboard_isKeyPressed(sfKeyM) && conf->range > 0)
        conf->range -= 10.0f;
}

void manage_events(sfRenderWindow *window, graph_t *conf, click_t *clicks)
{
    sfEvent event = {0};

    manage_direct_keyboard(conf);
    while (sfRenderWindow_pollEvent(window, &event)) {
        handle_event(window, &event, conf, clicks);
        managed_button(window, clicks, event);
    }
}
