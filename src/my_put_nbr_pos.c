/*
** EPITECH PROJECT, 2021
** my_put_nbr_pos.c
** File description:
** put nbr unsigned int
*/

#include <unistd.h>

void my_putchar(char c);

int my_put_nbr(int nb);

unsigned int my_put_nbr_pos(unsigned int nb)
{
    if (nb >= 10) {
        my_put_nbr(nb / 10);
        my_putchar(nb % 10 + '0');
    }
    if (nb < 10)
        my_putchar(nb + '0');
    return (0);
}
