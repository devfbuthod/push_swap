/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbuthod- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 11:37:27 by fbuthod-          #+#    #+#             */
/*   Updated: 2021/03/05 11:37:30 by fbuthod-         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/push_swap.h"

int isEmptyList(t_list *list)
{
    return list == NULL;
}

t_list *createCell(int data)
{
    t_list *cell = malloc(sizeof(t_list));
    if (!cell)
        return (NULL);
    cell->data = data;
    cell->next = NULL;

    return (cell);
}

void addAt(t_list **list, int data, int pos)
{
    t_list *prec = *list;
    t_list *cur = *list;
    int i;

    i = 0;
    t_list *cell = createCell(data);
    if (isEmptyList(*list))
        *list = cell;
    else if (pos == 0)
    {
        cell->next = *list;
        *list = cell;
    }
    else
    {
        while (i < pos)
        {
            i++;
            prec = cur;
            cur = cur->next;
        }
        prec->next = cell;
        cell->next = cur;
    }
}

t_list *freeList(t_list *list)
{
    t_list *tmp = NULL;
    while (list)
    {
        tmp = list->next;
        free(list);
        list = tmp;
    }
    return (list);
}

int lenList(t_list *list)
{
    int i;

    i = 0;
    while (list)
    {
        i++;
        list = list->next;
    }
    return (i);
}
