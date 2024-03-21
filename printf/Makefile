NAME = printf.a
SRCS = ft_printf.c ft_check_format.c ft_print_csid.c \
		ft_print_hex.c ft_itoa_2.c
CC = cc
CFLAGS = -Wall -Wextra -Werror -Ilibft
OBJS = $(SRCS:.c=.o)

all : $(NAME)

$(NAME) : $(OBJS)
	ar rc $(NAME) $(OBJS)
	ranlib $(NAME)

clean :
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY: all clean fclean re
