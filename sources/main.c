/*
** EPITECH PROJECT, 2020
** main
** File description:
** file
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "../include/my_ftp.h"

int	main(int ac, char **av)
{
    if (ac == 3) {
        return (three_arguments(av));
    } else {
        print_usage();
        return (84);
    }
    return (0);
}

int	three_arguments(char **av)
{
    if (check_if_number(av[1]) == 84 || atoi(av[1]) <= 0) {
        printf("Port must be a number, positive and greater than 0!\n");
        return (84);
    } else {
        return (main_initializer(av));
    }
    return (0);
}

int	main_initializer(char **av)
{
    check_directory(av[2]);
    chdir(av[2]);
    int	server_socket = initialize_socket();
    if (server_socket == 84) {
        printf("SOCKEETTTTT\n");
        return (84);
    }
    if ((initialize_socket_structure_bind(atoi(av[1]), server_socket)) == 84) {
        printf("BLLAAAAAA\n");
        return (84);
    }
    if ((main_loop(atoi(av[1]), server_socket, av[2])) != 0) {
        printf("Very bad\n");
        return (84);
    }
    return (0);
}
