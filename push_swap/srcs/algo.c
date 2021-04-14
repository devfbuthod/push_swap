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

void	sort(t_list **la, t_list **listb)
{
	if (getAt(*la, 0) > getAt(*la, 1))
		parsing("ra", la, listb);
}

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
    else if (getAt(*la, 0) > getAt(*la, 1) && getAt(*la, 1) < getAt(*la, 2) &&
        getAt(*la, 2) < getAt(*la, 0))
        parsing("ra", la, listb);
    else if (getAt(*la, 0) < getAt(*la, 1) && getAt(*la, 1) > getAt(*la, 2) &&
        getAt(*la, 2) > getAt(*la, 0))
    {
        parsing("sa", la, listb);
        parsing("ra", la, listb);
    }
    else if (getAt(*la, 0) < getAt(*la, 1) && getAt(*la, 1) > getAt(*la, 2) &&
        getAt(*la, 2) < getAt(*la, 0))
        parsing("rra", la, listb);
}

void	sort_5(t_list **la, t_list **lb)
{
    while (lenList(*la) != 3)
        parsing("pb", la, lb);
    sort_3(la, lb);
    while (lenList(*lb) != 0)
    {
        if ((getAt(*la, 0) > getAt(*lb, 0) && getAt(*la, lenList(*la) - 1) < getAt(*lb, 0)) || ((getAt(*la, 0) > getAt(*lb, 0) && getAt(*la, 0) == getSmallest(*la))))
            parsing("pa", la, lb);
        else if (getAt(*lb, 0) > getBiggest(*la))
        {
            parsing("pa", la, lb);
            parsing("ra", la, lb);
        }
        else
            parsing("ra", la, lb);
    }
    while (getAt(*la, 0) > getAt(*la, 1) || getAt(*la, 0) > getAt(*la, lenList(*la) - 1))
        parsing("ra", la, lb);
}

void	sort_100(t_list **la, t_list **lb)
{
    int quart;
    int min;
    int max;
    int i;
    int pos_first;
    int pos_second;

    min = getSmallest(*la);
    quart = median_finding(*la) / 4;
    max = min + quart;
    i = 1;
    while (i <= 4)
    {
        while (getPosFirst(*la, min, max) != -1)
        {
            while (getAt(*la, 0) != getAt(*la, getPosFirst(*la, min, max)))
                parsing("rra", la, lb);
            if (lenList(*lb) > 1)
                sortListb(la, lb);
            parsing("pb", la, lb);
        }
        i++;
        max += quart;
        if (i == 4)
            max = getBiggest(*la);
        min += quart;
        push_lista(la, lb);
    }
    pos_first = getPos(*la, getSmallest(*la));
    pos_second = lenList(*la) - pos_first;
    if (pos_first >= pos_second && pos_first != 0)
        while (getAt(*la, 0) != getSmallest(*la))
            parsing("ra", la, lb);
    else
        while (getAt(*la, 0) != getSmallest(*la))
            parsing("rra", la, lb);
}

void	sort_500(t_list **la, t_list **lb)
{
    int quart;
    int min;
    int max;
    int i;
    int pos_first;
    int pos_second;

    min = getSmallest(*la);
    quart = median_finding(*la) / 8;
    max = min + quart;
    i = 1;
    while (i <= 8)
    {
        while (getPosFirst(*la, min, max) != -1)
        {
            while (getAt(*la, 0) != getAt(*la, getPosFirst(*la, min, max)))
                parsing("rra", la, lb);
            if (lenList(*lb) > 1)
                sortListb(la, lb);
            parsing("pb", la, lb);
        }
        i++;
        max += quart;
        if (i == 8)
            max = getBiggest(*la);
        min += quart;
        push_lista(la, lb);
    }
    pos_first = getPos(*la, getSmallest(*la));
    pos_second = lenList(*la) - pos_first;
    if (pos_first >= pos_second && pos_first != 0)
        while (getAt(*la, 0) != getSmallest(*la))
            parsing("ra", la, lb);
    else
        while (getAt(*la, 0) != getSmallest(*la))
            parsing("rra", la, lb);
}

void algo(t_list **lista, t_list **listb)
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
    if (ft_verif(*lista) && lenList(*listb) == 0)
        ft_putstr("OK\n");
    else
        ft_putstr("KO\n");
}