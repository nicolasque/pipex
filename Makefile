NAME = pipex

CC = gcc

#CFLAGS = -Werror -Wall -Wextra -g3 -fsanitize=address
CFLAGS = -Werror -Wall -Wextra -g3

RM = rm -rf

SRCS = 	pipex.c\
		pipex_utils.c\
		errors.c\
		libft/libft.a\

SRCS_BONUS = 	pipex_bonus.c\
				pipex_utils_bonus.c\
				libft/libft.a\

$(NAME) :
	make all -C libft
	gcc $(CFLAGS) $(SRCS) -o $(NAME)


all : $(NAME)

fclean : clean
	$(RM) $(NAME)
	make fclean -C libft

clean :
	$(RM) $(NAME)
	make clean -C libft

re : fclean all

bonus : clean
	make all -C libft
	gcc $(CFLAGS) $(SRCS_BONUS) -o $(NAME)
