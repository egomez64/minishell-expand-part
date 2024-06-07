NAME = minishell

LIBFT = libft/libft.a

CC = cc

SRCS = src/parsing/lexing.c src/parsing/token_list.c src/parsing/parsing.c src/parsing/commands_lst.c src/parsing/create_cmd.c \
		src/parsing/lst.c src/expand/env_lst.c src/expand/get_env.c src/expand/expand_utils.c src/expand/expand_var.c test.c \
		src/expand/expand_quote.c

HEADERS = minishell.h

OBJS = $(SRCS:.c=.o)

LDFLAGS = -lreadline

CFLAGS = -Wall -Wextra -Werror -g -Iincludes -Ilibft

ifdef DEBUG
CFLAGS = -Wall -Wextra -Iincludes -Ilibft -g
endif

ifdef CHECK
CFLAGS += -fsanitize=address
endif

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $@ $(LDFLAGS)

$(LIBFT):
	@make -j8 -C libft/ all

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) $< -c -o $@

clean:
	rm -f $(OBJS)
	@make -C libft/ clean
	
fclean: clean
	rm -f $(NAME)
	rm -f $(LIBFT)

re: fclean all

.PHONY: all fclean clean re