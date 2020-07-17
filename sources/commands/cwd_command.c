/*
** EPITECH PROJECT, 2020
** cwd
** File description:
** command
*/

#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <dirent.h>
#include "../../include/my_ftp.h"

static int	if_dir(cli_t *cli, DIR *dir)
{
    if (cli->dir[cli->i][strlen(cli->dir[cli->i]) - 1] != '/')
        strcat(cli->dir[cli->i], "/");
    strcat(cli->dir[cli->i], cli->clean_line + 4);
    if (!opendir(cli->dir[cli->i])) {
        write(cli->sd[cli->i], \
    "550 No such directory.\r\n", 24);
    } else {
        chdir(cli->dir[cli->i]);
        write(cli->sd[cli->i], \
    "250 Requested file action okay, completed.\r\n", 44);
        closedir(dir);
        return (0);
    }
    return (0);
}

int	cwd_command(cli_t *cli)
{
    if (strncmp(cli->clean_line, "CWD ", 4) == 0) {
        char *str = cli->clean_line + 4;
        DIR *dir = opendir(str);
        if (dir) {
            return (if_dir(cli, dir));
        } else {
            write(cli->sd[cli->i], \
    "550 No such directory.\r\n", 24);
            return (0);
        }
    }
    return (84);
}
