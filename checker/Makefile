# **************************************************************************** #
#                                    VARIABLES                                 #
# **************************************************************************** #

CC=clang

CFLAGS=-Wall -Wextra -Werror -g3 -fsanitize=address -I ./includes/

NAME=checker

SRCS	=	./srcs/checker.c			\
			./srcs/list_functions.c		\
			./srcs/list_functions2.c	\
			./srcs/ft_error.c			\
			./srcs/instructions.c		\
			./srcs/parser.c				\
			./srcs/list_functions3.c


LIBFT	=	./libft/libft.a

HEADER	=	./includes/checker.h

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

.PHONY: leaks
leaks: CC = $(HOME)/.brew/opt/llvm/bin/clang
leaks: CFLAGS += -mlinker-version=450 -fsanitize=address -g
leaks: fclean $(NAME)
         ASAN_OPTIONS=detect_leaks=1 ./$(NAME)