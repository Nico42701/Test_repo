/*
** EPITECH PROJECT, 2026
** G-ING-200
** File description:
** my_world
*/

#include "my.h"

void raise_button(sfRenderWindow *window, click_t *clicks, sfEvent event)
{
    sfVector2u size = sfTexture_getSize(clicks->buttons.texture_raise_on);
    sfVector2f pose = sfSprite_getPosition(clicks->buttons.sprite_raise);
    sfVector2i mouse_pixel = sfMouse_getPositionRenderWindow(window);
    sfVector2f mouse = sfRenderWindow_mapPixelToCoords(window, mouse_pixel, sfRenderWindow_getView(window));

    if (mouse.x >= pose.x && mouse.x <= pose.x + (size.x / 2)) {
        if (mouse.y >= pose.y && mouse.y <= pose.y + (size.y / 2)) {
            if (event.type == sfEvtMouseButtonPressed && clicks->buttons.state_lower_raise == -1)
                clicks->buttons.state_lower_raise = -clicks->buttons.state_lower_raise;
        }
    }
}

void lower_button(sfRenderWindow *window, click_t *clicks, sfEvent event)
{
    sfVector2u size = sfTexture_getSize(clicks->buttons.texture_lower_on);
    sfVector2f pose = sfSprite_getPosition(clicks->buttons.sprite_lower);
    sfVector2i mouse_pixel = sfMouse_getPositionRenderWindow(window);
    sfVector2f mouse = sfRenderWindow_mapPixelToCoords(window, mouse_pixel, sfRenderWindow_getView(window));

    if (mouse.x >= pose.x && mouse.x <= pose.x + (size.x / 2)) {
        if (mouse.y >= pose.y && mouse.y <= pose.y + (size.y / 2)) {
            if (event.type == sfEvtMouseButtonPressed && clicks->buttons.state_lower_raise == 1)
                clicks->buttons.state_lower_raise = -clicks->buttons.state_lower_raise;
        }
    }
}

void managed_button(sfRenderWindow *window, click_t *clicks, sfEvent event)
{
    raise_button(window, clicks, event);
    lower_button(window, clicks, event);
}