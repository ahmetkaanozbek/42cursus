NAME = minitalk

CLIENT_SRC = client.c
CLIENT_OBJ = client.o

SERVER_SRC = server.c
SERVER_OBJ = server.o

CFLAGS = -Wall -Wextra -Werror
LIB = ./ft_printf/libftprintf.a

all: $(NAME)

$(NAME): $(SERVER_OBJ) $(CLIENT_OBJ)
		make -C ./ft_printf
		gcc -o server $(SERVER_SRC) $(CFLAGS) $(LIB)
		gcc -o client $(CLIENT_SRC) $(CFLAGS) $(LIB)
		ar rc $(NAME) $(SERVER_OBJ) $(CLIENT_OBJ)

clean: 
		rm -f $(CLIENT_OBJ) $(SERVER_OBJ)
		rm -f ./ft_printf/*.o

fclean: clean
		rm -f server client
		rm -f ./ft_printf/*.a
		rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
