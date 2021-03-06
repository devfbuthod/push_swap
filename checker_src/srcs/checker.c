/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbuthod- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 11:34:41 by fbuthod-          #+#    #+#             */
/*   Updated: 2021/03/05 11:34:44 by fbuthod-         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/checker.h"

int	main(int argc, char **argv)
{
	t_list	*lista;
	t_list	*listb;

	(void)argc;
	lista = NULL;
	listb = NULL;
	lista = incr_list(lista, argv);
	if (lista == NULL)
		return (0);
	parsing(&lista, &listb);
	if (ft_verif(lista) && lenList(listb) == 0)
		printf("OK\n");
	else
		printf("KO\n");
	freeList(lista);
	freeList(listb);
	lista = NULL;
	listb = NULL;
	return (0);
}
