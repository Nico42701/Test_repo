/*
** EPITECH PROJECT, 2026
** G-PSU 200
** File description:
** MINISHELL1
*/

#include "my.h"

int check_ambiguous(char **commands)
{
    int append = 0;
    int redirect = 0;

    for (int i = 0; commands[i]; i++) {
        append = count_occurrences_words(commands[i], ">>");
        redirect = count_occurrences_words(commands[i], ">") - (append * 2);
        if (append > 1 || redirect > 1 || (append && redirect)) {
            my_dprintf(2, "Ambiguous output redirect.\n");
            my_freelist(commands);
            return 1;
        }
        if (count_occurrences_words(commands[i], "<") > 1) {
            my_dprintf(2, "Ambiguous input redirect.\n");
            my_freelist(commands);
            return 1;
        }
    }
    return 0;
}
