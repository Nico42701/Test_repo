/*
** EPITECH PROJECT, 2026
** Stumper
** File description:
** Stumper
*/

#include "crocus.h"

const tab_nb_t tab[] = {
    {'0', {".000.", "0...0", "0...0", "0...0", ".000."}},
    {'1', {".000.", "0.00.", "..00.", "..00.", ".0000"}},
    {'2', {".000.", "0...0", "...0.", ".0...", "00000"}},
    {'3', {"0000.", "....0", ".000.", "....0", "0000."}},
    {'4', {"..00.", ".0.0.", "0..0.", "00000", "...0."}},
    {'5', {"00000", "0....", "0000.", "....0", "0000."}},
    {'6', {".000.", "0....", "0000.", "0...0", ".000."}},
    {'7', {"00000", "....0", "...0.", "..0..", ".0..."}},
    {'8', {".000.", "0...0", ".000.", "0...0", ".000."}},
    {'9', {".000.", "0...0", ".0000", "....0", ".000."}}
};

void print_line(char *str, char c)
{
    for (int i = 0; str[i]; i++) {
        if (str[i] == '0')
            printf("%c", c);
        else
            printf(" ");
    }
}

void print_space(char s)
{
    if (s != 0)
        printf(" ");
}

char fill_char(char *str, char c)
{
    int len = strlen(str);
    int mod = atoi(&c);
    int to_return = 0;

    to_return = mod % len;
    return str[to_return];
}

void loop_print(char *str, int j, int i, char *to_fill)
{
    char c = '\0';

    for (int k = 0; k < 10; k++) {
        if (str[j] == tab[k].number) {
            c = fill_char(to_fill, tab[k].number);
            print_line(tab[k].nb[i], c);
            print_space(str[j + 1]);
        }
    }
}

int print_crocus(char *str, char *to_fill)
{
    for (int i = 0; i < 5; i++) {
        for (int j = 0; str[j]; j++)
            loop_print(str, j, i, to_fill);
        printf("\n");
    }
    return 0;
}
