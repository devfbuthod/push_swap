/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbuthod- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 11:37:27 by fbuthod-          #+#    #+#             */
/*   Updated: 2021/03/05 11:37:30 by fbuthod-         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/checker.h"

int	isEmptyList(t_list *list)
{
	return (list == NULL);
}

t_list	*createCell(int data)
{
	t_list	*cell;

	cell = malloc(sizeof(t_list));
	if (!cell)
		return (NULL);
	cell->data = data;
	cell->next = NULL;
	return (cell);
}

void	addAtFollow(t_list **cell, t_list **list)
{
	(*cell)->next = *list;
	(*cell)->prev = NULL;
	*list = *cell;
}

void	addAt(t_list **list, int data, int pos)
{
	t_list	*prec;
	t_list	*cur;
	t_list	*cell;
	int		i;

	prec = *list;
	cur = *list;
	i = 0;
	cell = createCell(data);
	if (isEmptyList(*list))
		*list = cell;
	else if (pos == 0)
		addAtFollow(&cell, list);
	else
	{
		while (i++ < pos)
		{
			prec = cur;
			cur = cur->next;
		}
		prec->next = cell;
		cell->next = cur;
	}
}

t_list	*freeList(t_list *list)
{
	t_list	*tmp;

	tmp = NULL;
	while (list)
	{
		tmp = list->next;
		free(list);
		list = tmp;
	}
	return (list);
}
