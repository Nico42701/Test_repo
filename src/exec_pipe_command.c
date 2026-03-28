/*
** EPITECH PROJECT, 2026
** G-PSU 200
** File description:
** MINISHELL1
*/

#include "my.h"

static char **prepare_cmd_args(char *raw_cmd)
{
    char **cmd_args = my_str_to_word_array(raw_cmd, " \t");

    if (!cmd_args)
        exit(1);
    return cmd_args;
}

static void setup_pipes(int pipe_in, int pipe_out)
{
    if (pipe_in != STDIN_FILENO) {
        dup2(pipe_in, STDIN_FILENO);
        close(pipe_in);
    }
    if (pipe_out != STDOUT_FILENO) {
        dup2(pipe_out, STDOUT_FILENO);
        close(pipe_out);
    }
}

static int check_command(char ***env, char *raw_cmd, char **cmd_args,
    char **path)
{
    char **tmp = my_str_to_word_array(raw_cmd, " \t");
    int ret = 0;

    if (!tmp) {
        my_freelist(cmd_args);
        exit(1);
    }
    ret = check_builtins(env, raw_cmd);
    if (ret != 2) {
        my_freelist(cmd_args);
        my_freelist(tmp);
        exit(ret);
    }
    check_file_exist(&tmp, raw_cmd, path, env);
    if (!*path) {
        my_freelist(cmd_args);
        my_freelist(tmp);
        exit(1);
    }
    return ret;
}

void exec_pipe_command(char *raw_cmd, int pipe_in, int pipe_out, char ***env)
{
    char **cmd_args = prepare_cmd_args(raw_cmd);
    char **new_data = NULL;
    char *path = NULL;

    setup_pipes(pipe_in, pipe_out);
    handle_redirection(cmd_args);
    clean_args(cmd_args);
    check_command(env, raw_cmd, cmd_args, &path);
    new_data = my_str_to_word_array(path, " \t");
    if (new_data && cmd_args)
        exec_child(new_data, cmd_args, env);
    my_freelist(cmd_args);
    my_freelist(new_data);
    free(path);
    exit(1);
}
