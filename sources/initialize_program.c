/*
** EPITECH PROJECT, 2020
** initialize
** File description:
** program
*/

#include <netinet/in.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <string.h>
#include <stdio.h>
#include "../include/my_ftp.h"
#include <arpa/inet.h>

void	read_commands(cli_t *cli)
{
    cli->i = 0;
    while (cli->i < 50) {
        cli->sd[cli->i] = cli->client[cli->i];
        if (FD_ISSET(cli->sd[cli->i], &cli->readfd)) {
            if (read(cli->sd[cli->i], cli->line, 1024) == 0) {
                close(cli->sd[cli->i]);
                printf("Client %d left.\n", cli->i + 1);
                cli->client[cli->i] = 0;
            } else {
                cli->clean_line = clean_str(cli->line);
                parse_commands(cli);
            }
            bzero(cli->clean_line, strlen(cli->clean_line));
            bzero(cli->line, 1024);
        }
        cli->i++;
    }
}

int	main_loop(int port, int server_socket, char *dir)
{
    cli_t *cli = malloc(sizeof(cli_t));
    cli = initialize_structure(cli, port, server_socket, dir);

    printf("Start on port %d, waiting for clients.\n", cli->port);
    while (1) {
        if ((cli->max_socket = get_max_socket(cli)) == -1) {
            printf("max_socket problem\n");
            return (84);
        }
        set_fd(cli);
        if ((select_clients(cli)) != 0) {
            printf("Error on selecting clients\n");
            return (84);
        }
        read_commands(cli);
    }
    return (0);
}
