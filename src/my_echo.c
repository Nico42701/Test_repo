/*
** EPITECH PROJECT, 2026
** G-PSU 200
** File description:
** MINISHELL1
*/

#include "my.h"

static int check_status_exist(char **line, int last_status)
{
    char *str_status = NULL;
    char *old_line = NULL;

    str_status = my_itoa(last_status);
    old_line = *line;
    *line = my_str_replace(*line, "$?", str_status);
    free(old_line);
    free(str_status);
    return 0;
}

int my_echo(char *line, int last_status)
{
    char **data = NULL;
    int i = 1;
    char *new_line = my_strdup(line);

    check_status_exist(&new_line, last_status);
    data = my_str_to_word_array(new_line, " ");
    while (data[i]) {
        my_dprintf(1, "%s", data[i]);
        if (data[i + 1])
            my_putchar(' ');
        i++;
    }
    my_putchar('\n');
    my_freelist(data);
    free(new_line);
    return 0;
}
