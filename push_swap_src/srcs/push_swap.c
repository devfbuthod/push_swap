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

#include "./../includes/push_swap.h"

int	main(int argc, char **argv)
{
	t_list	*lista;
	t_list	*listb;

	(void)argc;
	lista = NULL;
	lista = incr_list(lista, argv);
	listb = NULL;
	if (lista == NULL)
		return (0);
	else if (lenList(lista) == 1 || ft_verif(lista))
	{
		freeList(lista);
		return (0);
	}
	algo(&lista, &listb);
	if (ft_verif(lista) && lenList(listb) == 0)
		printf("OK\n");
	else
		printf("KO\n");
	/*printList(lista);
	printf("-------------------\n");
	printList(listb);*/
	freeList(lista);
	freeList(listb);
	lista = NULL;
	listb = NULL;
	return (0);
}
