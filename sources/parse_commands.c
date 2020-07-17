/*
** EPITECH PROJECT, 2020
** parse
** File description:
** commands
*/

#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include "../include/my_ftp.h"

int	check_unknown_commands(char *str)
{
    int unknown_command = 0;

    if (strncmp(str, "QUIT", 4) == 0 || \
        strncmp(str, "USER", 4) == 0 || \
        strncmp(str, "PASS", 4) == 0 || \
        strncmp(str, "CWD", 3) == 0 || \
        strncmp(str, "PWD", 3) == 0 || \
        strncmp(str, "HELP", 4) == 0 || \
        strncmp(str, "LIST", 4) == 0 || \
        strncmp(str, "DELE", 4) == 0 || \
        strncmp(str, "CDUP", 4) == 0 || \
        strncmp(str, "PASV", 4) == 0 || \
        strncmp(str, "NOOP", 4) == 0)
        unknown_command = 0;
    else
        unknown_command = 1;
    return (unknown_command);
}

int	commands_after_user_logged_in(cli_t *cli)
{
    noop_command(cli);
    pwd_command(cli);
    cwd_command(cli);
    list_command(cli);
    delete_command(cli);
    cdup_command(cli);
    pasv_command(cli);
    return (0);
}

static int	call_user(cli_t *cli)
{
    if (user_command(cli) == 0)
        return 0;
    return (1);
}

static int	call_password(cli_t *cli)
{
    if (password_command(cli) == 0)
        return (0);
    return (1);
}

void	parse_commands(cli_t *cli)
{
    if (check_unknown_commands(cli->clean_line) == 0) {
        help_command(cli);
        quit_command(cli);
        if (call_user(cli) == 0 || call_password(cli) == 0)
            return;
        if (cli->logged_in[cli->i] == 1) {
            commands_after_user_logged_in(cli);
        } else {
            write(cli->sd[cli->i], \
    "530 Please login with USER and PASS\r\n", 37);
        }
    } else {
        write(cli->sd[cli->i], \
    "500 Not a valid command\r\n", 25);
    }
}
