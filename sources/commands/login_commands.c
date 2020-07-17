/*
** EPITECH PROJECT, 2020
** login
** File description:
** commands
*/

#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include "../../include/my_ftp.h"

int	check_pass_password(cli_t *cli)
{
    if (cli->logged_in[cli->i] == 1 && \
    (strcmp(cli->clean_line, "PASS ") == 0 || \
    strcmp(cli->clean_line, "PASS") == 0)) {
        cli->authenticate[cli->i] = 1;
        write(cli->sd[cli->i], "230 User logged in, proceed.\r\n", 30);
        return (0);
    } else {
        write(cli->sd[cli->i], "530 wrong user or password\r\n", 28);
        return (0);
    }
    return (0);
}

int	password_command(cli_t *cli)
{
    if (strncmp(cli->clean_line, "PASS", 4) == 0) {
        return (check_pass_password(cli));
    }
    return (84);
}

int	check_anonymous_user(cli_t *cli)
{
    if (strlen(cli->clean_line) > 4) {
        if (strcmp(cli->clean_line, "USER Anonymous") == 0)
            cli->logged_in[cli->i] = 1;
        write(cli->sd[cli->i], "331 User name okay, need password.\r\n", 36);
        return (0);
    } else {
        write(cli->sd[cli->i], "530 Please login with USER and PASS\r\n", 37);
    }
    return (0);
}

int	user_command(cli_t *cli)
{
    if (strncmp(cli->clean_line, "USER", 4) == 0) {
        return (check_anonymous_user(cli));
    }
    return (84);
}
