/*
** EPITECH PROJECT, 2020
** select
** File description:
** client
*/

#include <sys/select.h>
#include <stdio.h>
#include "../include/my_ftp.h"

int	select_clients(cli_t *cli)
{
    if ((select(cli->max_socket + 1, &cli->readfd, \
    NULL, NULL, NULL)) == -1) {
        printf("select problem\n");
        return (84);
    }
    if ((accept_connections(cli)) != 0) {
        printf("accept problem\n");
        return (84);
    }
    return (0);
}
