/*
** EPITECH PROJECT, 2026
** G-PSU 200
** File description:
** MINISHELL1
*/

#include "my.h"


int put_error(void)
{
    my_dprintf(2, ": No such file or directory.\n");
    return 84;
}

int check_error_value(int res, char ***env, char **data)
{
    if (res != 0 && my_getenv(env, "HOME") != NULL) {
        my_dprintf(2, "%s: No such file or directory.\n", data[1]);
        return 84;
    }
    if (res != 0 && my_getenv(env, "HOME") == NULL) {
        my_dprintf(2, "No $home variable set.\n");
        return 84;
    }
    return 0;
}

int check_error_file(int res)
{
    if (res == -1) {
        my_dprintf(2, ": No such file or directory.\n");
        return 1;
    }
    if (res == -2) {
        my_dprintf(2, ": Not a directory.\n");
        return 1;
    }
    if (res == -3) {
        my_dprintf(2, ": Permission denied.\n");
        return 1;
    }
    return 0;
}

int check_error(char ***env, int c_word, char **data, int res)
{
    if (c_word > 2) {
        my_dprintf(2, "cd: Too many arguments.\n");
        return 1;
    }
    if ((res == -1 || res == -2 || res == -3) && c_word != 1) {
        my_dprintf(2, data[1]);
        if (check_error_file(res) == 1)
            return 1;
    }
    if (my_getenv(env, "HOME") == NULL && c_word == 1) {
        my_dprintf(2, "cd: No home directory.\n");
        return 1;
    }
    return 0;
}

void check_error_message(char *str)
{
    if (access(str, F_OK) == -1) {
        my_dprintf(2, "%s: Command not found.\n", str);
        return;
    }
    if (access(str, X_OK) == -1) {
        my_dprintf(2, "%s: Permission denied.\n", str);
        return;
    }
    my_dprintf(2, "%s: Exec format error.", str);
    my_dprintf(2, " Binary file not executable.\n");
}
