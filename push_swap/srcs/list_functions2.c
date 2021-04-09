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

#include "./../includes/push_swap.h"

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

int getBiggest(t_list *list)
{
    int i;
    int nbr;

    nbr = -2147483648;
    i = 0;
    while (list)
    {
        if (nbr < list->data)
            nbr = list->data;
        list = list->next;
    }
    return (nbr);
}

int getSmallest(t_list *list)
{
    int i;
    int nbr;

    nbr = 2147483647;
    i = 0;
    while (list)
    {
        if (nbr > list->data)
            nbr = list->data;
        list = list->next;
    }
    return (nbr);
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