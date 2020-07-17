/*
** EPITECH PROJECT, 2020
** pasv
** File description:
** command
*/

#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include "../../include/my_ftp.h"

int	pasv_command(cli_t *cli)
{
    if (strcmp(cli->clean_line, "PASV") == 0) {
        if (cli->pasv[cli->i] == 0) {
            cli->pasv[cli->i] = 1;
            write(cli->sd[cli->i], "227 Entering Passive Mode ", 26);
            write(cli->sd[cli->i], "(h1,h2,h3,h4,p1,p2).\r\n", 22);
            return (0);
        } else {
            write(cli->sd[cli->i], "500 Passive mode already enabled.\r\n", 35);
            return (0);
        }
    }
    return (84);
}
