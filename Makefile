CLIENT_NAME = client
SERVER_NAME = server

CC = cc
CFLAGS = -Wall -Wextra -Werror -g3

CLIENT_SRCS = client.c
SERVER_SRCS = server.c

CLIENT_OBJS = $(CLIENT_SRCS:.c=.o)
SERVER_OBJS = $(SERVER_SRCS:.c=.o)

LIBFT_PATH = ./libft
LIBFT = $(LIBFT_PATH)/libft.a

all: $(CLIENT_NAME) $(SERVER_NAME)

$(CLIENT_NAME): $(LIBFT) $(CLIENT_OBJS)
	@cc $(CFLAGS) $(LIBFT) -o $(CLIENT_NAME) $(CLIENT_OBJS)

$(SERVER_NAME): $(LIBFT) $(SERVER_OBJS)
	@cc $(CFLAGS) $(LIBFT) -o $(SERVER_NAME) $(SERVER_OBJS)

$(LIBFT):
	@make -C $(LIBFT_PATH)

%.o : %.c
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@make clean -C $(LIBFT_PATH)
	@rm -f $(CLIENT_OBJS) $(SERVER_OBJS)

fclean: clean
	@rm -f $(CLIENT_NAME) $(SERVER_NAME)
	@make fclean -C $(LIBFT_PATH)

re: fclean all

.PHONY: all clean fclean re