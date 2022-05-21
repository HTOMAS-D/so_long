SRCS		=	so_long.c \

OBJS	= $(addprefix objs/,$(SRCS:.c=.o))

CFLAGS	= -Wall -Wextra -Werror

CC		= gcc
RM		= rm -f

NAME	= so_long

all:		$(NAME)

objs/%.o: srcs/%.c
			@$(CC) $(CFLAGS) -Imlx -c $< -o $@

$(NAME): 	$(OBJS)
			$(CC) $(OBJS)	 -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)

clean:
			@$(RM) $(OBJS) $(LIBFT_OBJS)

fclean:		clean
			@$(RM) $(NAME)

re:			fclean all
