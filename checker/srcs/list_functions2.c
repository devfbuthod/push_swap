/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_functions2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbuthod- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 11:39:28 by fbuthod-          #+#    #+#             */
/*   Updated: 2021/03/05 11:39:30 by fbuthod-         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/checker.h"

int getAt(t_list *list, int pos)
{
    int i;

    i = 0;
    if (isEmptyList(list))
        return (-1);
    while (i < pos)
    {
        list = list->next;
        i++;
    }
    return (list->data);
}

int printList(t_list *list)
{
    int i;

    i = 0;
    if (isEmptyList(list))
        return (-1);
    while (list)
    {
        ft_printf("%d \n", (int)(list->data));
        list = list->next;
        i++;
    }
    return (0);
}

t_list *free_and_ret(t_list *to_free, t_list *to_ret)
{
    if (to_free)
        freeList(to_free);
    return (to_ret);
}

int ft_verif(t_list *list)
{
    int prev;

    if (lenList(list) == 0)
        return (0);
    if (list->data < 0)
        prev = -2147483648;
    else
        prev = 0;
    while (list)
    {
        if (list->data >= prev)
        {
            prev = list->data;
            list = list->next;
        }
        else
            return (0);
    }
    return (1);
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