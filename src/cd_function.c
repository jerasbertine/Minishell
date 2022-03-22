/*
** EPITECH PROJECT, 2022
** B-PSU-101-PAR-1-1-minishell1-jeras.bertine
** File description:
** cd_function
*/

#include "my.h"
#include <stddef.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>

int error_handlings(int error, char **cmd)
{
    error = error;
    if (errno == ENOENT) {
        write(2, cmd[1], my_strlen(cmd[1]));
        write(2, ": No such file or directory.\n", 29);
        return (0);
    }
    if (errno == ENOTDIR) {
        write(2, cmd[1], my_strlen(cmd[1]));
        write(2, ": Not a directory.\n", 19);
        return (0);
    }
    if (errno == EACCES) {
        write(2, cmd[1], my_strlen(cmd[1]));
        write(2, ": Permission denied.\n", 21);
        return (0);
    }
    return (-1);
}

int cd_options(char **cmd)
{
    if (cmd[1] == NULL)
        return (0);
    if (chdir(cmd[1]) == -1) {
        return (error_handlings(errno, cmd));
    }
    return (0);
}
