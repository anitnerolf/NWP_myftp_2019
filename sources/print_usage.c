/*
** EPITECH PROJECT, 2020
** print
** File description:
** usage
*/

#include <stdio.h>
#include "../include/my_ftp.h"

void	print_usage(void)
{
    printf("Usage: ./myftp port path\n");
    printf("\tport is the port numner on ");
    printf("which the server socket listens\n");
    printf("\tport is the path to the home ");
    printf("directory for the Anonymous user\n");
}
