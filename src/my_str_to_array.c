/*
** EPITECH PROJECT, 2022
** lib
** File description:
** my_str_to_array
*/

#include <stdlib.h>

int count_words(char const *str, char d)
{
    int i = 0;
    int count = 0;
    for (; str[i] != '\0'; i++) {
        if (str[i] == d || str[i] == '\0')
            count += 1;
    }
    count += 1;
    return (count);
}

int len_words(char const *str)
{
    int i;
    int len = 0;
    for (i = 0; str[i] != '\0'; i++);
    len = i;
    return (len);
}

char **my_str_to_array(char *str, char d)
{
    int lines = count_words(str, d);
    char **tab = malloc(sizeof(char*) * (lines + 1));
    for (int l = 0, i = 0; l != lines; l++, i++) {
        tab[l] = malloc(sizeof(char) * (len_words(str) + 1));
        for (int c = 0; str[i] != d && str[i] != '\0'; i++, c++) {
            tab[l][c] = str[i];
        }
        tab[l + 1] = NULL;
    }
    return (tab);
}
