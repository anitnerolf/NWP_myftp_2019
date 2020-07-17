/*
** EPITECH PROJECT, 2020
** initialize
** File description:
** socket
*/

#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <netinet/in.h>
#include "../include/my_ftp.h"

int	initialize_socket(void)
{
    int server_socket = socket(AF_INET, SOCK_STREAM, 0);

    if (server_socket == -1) {
        printf("Socket creating failed.\n");
        return (84);
    }
    return (server_socket);
}

int	initialize_socket_structure_bind(int port, int server_socket)
{
    struct sockaddr_in server_address;
    int	size = sizeof(struct sockaddr);
    int server_bind = 0;
    int	listen_value = 0;

    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(port);
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_bind = bind(server_socket, \
    (struct sockaddr *)&server_address, size);
    if (server_bind == -1) {
        write_message_and_close(server_socket, "Bind failed.\n");
        return (84);
    }
    listen_value = listen(server_socket, 50);
    if (listen_value == -1) {
        write_message_and_close(server_socket, "Listen failed.\n");
        return (84);
    }
    return (0);
}
