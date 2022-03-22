/*
** EPITECH PROJECT, 2022
** B-PSU-101-PAR-1-1-minishell1-jeras.bertine
** File description:
** setenv_function
*/

#include "my.h"
#include <stddef.h>
#include <unistd.h>

int array_len(char **av)
{
    int i = 0;
    for (; av[i] != NULL; i++);
    return (i);
}

int error(char **cmd)
{
    if (array_len(cmd) > 3)
        write(2, "setenv: Too many arguments.\n", 28);
    return (1);
}

int setenv_function(char **cmd, char **env)
{
    int last = 0;
    error(cmd);
    if (cmd[1] == NULL) {
        env_function(env);
        return (1);
    }
    int len_new = my_strlen(cmd[1]);
    for (int i = 0; env[i] != NULL; i++) {
        last = i;
    }
    cmd[1][len_new] = '=';
    if (cmd[2] != NULL) {
        cmd[1] = my_strcat(cmd[1], cmd[2]);
    }
    env[last + 1] = cmd[1];
    env[last + 2] = NULL;
    return (0);
}
