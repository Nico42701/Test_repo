/*
** EPITECH PROJECT, 2026
** G-PSU 200
** File description:
** MINISHELL1
*/

#include "my.h"

static int my_loop_pipe(char **commands, char ***env, int *fd_in)
{
    int pipefd[2];
    pid_t pid = 0;

    for (int i = 0; commands[i + 1]; i++) {
        if (pipe(pipefd) == -1)
            return 1;
        pid = fork();
        if (pid == 0) {
            close(pipefd[0]);
            exec_pipe_command(commands[i], *fd_in, pipefd[1], env);
            perror("exec failed");
            exit(1);
        }
        if (*fd_in != STDIN_FILENO)
            close(*fd_in);
        close(pipefd[1]);
        *fd_in = pipefd[0];
    }
    return 0;
}

static char **prepare_commands(char *input)
{
    char **commands = my_str_to_word_array(input, "|");

    if (!commands || check_ambiguous(commands))
        return NULL;
    return commands;
}

static int get_last_index(char **commands)
{
    int last = 0;

    while (commands[last])
        last++;
    return last - 1;
}

static int execute_last_command(char *cmd, int fd_in, char ***env)
{
    int wstatus = 0;
    pid_t pid = fork();

    if (pid == 0) {
        exec_pipe_command(cmd, fd_in, STDOUT_FILENO, env);
        perror("exec failed");
        exit(1);
    }
    if (fd_in != STDIN_FILENO)
        close(fd_in);
    waitpid(pid, &wstatus, 0);
    while (wait(NULL) > 0);
    return stat_return(wstatus);
}

int execute_pipeline(char *input, char ***env)
{
    char **commands = prepare_commands(input);
    int fd_in = STDIN_FILENO;
    int last = 0;
    int res = 0;

    if (!commands)
        return 3;
    last = get_last_index(commands);
    if (my_loop_pipe(commands, env, &fd_in)) {
        my_freelist(commands);
        return 1;
    }
    res = execute_last_command(commands[last], fd_in, env);
    my_freelist(commands);
    return res;
}
