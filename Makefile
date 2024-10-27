# Variables
CC = gcc
CFLAGS = -Wall -Wextra -Werror -O3 #-g3 -fsanitize=address
NAME = pipex
SRCS = src/pipex.c src/pipex_utils.c src/errors.c libft/libft.a
SRCS_BONUS = src_bonus/pipex_bonus.c src/pipex_utils.c src/errors.c libft/libft.a
LIBFT = libft/libft.a
NAME_BONUS = pipex_bonus
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

bonus : clean
	make all -C libft
	gcc $(CFLAGS) $(SRCS_BONUS) -o $(NAME_BONUS)