/*
** EPITECH PROJECT, 2022
** B-PSU-101-PAR-1-1-minishell1-jeras.bertine
** File description:
** bin_function
*/

#include "my.h"
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <errno.h>

int cmd_fct(char **cmd, char **env)
{
    if (my_strcmp(cmd[0], "env") == 0)
        return (env_function(env));
    if (my_strcmp(cmd[0], "pwd") == 0)
        return (pwd_function());
    if (my_strcmp(cmd[0], "setenv") == 0)
        return (setenv_function(cmd, env));
    if (my_strcmp(cmd[0], "cd") == 0)
        return (cd_options(cmd));
    if (my_strcmp(cmd[0], "exit") == 0)
        exit(0);
    return (1);
}

int cmd_bin(char *str, char **env)
{
    char **cmd = my_str_to_array(str, ' ');
    int dir = cmd_fct(cmd, env);
    if (dir == 1)
        return (bin(cmd, env));
    return (0);
}

char *getpath(char **env)
{
    int i = 0;
    char *path = NULL;
    for (; env[i] != NULL; i++) {
        if (env[i][0] == 'P' && env[i][1] == 'A' && env[i][4] == '=') {
            path = env[i];
            break;
        }
    }
    path += 5;
    return (path);
}

int bin(char **cmd, char **env)
{
    pid_t child = fork();
    int status;
    int i = 0;
    char *test = getpath(env);
    char **path = my_str_to_array(test, ':');
    char *str = NULL;

    if (child == 0) {
        while ((execve(str, cmd, env)) == -1) {
            str = my_strcat(path[i], "/");
            str = my_strcat(str, cmd[0]);
            i++;
        }
        execve(cmd[0], cmd, env);
        exit(0);
    } else {
        waitpid(child, &status, 0);
    }
    return (0);
}
