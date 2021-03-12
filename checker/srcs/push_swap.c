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

/*void algo(t_list **lista, t_list **listb)
{
    if (*lista->data > *lista->prev->data && *lista->data < *list->next->data)
        rotate_rev(*lista);
}*/

t_list *loop_list(t_list *lista)
{
    t_list *temp = NULL;
    t_list *temp2 = lista;

    while (lista)
    {
        lista->prev = temp;
        temp = lista;
        lista = lista->next;
    }
    lista = temp;
    lista->next = temp2;
    lista = lista->next;
    return (lista);
}

int main(int argc, char **argv)
{
    argc = 0;
    
    t_list *lista = NULL;
    t_list *listb = NULL;
    lista = incr_list(lista, argv);
    if (lista == NULL)
        return (0);
    lista = loop_list(lista);
    //algo(&lista, &listb);
    if (ft_verif(lista) && lenList(listb) == 0)
        ft_putstr("OK\n");
    else
        ft_putstr("KO\n");
    freeList(lista);
    freeList(listb);
    lista = NULL;
    listb = NULL;
    return (0);
}
