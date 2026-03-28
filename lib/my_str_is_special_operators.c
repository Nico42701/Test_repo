/*
** EPITECH PROJECT, 2026
** LIB
** File description:
** my_str_is_special_operators
*/

#include "my.h"

int my_str_is_special_operators(char *str)
{
    if (my_strcmp(str, "<") == 0 || my_strcmp(str, ">") == 0 ||
        my_strcmp(str, ">>") == 0 || my_strcmp(str, "<<") == 0 ||
        my_strcmp(str, "|") == 0 || my_strcmp(str, ";") == 0)
        return 1;
    return 0;
}
