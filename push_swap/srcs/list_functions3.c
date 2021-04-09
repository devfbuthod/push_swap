/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_functions3.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbuthod- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 12:40:40 by fbuthod-          #+#    #+#             */
/*   Updated: 2021/04/09 12:40:41 by fbuthod-         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int ft_verif(t_list *list)
{
    int prev;

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

int getPosFirst(t_list *la, int min, int max)
{
    int i;

    i = 1;
    while (la)
    {
        if (la->data >= min && la->data <= max)
            return (i);
        la = la->next;
        i++;
    }
    return (-1);
}

int getPosSecond(t_list *la, int min, int max)
{
    int i;
    int temp;

    t_list *listTemp = la;
    t_list *listTemp2 = NULL;
    i = 1;
    while (listTemp)
    {
        temp = listTemp->data;
        listTemp2 = listTemp;
        listTemp = listTemp->next;
        if (listTemp)
            listTemp->prev = listTemp2;
        if (listTemp == NULL)
        {
            listTemp = listTemp2;
            break ;
        }
    }
    while (listTemp2->prev)
    {
        if (listTemp2->data >= min && listTemp2->data <= max)
            return (i);
        listTemp2 = listTemp2->prev;
        i++;
    }
    return (-1);
}

/*int getPosSecond(*la)
{

}*/