/*
** EPITECH PROJECT, 2026
** G-PSU 200
** File description:
** MINISHELL1
*/

int my_strlen(char const *str)
{
    int i = 0;

    while (str[i] != 0)
        i++;
    return i;
}
