/*
** EPITECH PROJECT, 2021
** my_strlen
** File description:
** display the lenght
*/

void my_putchar(char c);

int my_strlen(char const *str)
{
    int jb = 0;

    while (str[jb] != '\0') {
        jb ++;
    }
    return (jb);
}
