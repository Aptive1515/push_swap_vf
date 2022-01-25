LIBFT		= ./libft/libft.a

SRCS		= push_swap.c ft_swap.c ft_rotate.c ft_reverse_rotate.c ft_push.c \
			ft_check_arg.c ft_check_list.c ft_algo.c ft_place.c ft_find.c \
			ft_big_algo.c ft_opti.c

OBJS		= ${SRCS:.c=.o}

NAME		= push_swap

CC			= gcc

.c.o:
			${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

CFLAGS		= -g -Wall -Wextra -Werror

OBJS		= $(SRCS:.c=.o)

RM			= rm -f

$(NAME):	$(OBJS)
			$(MAKE) bonus -C ./libft

all:		$(NAME)
			@$(CC) $(FLAGS) $(SRCS) $(LIBFT) -o $(NAME)

clean:
			$(RM) $(OBJS)

libclean:	clean
			$(MAKE) clean -C ./libft

fclean:		clean
			$(RM) $(NAME)

re:			fclean $(NAME)

.PHONY:		all clean fclean re
