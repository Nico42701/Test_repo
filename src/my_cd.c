/*
** EPITECH PROJECT, 2026
** G-PSU 200
** File description:
** MINISHELL1
*/

#include "my.h"

static int is_folder(char *folder)
{
    struct stat st = {0};

    if (my_strcmp(folder, "-") == 0 ||
        my_strcmp(folder, "~") == 0)
        return 1;
    if (stat(folder, &st) == -1)
        return -1;
    if (S_ISDIR(st.st_mode)) {
        if (access(folder, X_OK) == 0)
            return 0;
        return -3;
    }
    return -2;
}

static void update_folder(char ***env, char *new_folder, char *old_folder)
{
    char *current_cwd = NULL;

    if (chdir(new_folder) == -1)
        return;
    my_form_setenv(env, "OLDPWD", old_folder);
    current_cwd = getcwd(NULL, 0);
    if (current_cwd != NULL) {
        my_form_setenv(env, "PWD", current_cwd);
        free(current_cwd);
    }
}

void update_arg_folder(char ***env, char *raw_new, char *raw_old)
{
    char *current_dir = my_strdup(raw_new);
    char *old_folder = (raw_old != NULL) ? my_strdup(raw_old) : my_strdup("");

    update_folder(env, current_dir, old_folder);
    free(current_dir);
    free(old_folder);
}

void update_home_folder(char ***env)
{
    char *old_folder = getcwd(NULL, 0);
    char *current_dir = my_getenv(env, "HOME");

    if (old_folder != NULL)
        update_folder(env, current_dir, old_folder);
    free(old_folder);
}

int exec_update(char ***env)
{
    char *raw_new = my_getenv(env, "OLDPWD");
    char *raw_old = my_getenv(env, "PWD");

    if (raw_new == NULL)
        return put_error();
    update_arg_folder(env, raw_new, raw_old);
    return 0;
}

int check_argument(char ***env, int res, char **data)
{
    char *old_folder = NULL;

    if (my_strcmp(data[1], "-") == 0) {
        if (exec_update(env) == 84)
            return 84;
        return 0;
    }
    if (my_strcmp(data[1], "~") == 0 && my_getenv(env, "HOME") != NULL) {
        update_home_folder(env);
        return 0;
    }
    if ((*env)[0] != NULL)
        old_folder = my_getenv(env, "PWD");
    if (check_error_value(res, env, data) == 84)
        return 84;
    update_folder(env, data[1], old_folder);
    return 0;
}

static int check_home_folder(int c_word, char ***env, char ***data)
{
    if (c_word == 1) {
        my_freelist(*data);
        update_home_folder(env);
        return 1;
    }
    return 0;
}

static int check_error_arg(char ***env, int res, char ***data)
{
    int res_argument = check_argument(env, res, *data);

    my_freelist(*data);
    if (res_argument == 0)
        return 0;
    if (res_argument == 84)
        return 1;
    return 2;
}

int my_cd(char ***env, char *line)
{
    int c_word = my_count_words(line, " \t");
    char **data = my_str_to_word_array(line, " \t");
    int res_argument = 2;
    int res = (c_word > 1) ? is_folder(data[1]) : 0;

    if (check_error(env, c_word, data, res) == 1) {
        my_freelist(data);
        return 1;
    }
    if (check_home_folder(c_word, env, &data) == 1)
        return 0;
    if (c_word == 2)
        res_argument = check_error_arg(env, res, &data);
    return (res_argument == 2) ? 0 : res_argument;
}
