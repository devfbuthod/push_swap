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

void push_listb(t_list **la, t_list **lb, int max)
{
    int ret;
    int i;

    i = 1;
    ret = 0;
    while (lenList(*la) != 0)
    {
        while (ret == 0)
        {
            ret = sortLista(la, lb, i, max);
            if (lenList(*lb) > 1)
                sortListb(la, lb);
            parsing("pb", la, lb);
        }
        ret = 0;
        i++;
    }
}

void push_lista(t_list **la, t_list **lb)
{
    int pos_first;
    int pos_second;

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
