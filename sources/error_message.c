/*
** EPITECH PROJECT, 2020
** error
** File description:
** message
*/

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "../include/my_ftp.h"

void	write_message_and_close(int server_socket, char *message)
{
    printf("%s", message);
    close(server_socket);
    exit(84);
}
