/*
** EPITECH PROJECT, 2020
** delete
** File description:
** command
*/

#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include "../../include/my_ftp.h"

int	delete_command(cli_t *cli)
{
    if (strncmp(cli->clean_line, "DELE", 4) == 0) {
        char *str = cli->clean_line + 5;
        int status = remove(str);
        if (status == 0) {
            write(cli->sd[cli->i], \
    "250 Requested file action okay, completed.\r\n", 44);
        } else {
            write(cli->sd[cli->i], \
    "550 Cannot delete file requested.\r\n", 35);
            return (0);
        }
    }
    return (84);
}
