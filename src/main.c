/*
** EPITECH PROJECT, 2022
** B-PSU-101-PAR-1-1-bsminishell1-jeras.bertine
** File description:
** main
*/

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "my.h"

char *str_cut(char *str)
{
    str[my_strlen(str) - 1] = '\0';
    return (str);
}

int exit_function(int characters, int out)
{
    if (characters == -1)
        out = 2;
    if (out != 0) {
        my_printf("exit\n");
        exit(0);
    }
    return (out);
}

int minishell(char **env)
{
    size_t size = 30000;
    char *str = NULL;
    int out = 0;
    int characters = 0;

    while (out == 0) {
        my_printf("$> ");
        characters = getline(&str, &size, stdin);
        out = exit_function(characters, out);
        str = str_cut(str);
        cmd_bin(str, env);
    }
    return (0);
}

int main(int ac, char **av, char **env)
{
    if (ac > 1)
        return (84);
    av = av;
    return (minishell(env));
}
