/*
** EPITECH PROJECT, 2022
** B-PSU-101-PAR-1-1-bsminishell1-jeras.bertine
** File description:
** my
*/

#ifndef MY_H_
    #define MY_H_
    #include <stdarg.h>

void my_flags(int i, va_list arg, char *s);
void my_printf(char *s, ...);
void my_putchar(char c);
int my_put_nbr(int nb);
unsigned int my_put_nbr_pos(unsigned int nb);
int my_putstr(char const *str);
char **my_str_to_array(char *str, char d);
int my_strcmp(char const *s1, char const *s2);
int my_strlen(char const *str);
int env_function(char **env);
int pwd_function(void);
int setenv_function(char **cmd, char **env);
int clear(char **cmd, char **env);
char *my_strcat(char *dest, char const *src);
char *getpath(char **env);
int cmd_fct(char **cmd, char **env);
int bin(char **cmd, char **env);
int cmd_bin(char *str, char **env);
int cd_options(char **cmd);
int error_handlings(int error, char **cmd);
int array_len(char **av);

#endif /* !MY_H_ */
