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

int	ft_verif(t_list *list)
{
	int	prev;

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

int	getPosFirst(t_list *la, int min, int max)
{
	int	i;

	i = 0;
	while (la)
	{
		if (la->data >= min && la->data <= max)
			return (i);
		la = la->next;
		i++;
	}
	return (-1);
}

int	getPosSecond(t_list *la, int min, int max)
{
	int	i;
	int temp;

	i = 0;
	temp = 0;
	while (la)
	{
		if (la->data >= min && la->data <= max)
			temp = i;
		la = la->next;
		i++;
	}
	if (temp != 0)
		return (i - temp);
	return (-1);
}

int	getPos(t_list *la, int value)
{
	int	i;

	i = 0;
	while (la && value != la->data)
	{
		i++;
		la = la->next;
	}
	return (i);
}

int getPosBetween(t_list *la, int value)
{
	int i;

	i = 0;
	
	if (value < getAt(la, lenList(la) - 1) && value > getAt(la, 0))
		i = 1;
	else if (value < getAt(la, 0) && value > getAt(la, lenList(la) - 1))
		i = lenList(la) - 1;
	else
	{
		while (la && !(value < getAt(la, 0) && value > getAt(la, 1)))
		{
			i++;
			la = la->next;
		}
	}
	return (i);
}

int	lenList(t_list *list)
{
	int	i;

	i = 0;
	while (list)
	{
		i++;
		list = list->next;
	}
	return (i);
}
