/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbuthod- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 15:17:19 by fbuthod-          #+#    #+#             */
/*   Updated: 2021/03/09 15:17:22 by fbuthod-         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/checker.h"

int	ft_error(t_list *list, int code_erreur)
{
	printf("Error\n");
	if (code_erreur == 1)
		printf("Some arguments are not integers\n");
	else if (code_erreur == 2)
		printf("Two parameters are duplicates\n");
	else if (code_erreur == 3)
		printf("Some arguments are bigger than an integer\n");
	else if (code_erreur == 4)
		printf("Instruction don’t exist and/or is incorrectly formatted\n");
	list = freeList(list);
	return (1);
}

int	verif_dup(char *argv, t_list *list)
{
	int	i;

	i = 0;
	while (list)
	{
		if (ft_atoi(argv) == list->data)
			return (1);
		list = list->next;
	}
	return (0);
}

int	ft_error_parser(char *argv, t_list *list)
{
	int	i;

	i = 0;
	if (ft_strlen(argv) == 1 && (argv[0] == '-' || argv[0] == '+'))
		return (ft_error(list, 1));
	if (ft_strlen(argv) >= 12)
		return (ft_error(list, 3));
	if ((ft_atoi(argv) >= 2147483648) || ((ft_atoi(argv) <= -2147483649)))
		return (ft_error(list, 3));
	if (argv[0] == '-' || argv[0] == '+')
		i++;
	if (ft_allisdigit(&argv[i]) == 0)
		return (ft_error(list, 1));
	if (list)
	{
		if (verif_dup(argv, list))
			return (ft_error(list, 2));
	}
	return (0);
}
