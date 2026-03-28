/*
** EPITECH PROJECT, 2026
** LIB
** File description:
** my_str_is_special_operators
*/

#include "my.h"

void handle_input_redirection(char **cmd, int i, int fd)
{
    if (my_strcmp(cmd[i], "<") == 0) {
        fd = open(cmd[i + 1], O_RDONLY);
        if (fd == -1) {
            perror("open");
            exit(1);
        }
        dup2(fd, 0);
        close(fd);
    }
}

void handle_output_redirection(char **cmd, int i, int fd)
{
    if (my_strcmp(cmd[i], ">") == 0) {
        fd = open(cmd[i + 1], O_CREAT | O_WRONLY | O_TRUNC, 0644);
        if (fd == -1) {
            perror("open");
            exit(1);
        }
        dup2(fd, 1);
        close(fd);
    }
}

void handle_append_redirection(char **cmd, int i, int fd)
{
    if (my_strcmp(cmd[i], ">>") == 0) {
        fd = open(cmd[i + 1], O_CREAT | O_WRONLY | O_APPEND, 0644);
        if (fd == -1) {
            perror("open");
            exit(1);
        }
        dup2(fd, 1);
        close(fd);
    }
}

static void loop_heredoc(char **cmd, int i, int pipefd[])
{
    char *line = NULL;
    size_t len = 0;

    while (1) {
        my_dprintf(1, "heredoc> ");
        if (getline(&line, &len, stdin) == -1)
            exit(1);
        line[my_strcspn(line, "\n")] = 0;
        if (my_strcmp(line, cmd[i + 1]) == 0)
            break;
        write(pipefd[1], line, my_strlen(line));
        write(pipefd[1], "\n", 1);
    }
    free(line);
    return;
}

void handle_heredoc(char **cmd, int i)
{
    int pipefd[2] = {0};

    if (my_strcmp(cmd[i], "<<") == 0) {
        pipe(pipefd);
        loop_heredoc(cmd, i, pipefd);
        close(pipefd[1]);
        dup2(pipefd[0], 0);
        close(pipefd[0]);
    }
}

void handle_redirection(char **cmd)
{
    int fd = 0;

    for (int i = 0; cmd[i]; i++) {
        handle_input_redirection(cmd, i, fd);
        handle_output_redirection(cmd, i, fd);
        handle_append_redirection(cmd, i, fd);
        handle_heredoc(cmd, i);
    }
}
