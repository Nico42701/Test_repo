/*
** EPITECH PROJECT, 2026
** G-PSU 200
** File description:
** MINISHELL1
*/

#include "my.h"

int count_occurrences_words(char *str, char *target)
{
    int count = 0;
    char *ptr = str;
    int len = my_strlen(target);

    ptr = my_strstr(ptr, target);
    while (ptr != NULL) {
        count++;
        ptr += len;
        ptr = my_strstr(ptr, target);
    }
    return count;
}
