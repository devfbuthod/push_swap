# **************************************************************************** #
#                                    VARIABLES                                 #
# **************************************************************************** #

CC=clang

CFLAGS=-Wall -Wextra -Werror -I ./includes/

NAME=push_swap

SRCS	=	./srcs/push_swap.c			\
			./srcs/list_functions.c		\
			./srcs/list_functions2.c	\
			./srcs/ft_error.c			\
			./srcs/instructions.c		\
			./srcs/parser.c				\
			./srcs/algo.c				\
			./srcs/list_functions3.c	\
			./srcs/list_functions4.c	\
			./srcs/list_functions5.c	\

LIBFT	=	./libft/libft.a

HEADER	=	./includes/push_swap.h

OBJS	=	$(SRCS:.c=.o)

RM		=	rm -f

# **************************************************************************** #
#                                    RULES                                     #
# **************************************************************************** #

%.c%.o:
				$(CC) $(CFLAGS) -c $< -o $@

all:            $(NAME)

$(OBJS):        $(INC)

lib:
				$(MAKE) -C libft

$(NAME):        $(OBJS) $(HEADER) lib
				$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

clean:
				$(RM) $(OBJS)
				cd libft && make clean

fclean:         clean
				$(RM) $(NAME)
				cd libft && make fclean

re:             fclean all

.PHONY: all bonus clean fclean re lib