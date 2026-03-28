/*
** EPITECH PROJECT, 2026
** G-PSU 200
** File description:
** MINISHELL1
*/

#include "my.h"

static int my_count_char(char **tab)
{
    int i = 0;
    int j = 0;
    int k = 0;

    while (tab[i] != NULL) {
        j = 0;
        while (tab[i][j] != '\0') {
            k++;
            j++;
        }
        if (tab[i + 1] != NULL)
            k++;
        i++;
    }
    return k + 1;
}

static void my_switch_variable(char **str, char **tab)
{
    int i = 0;
    int j = 0;
    int k = 0;

    while (tab[i] != NULL) {
        j = 0;
        while (tab[i][j] != '\0') {
            (*str)[k] = tab[i][j];
            k++;
            j++;
        }
        if (tab[i + 1] != NULL) {
            (*str)[k] = ' ';
            k++;
        }
        i++;
    }
    (*str)[k] = '\0';
}

char *my_word_array_to_str(char **tab)
{
    char *str = NULL;
    int len_tab = my_count_char(tab);

    str = malloc(len_tab);
    if (!str)
        return NULL;
    my_switch_variable(&str, tab);
    return str;
}
