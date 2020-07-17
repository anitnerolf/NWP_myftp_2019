/*
** EPITECH PROJECT, 2020
** error
** File description:
** check
*/

#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include "../include/my_ftp.h"

int	check_if_number(char *s)
{
    int i = 0;
    int result = 0;

    while (s[i] != '\0') {
        if (!(s[i] <= '9' && s[i] >= '0'))
            return (84);
        i++;
    }
    return (result);
}

void	check_directory(char *directory)
{
    DIR *dir = opendir(directory);

    if (dir == NULL) {
        printf("Directory %s not reachable!\n", directory);
        exit(84);
    }
}
