/*
** EPITECH PROJECT, 2026
** G-PSU 200
** File description:
** MINISHELL1
*/

#include "my.h"

static int check_status_builtins(int status, int *last_status, int *idx)
{
    if (status == -1) {
        *idx = 1;
        return 1;
    }
    if (status != 2) {
        *last_status = status;
        return 1;
    }
    return 0;
}

int is_invalid_pipeline(char *str)
{
    int i = 0;

    if (!str || str[0] == '|')
        return 1;
    while (str[i]) {
        if (str[i] == '|' && (str[i + 1] == '|'
                || str[i + 1] == '\0'))
            return 1;
        i++;
    }
    return 0;
}

static int loop_semicolons(char *str, char ***env, int *idx, int *last_status)
{
    int ret = 0;

    if (is_invalid_pipeline(str)) {
        my_dprintf(2, "Invalid null command.\n");
        *last_status = 1;
        return 1;
    }
    if (my_strchr(str, '|') == NULL) {
        ret = check_builtins(env, str);
        if (check_status_builtins(ret, last_status, idx))
            return 2;
    }
    *last_status = execute_pipeline(str, env);
    if (*last_status == 3)
        return 1;
    return 0;
}

int handle_semicolons(char *line, char ***env, int *last_status)
{
    char **segments = my_str_to_word_array(line, ";");
    int status = 0;
    int idx = 0;

    if (!segments)
        return 0;
    for (int i = 0; segments[i] != NULL; i++) {
        status = loop_semicolons(segments[i], env, &idx, last_status);
        if (status == 1) {
            my_freelist(segments);
            return 1;
        }
        if (status == 2)
            continue;
    }
    my_freelist(segments);
    if (idx == 1)
        return -1;
    return 0;
}
