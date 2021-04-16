# **************************************************************************** #
#                                    RULES                                     #
# **************************************************************************** #

all:
			cd checker_src && make && mv checker ..
			cd push_swap_src && make && mv push_swap ..

clean:
			cd checker_src && make clean
			cd push_swap_src && make clean
			rm -f checker && rm -f push_swap

fclean:		clean
			cd checker_src && make fclean
			cd push_swap_src && make fclean

re:			fclean all

.PHONY: all clean fclean re