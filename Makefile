# Variables
CC = gcc
CFLAGS = -Wall -Wextra -Werror -O3 #-g3 -fsanitize=address
NAME = pipex
SRCS = pipex.c pipex_utils.c errors.c
SRCS_BONUS = pipex_bonus.c pipex_utils_bonus.c
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