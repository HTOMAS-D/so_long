SRCS		=	so_long.c \

LIBFT_SRCS	=	ft_printf.c ft_bzero.c get_next_line_utils_bonus.c get_next_line_bonus.c \
			ft_calloc.c ft_itoa.c ft_memset.c ft_putchar.c ft_putex.c ft_putexup.c \
			ft_putptr.c ft_putsigned.c ft_putstr.c ft_putunsigned.c ft_uitoa.c
OBJS	= $(addprefix objs/,$(SRCS:.c=.o))

LIBFT_OBJS	= $(addprefix objs/,$(LIBFT_SRCS:.c=.o))

CFLAGS	= -Wall -Wextra -Werror

RM		= rm -f

NAME	= so_long

all:		$(NAME)

objs/%.o: srcs/%.c
			@$(CC) $(CFLAGS) -Imlx -c $< -o $@

objs/%.o: libft_srcs/%.c
			@$(CC) $(CFLAGS) -Imlx -c $< -o $@

$(NAME): 	$(OBJS) $(LIBFT_OBJS)
			@cc $(OBJS)	$(LIBFT_OBJS) $(CFLAGS) -g -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)

clean:
			@$(RM) $(OBJS) $(LIBFT_OBJS)

fclean:		clean
			@$(RM) $(NAME)

re:			fclean all
