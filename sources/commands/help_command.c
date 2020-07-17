/*
** EPITECH PROJECT, 2020
** help
** File description:
** command
*/

#include <string.h>
#include <unistd.h>
#include "../../include/my_ftp.h"

int	help_command(cli_t *cli)
{
    const char ptr[45] = "214 Help. Use one of the following commands: ";
    const char str[52] = "USER, PASS, QUIT, PWD, CWD, HELP, NOOP, DELE, CDUP, ";
    const char str2[31] = "PORT, PASV, STOR, RETR, LIST.\r\n";

    if (strcmp(cli->clean_line, "HELP") == 0) {
        write(cli->sd[cli->i], (const void *)ptr, strlen(ptr));
        write(cli->sd[cli->i], str, strlen(str));
        write(cli->sd[cli->i], str2, strlen(str2));
    }
    return (84);
}
