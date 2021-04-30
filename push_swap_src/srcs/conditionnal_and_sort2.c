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
		while (getAt(*lb, lenList(*lb) - 1) != getSmallest(*lb)
			&& lenList(*lb) > 1)
			parsing("rrb", la, lb);
	else
		while (getAt(*lb, lenList(*lb) - 1) != getSmallest(*lb)
			&& lenList(*lb) > 1)
			parsing("rb", la, lb);
	/*if (getAt(*lb, 0) > getSmallest(*la) && getAt(*lb, 0) < getBiggest(*la))
	{
		pos_first = getPosEndList(*la, getAt(*lb, 0));
		pos_second = lenList(*la) - pos_first;
		//printf("pos_first : %d, pos_second : %d\n", pos_first, pos_second);
		if (pos_first >= pos_second && pos_first != 0)
			while (!(getAt(*lb, 0) < getAt(*la, lenList(*la) - 1)
				&& getAt(*lb, 0) > getAt(*la, 0)))
			parsing("ra", la, lb);
		else
			while (!(getAt(*lb, 0) < getAt(*la, lenList(*la) - 1)
				&& getAt(*lb, 0) > getAt(*la, 0)))
			parsing("rra", la, lb);
	}*/
	while (*lb)
		parsing("pa", la, lb);
}

void	sort(t_list **la, t_list **listb)
{
	if (getAt(*la, 0) > getAt(*la, 1))
		parsing("ra", la, listb);
}

long long	median_finding(t_list *la)
{
	long long	res;

	if (getSmallest(la) < 0 && getBiggest(la) < 0)
		res = (-(long long)(getSmallest(la)) - -(long long)(getBiggest(la)));
	else if (getSmallest(la) < 0)
		res = -(long long)(getSmallest(la)) + (long long)getBiggest(la);
	else
		res = (long long)getBiggest(la) - (long long)getSmallest(la);
	return (res);
}

void	rotate_pushb(t_list **la, t_list **lb, int min, int max)
{
	while (getAt(*la, 0) != getAt(*la, getPosFirst(*la, min, max)))
		parsing("rra", la, lb);
	if (lenList(*lb) > 1)
		sortListb(la, lb);
	parsing("pb", la, lb);
}

void	sortLista5(t_list **la, t_list **lb)
{
	int	pos_first;
	int	pos_second;

	pos_first = getPos(*la, getSmallest(*la));
	pos_second = 5 - pos_first;
	if (pos_first >= pos_second && pos_first != 0)
		while (getAt(*la, 0) != getSmallest(*la))
			parsing("rra", la, lb);
	else
		while (getAt(*la, 0) != getSmallest(*la))
			parsing("ra", la, lb);
}
