/*
** EPITECH PROJECT, 2020
** clean
** File description:
** string
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "../include/my_ftp.h"

int     is_tab_space(char c)
{
    if (c == ' ' || c == '\t')
        return (1);
    return (0);
}

char    *clean_str(char *ptr)
{
    int i = 0;
    int j = 0;
    char *str = malloc(sizeof(char) * strlen(ptr) + 1);

    for ( ; is_tab_space(ptr[i]) != 0; i++);
    while (ptr[i] != '\0') {
        for ( ; is_tab_space(ptr[i]) == 0 && ptr[i] != '\0'; j++, i++) {
            str[j] = ptr[i];
        }
        while (is_tab_space(ptr[i]) == 1 && ptr[i] != '\0') {
            i++;
        }
        str[j] = ' ';
        j++;
    }
    str[j - 1] = '\0';
    str[strlen(str) - 2] = '\0';
    return (str);
}
