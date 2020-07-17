/*
** EPITECH PROJECT, 2020
** client
** File description:
** structure
*/

#include <string.h>
#include "../include/my_ftp.h"

cli_t	*initialize_structure(cli_t *cli, int port, \
    int server_socket, char *dir)
{
    int i = 0;
    cli->server_socket = server_socket;
    cli->port = port;
    cli->i = 0;
    cli->auth = 0;
    while (i < 50) {
        cli->logged_in[i] = 0;
        cli->client[i] = 0;
        cli->sd[i] = 0;
        cli->authenticate[i] = 0;
        cli->cdup[i] = 0;
        cli->pasv[i] = 0;
        cli->dir[i] = strdup(dir);
        i++;
    }
    return (cli);
}
