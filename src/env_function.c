/*
** EPITECH PROJECT, 2022
** B-PSU-101-PAR-1-1-minishell1-jeras.bertine
** File description:
** env_function
*/

#include "my.h"
#include <stddef.h>

int env_function(char **env)
{
    for (int i = 0; env[i] != NULL; i++)
        my_printf("%s\n", env[i]);
    return (0);
}
