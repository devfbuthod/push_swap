/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_functions4.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbuthod- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/11 11:27:18 by fbuthod-          #+#    #+#             */
/*   Updated: 2021/04/11 11:27:20 by fbuthod-         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	isBiggest(t_list **la, t_list **lb)
{
	int	pos_first;
	int	pos_second;

	pos_first = getPos(*lb, getBiggest(*lb));
	pos_second = lenList(*lb) - pos_first;
	if (pos_first >= pos_second && pos_first != 0)
		while (getAt(*lb, 0) != getBiggest(*lb))
			parsing("rrb", la, lb);
	else
		while (getAt(*lb, 0) != getBiggest(*lb))
			parsing("rb", la, lb);
}

void	isSmallest(t_list **la, t_list **lb)
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
}

void	isBetween(t_list **la, t_list **lb)
{
	int	pos_first;
	int	pos_second;

	pos_first = getPosBetween(*lb, getAt(*la, 0));
	pos_second = lenList(*lb) - pos_first;
	//printf("pos_first : %d, pos_second : %d, total : %d\n", pos_first, pos_second, lenList(*lb));
	if (pos_first >= pos_second)
		while (!(getAt(*la, 0) < getAt(*lb, lenList(*lb) - 1)
				&& getAt(*la, 0) > getAt(*lb, 0)))
			parsing("rrb", la, lb);
	else if (pos_first < pos_second && pos_second != 0)
		while (!(getAt(*la, 0) < getAt(*lb, lenList(*lb) - 1)
				&& getAt(*la, 0) > getAt(*lb, 0)))
			parsing("rb", la, lb);
}

void	sortListb(t_list **la, t_list **lb)
{
	if (getBiggest(*lb) < getAt(*la, 0))
		isBiggest(la, lb);
	else if (getSmallest(*lb) > getAt(*la, 0))
		isSmallest(la, lb);
	else
		isBetween(la, lb);
}

void	sortLista(t_list **la, t_list **lb)
{
	int	pos_first;
	int	pos_second;

	pos_first = getPos(*la, getSmallest(*la));
	pos_second = lenList(*la) - pos_first;
	if (pos_first >= pos_second && pos_first != 0)
		while (getAt(*la, 0) != getSmallest(*la))
			parsing("rra", la, lb);
	else
		while (getAt(*la, 0) != getSmallest(*la))
			parsing("ra", la, lb);
}
