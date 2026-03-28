/*
** EPITECH PROJECT, 2026
** G-PSU 200
** File description:
** MINISHELL1
*/

#include "my.h"

static void sigint_handler(int sig)
{
    (void)sig;
    if (isatty(0) != 1)
        exit(0);
}

static void put_txt(void)
{
    if (isatty(0) == 1)
        my_dprintf(1, "$> ");
}

static void init_env(char ***env)
{
    char *old_folder = NULL;

    if (my_getenv(env, "PWD") == NULL) {
        old_folder = getcwd(NULL, 0);
        my_exec_setenv(env, "PWD", old_folder);
        free(old_folder);
    }
    signal(SIGINT, sigint_handler);
}

int my_sh(char **env)
{
    char **my_env = my_listdup(env);
    int last_status = 0;
    char *line = NULL;
    size_t len = 0;

    init_env(&my_env);
    while (1) {
        put_txt();
        if (getline(&line, &len, stdin) == -1)
            break;
        line[my_strcspn(line, "\n")] = '\0';
        if (my_strlen(line) == 0)
            continue;
        if (handle_semicolons(line, &my_env, &last_status) == -1) {
            free_data(&my_env, &line);
            return last_status;
        }
    }
    free_data(&my_env, &line);
    return last_status;
}
