##
## EPITECH PROJECT, 2020
## strace
## File description:
## makefile
##

SRC	=	sources/main.c					\
		sources/client_structure.c			\
		sources/error_check.c				\
		sources/clean_string.c				\
		sources/error_message.c				\
		sources/initialize_program.c			\
		sources/initialize_socket.c			\
		sources/commands/login_commands.c		\
		sources/commands/noop_command.c			\
		sources/parse_commands.c			\
		sources/print_usage.c				\
		sources/commands/quit_command.c			\
		sources/commands/cwd_command.c			\
		sources/commands/help_command.c			\
		sources/commands/list_command.c			\
		sources/commands/delete_command.c		\
		sources/commands/cdup_command.c			\
		sources/commands/pasv_command.c			\
		sources/client_connection.c			\
		sources/select_client.c				\
		sources/commands/pwd_command.c

OBJ	=	$(SRC:.c=.o)

NAME	=	myftp

CFLAGS	=	-Wall -Wextra -Werror

all:		$(NAME) message

$(NAME):	$(OBJ)
		gcc -o $(NAME) $(OBJ) $(CFLAGS) -I ./include

clean:
		rm -f $(OBJ)

fclean:		clean
		rm -f *~ $(NAME)
		rm -rf sources/*~ sources/commands/*~

re:		fclean all

message:
		@echo "Successfully compiled!"
