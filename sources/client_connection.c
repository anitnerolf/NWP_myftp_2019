/*
** EPITECH PROJECT, 2020
** client
** File description:
** connection
*/

#include <stdio.h>
#include <unistd.h>
#include "../include/my_ftp.h"

void	set_fd(cli_t *cli)
{
    int i = 0;

    while (i < 50) {
        cli->sd[i] = cli->client[i];
        if (cli->sd[i] > 0)
            FD_SET(cli->sd[i], &cli->readfd);
        if (cli->sd[i] > cli->max_socket)
            cli->max_socket = cli->sd[i];
        i++;
    }
}

int	get_max_socket(cli_t *cli)
{
    FD_ZERO(&cli->readfd);
    FD_SET(cli->server_socket, &cli->readfd);
    cli->max_socket = cli->server_socket;
    return (cli->max_socket);
}

static int	update_connection_list(cli_t *cli)
{
    int i = 0;

    while (i < 50 && 1) {
        if (cli->client[i] == 0) {
            cli->client[i] = cli->client_socket;
            break;
        }
        i++;
    }
    return (0);
}

int	accept_connections(cli_t *cli)
{
    struct sockaddr_in client_s;
    socklen_t size = sizeof(client_s);

    if (FD_ISSET(cli->server_socket, &cli->readfd)) {
        cli->client_socket = accept(cli->server_socket, \
    (struct sockaddr *)&client_s, &size);
        if (cli->client_socket == -1) {
            printf("Client socket error!\n");
            close(cli->client_socket);
            return (84);
        }
        printf("New connction with ip = %s and port %d\n", \
    inet_ntoa(client_s.sin_addr), ntohs(client_s.sin_port));
        write(cli->client_socket, "220 Welcome\r\n", 13);
        update_connection_list(cli);
    }
    return (0);
}
