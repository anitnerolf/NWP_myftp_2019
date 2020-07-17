/*
** EPITECH PROJECT, 2020
** noop
** File description:
** command
*/

#include <string.h>
#include <unistd.h>
#include "../../include/my_ftp.h"

void	noop_command(cli_t *cli)
{
    if (strcmp(cli->clean_line, "NOOP") == 0) {
        write(cli->client_socket, "200 Command okay.\r\n", 19);
    }
}
