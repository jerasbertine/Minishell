/*
** EPITECH PROJECT, 2021
** my_printf.c
** File description:
** function print
*/

#include "my.h"
#include <stdarg.h>

void my_flags(int i, va_list arg, char *s)
{
    if (s[i] == 'c')
        my_putchar(va_arg(arg, int));
    if (s[i] == 's')
        my_putstr(va_arg(arg, char *));
    if (s[i] == 'd')
        my_put_nbr(va_arg(arg, int));
    if (s[i] == 'i')
        my_put_nbr(va_arg(arg, int));
    if (s[i] == 'u')
        my_put_nbr_pos(va_arg(arg, unsigned int));
    if (s[i] == '%')
        my_putchar('%');
}

void my_printf(char *s, ...)
{
    int i = 0;
    va_list arg;

    va_start(arg, s);
    for (; s[i] != '\0'; i++) {
        if (s[i] == '%') {
            i++;
            my_flags(i, arg, s);
        } else {
            my_putchar(s[i]);
        }
    }
    va_end(arg);
}
