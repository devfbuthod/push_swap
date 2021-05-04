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

void	push_lista(t_list **la, t_list **lb, int *save)
{
	int	pos_first;
	int	pos_second;

	pos_first = getPos(*lb, getBiggest(*lb));
	pos_second = lenList(*lb) - pos_first;
	if (pos_first >= pos_second && pos_first != 0)
		while (getAt(*lb, 0) != getBiggest(*lb)
			&& lenList(*lb) > 1)
			parsing("rrb", la, lb);
	else
		while (getAt(*lb, 0) != getBiggest(*lb)
			&& lenList(*lb) > 1)
			parsing("rb", la, lb);
	if (*save != -1)
	{
		pos_first = getPos(*la, *save);
		pos_second = lenList(*la) - pos_first;
		if (pos_first >= pos_second)
			while (getAt(*la, lenList(*la) - 1) != *save)
				parsing("rra", la, lb);
		else
			while (getAt(*la, lenList(*la) - 1) != *save)
				parsing("ra", la, lb);
	}
	*save = getBiggest(*lb);
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

void sort_list(t_list *la, int *tab)
{
    int len;
    int i;
    int j;
    int temp;

    i = 0;
    j = 0;
    temp = 0;
    len = lenList(la);
    while (la)
    {
        tab[i] = la->data;
        la = la->next;
        i++;
    }
    i = 0;
    while (i < len)
    {
        while (j < len - 1)
        {
            if (tab[j] > tab[j + 1])
            {
                temp = tab[j + 1];
                tab[j + 1] = tab[j];
                tab[j] = temp;
            }
            j++;
        }
        j = 0;
        i++;
    }
}

void	getChunks(t_list **la, int *tab2)
{
	int	tab[lenList(*la)];
	int i;
	int j;

	i = 0;
	j = 0;
	sort_list(*la, tab);
	tab2[j] = getSmallest(*la);
	j++;
	while (i < lenList(*la))
	{
		while (i < lenList(*la) * j / 11)
			i++;
		if (j == 11)
		{
			tab2[j] = getBiggest(*la);
			tab2[j + 1] = 0;
			break;
		}
		tab2[j] = tab[i];
		j++;
	}
}
