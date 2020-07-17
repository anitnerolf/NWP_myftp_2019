/*
** EPITECH PROJECT, 2020
** pwd
** File description:
** command
*/

#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include "../../include/my_ftp.h"

int	pwd_command(cli_t *cli)
{
    if (strcmp(cli->clean_line, "PWD") == 0 && strlen(cli->clean_line) == 3) {
        write(cli->sd[cli->i], "257 \"", 6);
        write(cli->sd[cli->i], cli->dir[cli->i], strlen(cli->dir[cli->i]));
        write(cli->sd[cli->i], "\" created.\r\n", 13);
        return (0);
    }
    return (84);
}
