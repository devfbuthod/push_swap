/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbuthod- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 14:31:14 by fbuthod-          #+#    #+#             */
/*   Updated: 2021/03/08 14:31:16 by fbuthod-         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/push_swap.h"

t_list	*rotate_rev(t_list *list)
{
	t_list	*listTemp;
	t_list	*listTemp2;
	int		temp;

	listTemp = list;
	listTemp2 = NULL;
	while (listTemp)
	{
		temp = listTemp->data;
		listTemp2 = listTemp;
		listTemp = listTemp->next;
		if (listTemp)
			listTemp->prev = listTemp2;
		else
		{
			listTemp = listTemp2;
			break ;
		}
	}
	listTemp2 = listTemp2->prev;
	free(listTemp2->next);
	listTemp2->next = NULL;
	addAt(&list, temp, 0);
	return (list);
}

t_list	*rotate_up(t_list *list)
{
	int		len;
	int		temp;
	t_list	*temp2;

	len = lenList(list);
	temp = list->data;
	temp2 = list;
	list = list->next;
	free(temp2);
	addAt(&list, temp, len - 1);
	return (list);
}

t_list	*push(t_list **src, t_list *dest)
{
	t_list	*temp;

	temp = *src;
	if (!*src)
		return (dest);
	addAt(&dest, (*src)->data, 0);
	*src = (*src)->next;
	free(temp);
	return (dest);
}

t_list	*swap(t_list *list)
{
	t_list	*temp;
	t_list	*temp2;

	temp = list;
	temp2 = list->next;
	temp->next = temp2->next;
	temp2->next = temp;
	temp = NULL;
	return (temp2);
}

t_list	*incr_list(t_list *list, char **argv)
{
	int	i;

	i = 1;
	while (argv[i])
	{
		if (ft_error_parser(argv[i], list))
			return (NULL);
		addAt(&list, ft_atoi(argv[i]), i - 1);
		i++;
	}
	return (list);
}
