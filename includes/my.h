/*
** EPITECH PROJECT, 2025
** my.h
** File description:
** null
*/

#ifndef MY_H
    #define MY_H

    #include <unistd.h>
    #include <string.h>
    #include <stdlib.h>
    #include <sys/types.h>
    #include <dirent.h>
    #include <stdio.h>
    #include <sys/wait.h>
    #include <signal.h>
    #include <string.h>
    #include <sys/stat.h>
    #include <fcntl.h>
    #include "my_printf.h"

typedef struct command_s {
    char *tmp;
    char *path;
} command_t;

typedef struct semicolon_s {
    int max;
    int current;
    int is_exit;
} semicolon_t;

typedef struct setenv_s {
    int idx;
    size_t name_len;
    char **new_env;
    char *new_line;
} setenv_t;

typedef struct s_replace_ctx {
    char **res_ptr;
    const char *cur;
    const char *tmp;
    const char *old;
    const char *new_str;
} replace_ctx_t;


// Lib

int my_strlen(char const *str);
void my_putchar(char c);
char **my_str_to_word_array(char const *str, const char *delims);
int my_count_words(const char *str, const char *delims);
int my_strncmp(char const *s1, char const *s2, int n);
int my_strcmp(char const *s1, char const *s2);
char *my_strdup(const char *src);
char *my_strchr(const char *str, char c);
int my_strcspn(char const *str, char const *charset);
char *my_strcpy(char *dest, char const *src);
char *my_strstr(const char *haystack, const char *needle);
char *my_strcat(char *dest, char const *src);
char *my_word_array_to_str(char **tab);
char *my_itoa(int n);
void *my_memcpy(void *dest, const void *src, int n);
char *my_str_replace(const char *str, const char *old, const char *new_str);
int my_str_is_alnum(const char *s);
int my_is_alpha(char c);
void my_freelist(char **list);
char **my_listdup(char **list);
int my_str_is_special_operators(char *str);
char *trim_space(char *str);

// MINISHELL

int my_sh(char **env);
int handle_semicolons(char *line, char ***env, int *last_status);
int check_builtins(char ***env, char *line);
int execute_pipeline(char *input, char ***env);
int check_ambiguous(char **commands);
int count_occurrences_words(char *str, char *target);
void my_env(char ***env);
int my_cd(char ***env, char *line);
int my_echo(char *line, int last_status);
int my_exec_setenv(char ***env, const char *name, const char *value);
char *my_getenv(char ***env, const char *str);
char *my_getpath(char **data, char *str);
int my_form_setenv(char ***env, const char *name, const char *value);
int my_setenv(char ***env, char *line);
int my_unsetenv(char ***env, const char *name);
void exec_pipe_command(char *raw_cmd, int pipe_in, int pipe_out, char ***env);
void handle_redirection(char **cmd);
int stat_return(int wstatus);
void clean_args(char **args);
void free_data(char ***my_env, char **line);
int check_file_exist(char ***tmp, char *line,
    char **path, char ***env);
void exec_child(char **str, char **list, char ***env);
void check_error_message(char *str);
int check_error(char ***env, int c_word, char **data, int res);
int check_error_value(int res, char ***env, char **data);
int put_error(void);
int my_checkenv(char ***env, const char *name);

#endif
