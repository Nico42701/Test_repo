/*
** EPITECH PROJECT, 2026
** G-PSU 200
** File description:
** MINISHELL1
*/

#include "my.h"

int update_path(char **copy, char **env_line, char **path, char *line)
{
    char **data = NULL;

    *copy = my_strdup(*env_line);
    if (!copy)
        return 84;
    data = my_str_to_word_array(*copy, ":");
    if (!data)
        return 84;
    *path = my_getpath(data, line);
    if (!*path)
        *path = my_strdup(line);
    my_freelist(data);
    return 0;
}

int check_file_exist(char ***tmp, char *line,
    char **path, char ***env)
{
    char *copy = NULL;
    char *env_line = NULL;

    if (my_strchr((*tmp)[0], '/') == NULL) {
        my_freelist(*tmp);
        env_line = my_getenv(env, "PATH");
        if (env_line == NULL) {
            *path = my_strdup(line);
            return 84;
        }
        if (update_path(&copy, &env_line, path, line) == 84)
            return 84;
    } else {
        my_freelist(*tmp);
        *path = my_strdup(line);
    }
    free(copy);
    return 0;
}
