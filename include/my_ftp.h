/*
** EPITECH PROJECT, 2020
** my
** File description:
** ftp
*/

#ifndef MY_FTP_H
#define MY_FTP_H

#include <arpa/inet.h>

typedef struct client {
    int client[50];
    int sd[50];
    int authenticate[50];
    int cdup[50];
    char *dir[50];
    int	pasv[50];
    int max_socket;
    int server_socket;
    int client_socket;
    int port;
    char line[1025];
    char *clean_line;
    fd_set readfd;
    int i;
    int auth;
    int logged_in[50];
    char *directory;
} cli_t;

int	check_if_number(char *s);
void	check_directory(char *directory);
void	write_message_and_close(int server_socket, char *message);
int	main_loop(int port, int server_socket, char *dir);
int	initialize_socket(void);
cli_t	*initialize_structure(cli_t *cli, int port, \
    int server_socket, char *dir);
int	initialize_socket_structure_bind(int port, int server_socket);
int	get_max_socket(cli_t *cli);
void	set_fd(cli_t *cli);
int	accept_connections(cli_t *cli);
int	select_clients(cli_t *cli);
void    parse_commands(cli_t *cli);
void	print_usage(void);
int	password_command(cli_t *cli);
char	*clean_str(char *str);
int	user_command(cli_t *cli);
int	quit_command(cli_t *cli);
void	noop_command(cli_t *cli);
int	cwd_command(cli_t *cli);
int	pwd_command(cli_t *cli);
int	list_command(cli_t *cli);
int	delete_command(cli_t *cli);
int	pasv_command(cli_t *cli);
int	cdup_command(cli_t *cli);
int	help_command(cli_t *cli);
int	three_arguments(char **av);
int	main_initializer(char **av);

#endif /* MY_FTP_H */
