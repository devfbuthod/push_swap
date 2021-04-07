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

t_list sort_3(t_list **lista)
{
    t_list tmp = *lista;
    
}

void algo(t_list **lista, t_list **listb)
{
    if (lenList(*lista) == 3 && lenList(*listb) == 0)
        *lista = sort_3(*lista);
    
}

int main(int argc, char **argv)
{
    argc = 0;
    
    t_list *lista = NULL;
    t_list *listb = NULL;
    lista = incr_list(lista, argv);
    if (lista == NULL)
        return (0);
    algo(&lista, &listb);
    /*if (ft_verif(lista) && lenList(listb) == 0)
        ft_putstr("OK\n");
    else
        ft_putstr("KO\n");*/
    freeList(lista);
    freeList(listb);
    lista = NULL;
    listb = NULL;
    return (0);
}
