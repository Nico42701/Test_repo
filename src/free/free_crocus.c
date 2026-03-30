/*
** EPITECH PROJECT, 2026
** crocus
** File description:
** crocus
*/

#include "crocus.h"

void free_crocus(crocus_t *cr)
{
    if (cr->number)
        free(cr->number);
    if (cr->to_fill)
        free(cr->to_fill);
}
