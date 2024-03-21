CLIENT_NAME = client
SERVER_NAME = server

CLIENT_BONUS_NAME = client_bonus
SERVER_BONUS_NAME = server_bonus

CC = cc
CFLAGS = -Wall -Wextra -Werror -g3

CLIENT_SRCS = client.c
SERVER_SRCS = server.c

CLIENT_BONUS_SRCS = client_bonus.c
SERVER_BONUS_SRCS = server_bonus.c

CLIENT_BONUS_OBJS = $(CLIENT_BONUS_SRCS:.c=.o)
SERVER_BONUS_OBJS = $(SERVER_BONUS_SRCS:.c=.o)

PRINTF_PATH = ./printf
PRINTF = $(PRINTF_PATH)/printf.a

all: $(CLIENT_NAME) $(SERVER_NAME)

bonus: $(CLIENT_BONUS_NAME) $(SERVER_BONUS_NAME)

$(CLIENT_NAME): $(PRINTF) $(CLIENT_OBJS)
	@cc $(CFLAGS) $(PRINTF) -o $(CLIENT_NAME) $(CLIENT_OBJS)

$(SERVER_NAME): $(PRINTF) $(SERVER_OBJS)
	@cc $(CFLAGS) $(PRINTF) -o $(SERVER_NAME) $(SERVER_OBJS)


$(CLIENT_BONUS_NAME): $(PRINTF) $(CLIENT_BONUS_OBJS)
	@cc $(CFLAGS) $(PRINTF) -o $(CLIENT_BONUS_NAME) $(CLIENT_BONUS_OBJS)

$(SERVER_BONUS_NAME): $(PRINTF) $(SERVER_BONUS_OBJS)
	@cc $(CFLAGS) $(PRINTF) -o $(SERVER_BONUS_NAME) $(SERVER_BONUS_OBJS)

$(PRINTF):
	@make -C $(PRINTF_PATH)

%.o : %.c
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@make clean -C $(PRINTF_PATH)
	@rm -f $(CLIENT_OBJS) $(SERVER_OBJS)
	@rm -f $(CLIENT_BONUS_OBJS) $(SERVER_BONUS_OBJS)

fclean: clean
	@rm -f $(CLIENT_NAME) $(SERVER_NAME)
	@rm -f $(CLIENT_BONUS_NAME) $(SERVER_BONUS_NAME)
	@make fclean -C $(PRINTF_PATH)

re: fclean all

rebonus: fclean bonus

.PHONY: all clean fclean re rebonus