/*
** EPITECH PROJECT, 2026
** G-PSU 200
** File description:
** MINISHELL1
*/

#include "my.h"

static void concatenate_string(char *res, const char *name, const char *value)
{
    my_strcpy(res, name);
    my_strcat(res, "=");
    if (value)
        my_strcat(res, value);
}

static int end_setenv(setenv_t *senv, char ***env, const char *name,
    const char *value)
{
    int j = 0;

    senv->new_env = malloc(sizeof(char *) * (senv->idx + 2));
    if (!senv->new_env)
        return -1;
    for (j = 0; j < senv->idx; j++)
        senv->new_env[j] = (*env)[j];
    if (!value)
        senv->new_env[senv->idx] = malloc(senv->name_len + 2);
    else
        senv->new_env[senv->idx] = malloc(senv->name_len +
            my_strlen(value) + 2);
    if (!senv->new_env[senv->idx])
        return -1;
    concatenate_string(senv->new_env[senv->idx], name, value);
    senv->new_env[senv->idx + 1] = NULL;
    return 0;
}

static int overwrite_loop(setenv_t *senv, char ***env, const char *name,
    const char *value)
{
    if (!value)
        senv->new_line = malloc(senv->name_len + 2);
    else
        senv->new_line = malloc(senv->name_len + my_strlen(value) + 2);
    if (!senv->new_line)
        return -1;
    concatenate_string(senv->new_line, name, value);
    free((*env)[senv->idx]);
    (*env)[senv->idx] = senv->new_line;
    return 1;
}

static int main_loop(setenv_t *senv, char ***env, const char *name,
    const char *value)
{
    if (my_strncmp((*env)[senv->idx], name, senv->name_len) == 0 &&
        (*env)[senv->idx][senv->name_len] == '=') {
        if (overwrite_loop(senv, env, name, value) == -1)
            return -1;
        return 1;
    }
    return 0;
}

static void set_senv(setenv_t *senv, const char *name)
{
    senv->idx = 0;
    senv->name_len = my_strlen(name);
    senv->new_env = NULL;
    senv->new_line = NULL;
}

int my_exec_setenv(char ***env, const char *name, const char *value)
{
    setenv_t senv = {0};
    int status = 0;
    char **old_table = *env;

    set_senv(&senv, name);
    while ((*env)[senv.idx] != NULL) {
        status = main_loop(&senv, env, name, value);
        if (status == 1)
            return 0;
        senv.idx++;
    }
    if (end_setenv(&senv, env, name, value) == -1)
        return -1;
    *env = senv.new_env;
    free(old_table);
    return 0;
}
