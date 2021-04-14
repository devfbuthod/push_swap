/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_functions5.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbuthod- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 12:10:11 by fbuthod-          #+#    #+#             */
/*   Updated: 2021/04/13 12:10:13 by fbuthod-         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_lista(t_list **la, t_list **lb)
{
	int	pos_first;
	int	pos_second;

	pos_first = getPos(*lb, getSmallest(*lb));
	pos_second = lenList(*lb) - pos_first;
	if (pos_first >= pos_second && pos_first != 0)
		while (getAt(*lb, lenList(*lb) - 1) != getSmallest(*lb))
			parsing("rrb", la, lb);
	else
		while (getAt(*lb, lenList(*lb) - 1) != getSmallest(*lb))
			parsing("rb", la, lb);
	while (*lb)
		parsing("pa", la, lb);
}

void	sort(t_list **la, t_list **listb)
{
	if (getAt(*la, 0) > getAt(*la, 1))
		parsing("ra", la, listb);
}

int	lenList(t_list *list)
{
	int	i;

	i = 0;
	while (list)
	{
		i++;
		list = list->next;
	}
	return (i);
}
