/*
** EPITECH PROJECT, 2026
** G-PSU 200
** File description:
** MINISHELL1
*/

#include "my.h"

static char *my_build_path(char *dir, char *file)
{
    char *path = malloc(my_strlen(dir) + my_strlen(file) + 2);

    my_strcpy(path, dir);
    my_strcat(path, "/");
    my_strcat(path, file);
    return path;
}

static void my_free_data(char ***data, DIR **dir, char **str)
{
    my_freelist(*data);
    closedir(*dir);
    free(*str);
}

static char *loop_directory(char *str, char *file_dir)
{
    DIR *dir = opendir(file_dir);
    struct dirent *entry = NULL;
    char **data = NULL;
    char *res = NULL;

    if (dir == NULL)
        return NULL;
    data = my_str_to_word_array(str, " \t");
    str = my_word_array_to_str(data);
    entry = readdir(dir);
    while (entry != NULL) {
        if (my_strcmp(entry->d_name, data[0]) == 0) {
            res = my_build_path(file_dir, str);
            my_free_data(&data, &dir, &str);
            return res;
        }
        entry = readdir(dir);
    }
    my_free_data(&data, &dir, &str);
    return NULL;
}

char *my_getpath(char **data, char *str)
{
    int i = 0;
    char *res = NULL;

    if (!str || !data)
        return NULL;
    while (data[i] != 0) {
        res = loop_directory(str, data[i]);
        if (res != NULL)
            return res;
        i++;
    }
    return NULL;
}
