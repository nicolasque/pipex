SRCS			= pipex_utils.c pipex.c libft/libft.a
OBJS			= $(SRCS:.c=.o)
CC				= @cc
RM				= @rm -f
CFLAGS			= -Wall -Wextra -Werror -ggdb -pedantic -I.

NAME			= pipex

all:			$(NAME)

$(NAME):		$(OBJS)
				@ar rcs $(NAME) $(OBJS)

clean:
				@$(RM) $(OBJS) $(BONUS_OBJS)

fclean:			clean
				@$(RM) $(NAME)

re:				fclean $(NAME)

bonus:			$(OBJS) $(BONUS_OBJS)
				@ar rcs $(NAME) $(OBJS) $(BONUS_OBJS)

.PHONY:			all clean fclean re bonus