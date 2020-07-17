/*
** EPITECH PROJECT, 2020
** cdup
** File description:
** command
*/

#include <string.h>
#include <unistd.h>
#include <dirent.h>
#include <stdio.h>
#include "../../include/my_ftp.h"

static int count_slash(char *str)
{
    int	i = 0;
    int count = 0;

    for (i = 0; str[i] != '\0'; i++) {
        if (str[i] == '/')
            count++;
    }
    return (count);
}

static void trim_string(char *str)
{
    for (int i = strlen(str); i > 0; i--) {
        if (str[i] == '/') {
            str[i] = '\0';
            break;
        }
    }
}

int	cdup_command(cli_t *cli)
{
    if (strcmp(cli->clean_line, "CDUP") == 0) {
        char *str = strdup(cli->dir[cli->i]);
        trim_string(str);
        DIR *dir = opendir(str);
        if (dir && count_slash(cli->dir[cli->i]) > 1) {
            if (!opendir(str)) {
                write(cli->sd[cli->i], "550 No such directory.\r\n", 24);
            } else {
                cli->dir[cli->i] = strdup(str);
                chdir(cli->dir[cli->i]);
                write(cli->sd[cli->i], "200 Command okay.\r\n", 19);
                closedir(dir);
                return (0);
            }
        } else {
            write(cli->sd[cli->i], "550 No such directory.\r\n", 24);
            return (0);
        }
    }
    return (84);
}
