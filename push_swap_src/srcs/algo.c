/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbuthod- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 09:00:46 by fbuthod-          #+#    #+#             */
/*   Updated: 2021/04/09 09:00:48 by fbuthod-         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_3(t_list **la, t_list **listb)
{
	if (getAt(*la, 0) > getAt(*la, 1) && getAt(*la, 1) < getAt(*la, 2)
		&& getAt(*la, 2) > getAt(*la, 0))
		parsing("sa", la, listb);
	else if (getAt(*la, 0) > getAt(*la, 1) && getAt(*la, 1) > getAt(*la, 2))
	{
		parsing("sa", la, listb);
		parsing("rra", la, listb);
	}
	else if (getAt(*la, 0) > getAt(*la, 1) && getAt(*la, 1) < getAt(*la, 2)
		&& getAt(*la, 2) < getAt(*la, 0))
		parsing("ra", la, listb);
	else if (getAt(*la, 0) < getAt(*la, 1) && getAt(*la, 1) > getAt(*la, 2)
		&& getAt(*la, 2) > getAt(*la, 0))
	{
		parsing("sa", la, listb);
		parsing("ra", la, listb);
	}
	else if (getAt(*la, 0) < getAt(*la, 1) && getAt(*la, 1) > getAt(*la, 2)
		&& getAt(*la, 2) < getAt(*la, 0))
		parsing("rra", la, listb);
}

void	sort_5(t_list **la, t_list **lb)
{
	while (lenList(*la) > 3)
		parsing("pb", la, lb);
	sort_3(la, lb);
	sortListb(la, lb);
	while (lenList(*lb) != 0)
	{
		if ((getAt(*la, 0) > getAt(*lb, 0)
				&& getAt(*la, lenList(*la) - 1) < getAt(*lb, 0))
			|| ((getAt(*la, 0) > getAt(*lb, 0)
					&& getAt(*la, 0) == getSmallest(*la))))
			parsing("pa", la, lb);
		else if (getAt(*lb, 0) > getBiggest(*la))
			parsing("pa", la, lb);
		else
			parsing("rra", la, lb);
	}
	sortLista5(la, lb);
}

void	sort_100(t_list **la, t_list **lb)
{
	int save;
	int	middle;
	int	min;
	int	i;

	min = getSmallest(*la);
	middle = median_finding(*la) / 4;
	save = -1;
	i = 1;
	while (i <= 4)
	{
		while (getPosFirst(*la, min, min + middle) != -1)
		{
			while (getAt(*la, 0) != getAt(*la,
					getPosFirst(*la, min, min + middle)))
				parsing("rra", la, lb);
			if (lenList(*lb) > 1)
				sortListb(la, lb);
			parsing("pb", la, lb);
		}
		i++;
		min += middle;
		push_lista(la, lb, &save);
	}
	sortLista(la, lb);
}

void	sort_500(t_list **la, t_list **lb)
{
	(void)lb;
	int pos_first;
	int pos_second;
	int save;
	int tab[12];
	int	i;

	getChunks(la, tab);
	save = -1;
	i = 0;
	while (i <= 11)
	{
		while (getPosFirst(*la, tab[i], tab[i + 1]) != -1)
		{
			pos_first = getPosFirst(*la, tab[i], tab[i + 1]);
			pos_second = getPosSecond(*la, tab[i], tab[i + 1]);
			if (pos_first >= pos_second)
				while (getPosFirst(*la, tab[i], tab[i + 1]) != 0)
					parsing("rra", la, lb);
			else
				while (getPosFirst(*la, tab[i], tab[i + 1]) != 0)
					parsing("ra", la, lb);
			if (lenList(*lb) > 1)
				sortListb(la, lb);
			parsing("pb", la, lb);
		}
		i++;
		tab[i] = tab[i] + 1;
		push_lista(la, lb, &save);
	}
	sortLista(la, lb);
}

void	algo(t_list **lista, t_list **listb)
{
	if (lenList(*lista) < 3)
		sort(lista, listb);
	else if (lenList(*lista) == 3)
		sort_3(lista, listb);
	else if (lenList(*lista) <= 5 && lenList(*lista) > 3)
		sort_5(lista, listb);
	else if (lenList(*lista) <= 100 && lenList(*lista) > 5)
		sort_100(lista, listb);
	else if (lenList(*lista) <= 500 && lenList(*lista) > 100)
		sort_500(lista, listb);
	else
		printf("Error\nToo many number injected");
}
