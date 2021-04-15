/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbuthod- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 13:32:14 by fbuthod-          #+#    #+#             */
/*   Updated: 2021/03/09 13:32:22 by fbuthod-         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/checker.h"

void	parse_swap(t_list **lista, t_list **listb, char *buffer)
{
	if (ft_strcmp(buffer, "sa") == 0 && testLen(lista) == 0)
		*lista = swap(*lista);
	else if (ft_strcmp(buffer, "sb") == 0 && testLen(listb) == 0)
		*listb = swap(*listb);
	else if (ft_strcmp(buffer, "ss") == 0)
	{
		if (testLen(lista) == 0)
			*lista = swap(*lista);
		if (testLen(listb) == 0)
			*listb = swap(*listb);
	}
	else
		printf("Instruction don’t exist and/or is incorrectly formatted\n");
}

void	parse_push(t_list **lista, t_list **listb, char *buffer)
{
	if (ft_strcmp(buffer, "pa") == 0)
		*lista = push(&*listb, *lista);
	else if (ft_strcmp(buffer, "pb") == 0)
		*listb = push(&*lista, *listb);
	else
		printf("Instruction don’t exist and/or is incorrectly formatted\n");
}

void	parse_rotate(t_list **lista, t_list **listb, char *buffer)
{
	if (ft_strcmp(buffer, "ra") == 0 && testLen(lista) == 0)
		*lista = rotate_up(*lista);
	else if (ft_strcmp(buffer, "rb") == 0 && testLen(listb) == 0)
		*listb = rotate_up(*listb);
	else if (ft_strcmp(buffer, "rra") == 0 && testLen(lista) == 0)
		*lista = rotate_rev(*lista);
	else if (ft_strcmp(buffer, "rrb") == 0 && testLen(listb) == 0)
		*listb = rotate_rev(*listb);
	else if (ft_strcmp(buffer, "rr") == 0)
	{
		if (testLen(lista) == 0)
			*lista = rotate_up(*lista);
		if (testLen(listb) == 0)
			*listb = rotate_up(*listb);
	}
	else if (ft_strcmp(buffer, "rrr") == 0)
	{
		if (testLen(lista) == 0)
			*lista = rotate_rev(*lista);
		if (testLen(listb) == 0)
			*listb = rotate_rev(*listb);
	}
	else
		printf("Instruction don’t exist and/or is incorrectly formatted\n");
}

int	parsing(t_list **lista, t_list **listb)
{
	char	*line;
	int		ret;

	ret = get_next_line(0, &line);
	while (ret > 0)
	{
		if (line[0] == 's')
			parse_swap(lista, listb, line);
		else if (line[0] == 'p')
			parse_push(lista, listb, line);
		else if (line[0] == 'r')
			parse_rotate(lista, listb, line);
		else
		{
			printf("Instruction don’t exist and/or ");
			printf("is incorrectly formatted\n");
		}
		free(line);
		line = NULL;
		ret = get_next_line(0, &line);
	}
	free(line);
	line = NULL;
	return (0);
}
