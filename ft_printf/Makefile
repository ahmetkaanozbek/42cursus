NAME		= libftprintf.a

SRCS		= ft_printf.c \
	ft_print_char.c \
	ft_print_hex.c \
	ft_print_nbr.c \
	ft_print_ptr.c \
	ft_print_string.c \
	ft_print_unbr.c \
	ft_print_perc.c \

OBJS		= $(SRCS:.c=.o)

FLAGS		= -Wall -Werror -Wextra

$(NAME): $(OBJS)

	gcc $(FLAGS) -c $(SRCS)
	ar rc $(NAME) $(OBJS)

all: $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all  clean fclean re
