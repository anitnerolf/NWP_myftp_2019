/*
** EPITECH PROJECT, 2020
** quit
** File description:
** command
*/

#include <string.h>
#include <unistd.h>
#include <stdio.h>
#include "../../include/my_ftp.h"

int	quit_command(cli_t *cli)
{
    if (strcmp(cli->clean_line, "QUIT") == 0) {
        write(cli->sd[cli->i], "221 Goodbye!\r\n", 14);
        close(cli->sd[cli->i]);
        cli->client[cli->i] = 0;
    }
    return (0);
}
