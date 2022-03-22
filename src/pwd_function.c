/*
** EPITECH PROJECT, 2022
** B-PSU-101-PAR-1-1-minishell1-jeras.bertine
** File description:
** pwd_function
*/

#include "my.h"
#include <unistd.h>

int pwd_function(void)
{
    char pwd[100];

    getcwd(pwd, 100);
    my_printf("%s\n", pwd);
    return (0);
}
