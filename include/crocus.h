/*
** EPITECH PROJECT, 2026
** crocus
** File description:
** crocus
*/

#ifndef CROCUS_H_
    #define CROCUS_H_
    #include <string.h>
    #include <unistd.h>
    #include <stdio.h>
    #include <stdlib.h>

typedef struct tab_nb_s {
    char number;
    char *nb[5];
} tab_nb_t;

typedef struct crocus_s {
    char *number;
    char *to_fill;
} crocus_t;

int parser(char **av, crocus_t *cr);
int find_flag_n(char **av, crocus_t *cr);
int find_flag_s(char **av, crocus_t *cr);
int print_error(int fd);
int print_h(int fd);
int print_crocus(char *str, char *to_fill);
void free_crocus(crocus_t *cr);

#endif /* !CROCUS_H_ */
