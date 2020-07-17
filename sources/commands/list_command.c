/*
** EPITECH PROJECT, 2020
** list
** File description:
** command
*/

#include <string.h>
#include <unistd.h>
#include "../../include/my_ftp.h"

int	list_command(cli_t *cli)
{
    char str[54] = "150 File status okay; about to open data connection.\r\n";
    const char str2[30] = "226 Closing data connection.\r\n";
    char *array[] = {"ls", "-l", NULL};

    if (strcmp(cli->clean_line, "LIST") == 0) {
        if (cli->pasv[cli->i] == 1) {
            pid_t pid;
            pid = fork();
            if (pid == 0) {
                execvp(array[0], array);
            }
            write(cli->sd[cli->i], str, 54);
            write(cli->sd[cli->i], str2, 30);
        } else {
            write(cli->sd[cli->i], "500 Enable passive mode.\r\n", 26);
            return (0);
        }
    }
    return (84);
}
