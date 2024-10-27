# Variables
CC = gcc
CFLAGS = -Wall -Wextra -Werror -O3 #-g3 -fsanitize=address
NAME = pipex
SRCS = src/pipex.c src/pipex_utils.c src/errors.c
SRCS_BONUS = src/_bonuspipex_bonus.c src_bonus/pipex_utils_bonus.c
LIBFT = libft/libft.a

# Rules
all: $(NAME)

$(NAME): $(SRCS) $(LIBFT)
	$(CC) $(CFLAGS) $(SRCS) $(LIBFT) -o $(NAME)

bonus: $(SRCS_BONUS) $(LIBFT)
	$(CC) $(CFLAGS) $(SRCS_BONUS) $(LIBFT) -o $(NAME)

$(LIBFT):
	make -C libft all

clean:
	$(RM) $(NAME)
	make -C libft clean

fclean: clean
	make -C libft fclean

re: fclean all