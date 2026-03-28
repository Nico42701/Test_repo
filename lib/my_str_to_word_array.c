/*
** EPITECH PROJECT, 2026
** G-PSU 200
** File description:
** MINISHELL1
*/

#include <stdlib.h>
#include <string.h>
#include <ctype.h>

static int is_field_char(char c, const char *delims)
{
    for (int i = 0; delims[i] != '\0'; i++) {
        if (c == delims[i])
            return 0;
    }
    return 1;
}

static void check_inc(int *in_word, int *count)
{
    if (!*in_word) {
        (*count)++;
        *in_word = 1;
    }
}

int my_count_words(const char *str, const char *delims)
{
    int count = 0;
    int in_word = 0;
    int i = 0;

    while (str[i] != 0) {
        if (is_field_char(str[i], delims))
            check_inc(&in_word, &count);
        else
            in_word = 0;
        i++;
    }
    return count;
}

static char *word_dup(const char *start, int len)
{
    char *word = malloc(len + 1);

    if (!word)
        return NULL;
    for (int i = 0; i < len; i++)
        word[i] = start[i];
    word[len] = '\0';
    return word;
}

static void loop_str(const char **str, char **result, int *i,
    const char *delims)
{
    const char *start = NULL;

    if (is_field_char(**str, delims)) {
        start = *str;
        while (**str && is_field_char(**str, delims))
            (*str)++;
        result[*i] = word_dup(start, *str - start);
        (*i)++;
    } else {
        (*str)++;
    }
}

char **my_str_to_word_array(char const *str, const char *delims)
{
    char **result = NULL;
    int i = 0;
    int word_count = 0;

    if (!str || !delims)
        return NULL;
    word_count = my_count_words(str, delims);
    result = malloc(sizeof(char *) * (word_count + 1));
    if (!result)
        return NULL;
    while (*str)
        loop_str(&str, result, &i, delims);
    result[i] = NULL;
    return result;
}
