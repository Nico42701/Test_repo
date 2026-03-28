/*
** EPITECH PROJECT, 2026
** G-PSU 200
** File description:
** MINISHELL1
*/

#include <unistd.h>

char *my_strstr(const char *haystack, const char *needle)
{
    int j = 0;

    if (!*needle)
        return (char *)haystack;
    for (int i = 0; haystack[i]; i++) {
        j = 0;
        while (needle[j] && haystack[i + j] && haystack[i + j] == needle[j])
            j++;
        if (!needle[j])
            return (char *)(haystack + i);
    }
    return NULL;
}
