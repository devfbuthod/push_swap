#ifndef __MAIN_H__
#define __MAIN_H__

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "./../libft/libft.h"

typedef struct		s_list
{
	int             data;
	struct s_list	*next;
	struct s_list	*prev;
}					t_list;

int isEmptyList(t_list *list);

t_list *createCell(int data);

void addAt(t_list **list, int data, int pos);

t_list *freeList(t_list *list);

int lenList(t_list *list);

int getAt(t_list *list, int pos);

int printList(t_list *list);

int ft_error(t_list *list, int code_erreur);

t_list *rotate_rev(t_list *list);

t_list *rotate_up(t_list *list);

t_list *push(t_list **src, t_list *dest);

t_list *swap(t_list *list);

t_list *incr_list(t_list *list, char **argv);

int ft_verif(t_list *list);

void parse_swap(t_list **lista, t_list **listb, char* buffer);

void parse_push(t_list **lista, t_list **listb, char* buffer);

void parse_rotate(t_list **lista, t_list **listb, char* buffer);

int parsing(char *cmd, t_list **lista, t_list **listb);

int ft_error_parser(char *argv, t_list *list);

t_list *free_and_ret(t_list *to_free, t_list *to_ret);

#endif