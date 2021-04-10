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

void sort(t_list **la, t_list **listb)
{
    if (getAt(*la, 0) > getAt(*la, 1))
        parsing("ra", la, listb);
}

void sort_3(t_list **la, t_list **listb)
{
    if (getAt(*la, 0) > getAt(*la, 1) && getAt(*la, 1) < getAt(*la, 2) &&
        getAt(*la, 2) > getAt(*la, 0))
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

void sort_5(t_list **la, t_list **lb)
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

void sort_100(t_list **la, t_list **lb)
{
    (void)*lb;
    int pos_first;
    int pos_second;
    int i;

    i = 1;
    while (lenList(*la) != 0)
    {
        while (1)
        {
            pos_first = getPosFirst(*la, 0, 20 * i);
            if (pos_first == -1)
                break ;
            pos_second = getPosSecond(*la, 0, 20 * i);
            if (pos_first <= pos_second && pos_first != 0)
            {
                while (pos_first > 0)
                {
                    parsing("ra", la, lb);
                    pos_first--;
                }
            }
            else if (pos_first > pos_second && pos_second != 0)
            {
                while (pos_second > 0)
                {
                    parsing("rra", la, lb);
                    pos_second--;
                }
            }
            if (lenList(*lb) > 1)
            {
                if (getBiggest(*lb) < getAt(*la, 0))
                {
                    pos_first = getPos(*lb, getBiggest(*lb));
                    pos_second = lenList(*lb) - pos_first;
                    if (pos_first >= pos_second && pos_first != 0)
                        while (getAt(*lb, 0) != getBiggest(*lb))
                            parsing("rrb", la, lb);
                    else
                        while (getAt(*lb, 0) != getBiggest(*lb))
                            parsing("rb", la, lb);
                }
                else if (getSmallest(*lb) > getAt(*la, 0))
                {
                    pos_first = getPos(*lb, getSmallest(*lb));
                    pos_second = lenList(*lb) - pos_first;
                    if (pos_first >= pos_second && pos_first != 0)
                        while (getAt(*lb, lenList(*lb) - 1) != getSmallest(*lb))
                            parsing("rrb", la, lb);
                    else
                        while (getAt(*lb, lenList(*lb) - 1) != getSmallest(*lb))
                            parsing("rb", la, lb);
                }
                else
                {
                    pos_first = getPos(*lb, getAt(*la, 0));
                    pos_second = lenList(*lb) - pos_first;
                    if (pos_first >= pos_second && pos_first != 0)
                        while (!(getAt(*la, 0) < getAt(*lb, lenList(*lb) - 1) && getAt(*la, 0) > getAt(*lb, 0)))
                            parsing("rrb", la, lb);
                    else if (pos_first < pos_second && pos_second != 0)
                        while (!(getAt(*la, 0) < getAt(*lb, lenList(*lb) - 1) && getAt(*la, 0) > getAt(*lb, 0)))
                            parsing("rb", la, lb);
                }
            }
            parsing("pb", la, lb);
        }
        i++;
    }
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

void sort_500(t_list **la, t_list **lb)
{
    (void)*lb;
    int pos_first;
    int pos_second;
    int i;

    i = 1;
    while (lenList(*la) != 0)
    {
        while (1)
        {
            pos_first = getPosFirst(*la, 0, 45 * i);
            if (pos_first == -1)
                break ;
            pos_second = getPosSecond(*la, 0, 45 * i);
            if (pos_first <= pos_second && pos_first != 0)
            {
                while (pos_first > 0)
                {
                    parsing("ra", la, lb);
                    pos_first--;
                }
            }
            else if (pos_first > pos_second && pos_second != 0)
            {
                while (pos_second > 0)
                {
                    parsing("rra", la, lb);
                    pos_second--;
                }
            }
            if (lenList(*lb) > 1)
            {
                if (getBiggest(*lb) < getAt(*la, 0))
                {
                    pos_first = getPos(*lb, getBiggest(*lb));
                    pos_second = lenList(*lb) - pos_first;
                    if (pos_first >= pos_second && pos_first != 0)
                        while (getAt(*lb, 0) != getBiggest(*lb))
                            parsing("rrb", la, lb);
                    else
                        while (getAt(*lb, 0) != getBiggest(*lb))
                            parsing("rb", la, lb);
                }
                else if (getSmallest(*lb) > getAt(*la, 0))
                {
                    pos_first = getPos(*lb, getSmallest(*lb));
                    pos_second = lenList(*lb) - pos_first;
                    if (pos_first >= pos_second && pos_first != 0)
                        while (getAt(*lb, lenList(*lb) - 1) != getSmallest(*lb))
                            parsing("rrb", la, lb);
                    else
                        while (getAt(*lb, lenList(*lb) - 1) != getSmallest(*lb))
                            parsing("rb", la, lb);
                }
                else
                {
                    pos_first = getPos(*lb, getAt(*la, 0));
                    pos_second = lenList(*lb) - pos_first;
                    if (pos_first >= pos_second && pos_first != 0)
                        while (!(getAt(*la, 0) < getAt(*lb, lenList(*lb) - 1) && getAt(*la, 0) > getAt(*lb, 0)))
                            parsing("rrb", la, lb);
                    else if (pos_first < pos_second && pos_second != 0)
                        while (!(getAt(*la, 0) < getAt(*lb, lenList(*lb) - 1) && getAt(*la, 0) > getAt(*lb, 0)))
                            parsing("rb", la, lb);
                }
            }
            parsing("pb", la, lb);
        }
        i++;
    }
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