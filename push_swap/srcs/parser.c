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

#include "./../includes/push_swap.h"

void parse_swap(t_list **lista, t_list **listb, char* buffer)
{
    if (ft_strcmp(buffer, "sa") == 0 && lenList(*lista) != 0)
        *lista = swap(*lista);
    else if (ft_strcmp(buffer, "sb") == 0 && lenList(*listb) != 0)
        *listb = swap(*listb);
    else if (ft_strcmp(buffer, "ss") == 0)
    {
        if (lenList(*lista) != 0)
            *lista = swap(*lista);
        if (lenList(*listb) != 0)
            *listb = swap(*listb);
    }
    else
       ft_putstr("Instruction don’t exist and/or is incorrectly formatted\n");
}

void parse_push(t_list **lista, t_list **listb, char* buffer)
{
    if (ft_strcmp(buffer, "pa") == 0)
        *lista = push(&*listb, *lista);
    else if (ft_strcmp(buffer, "pb") == 0)
        *listb = push(&*lista, *listb);
    else
       ft_putstr("Instruction don’t exist and/or is incorrectly formatted\n");
}

void parse_rotate(t_list **lista, t_list **listb, char* buffer)
{
    if (ft_strcmp(buffer, "ra") == 0 && lenList(*lista) != 0)
        *lista = rotate_up(*lista);
    else if (ft_strcmp(buffer, "rb") == 0 && lenList(*listb) != 0)
        *listb = rotate_up(*listb);
    else if (ft_strcmp(buffer, "rra") == 0 && lenList(*lista) != 0)
        *lista = rotate_rev(*lista);
    else if (ft_strcmp(buffer, "rrb") == 0 && lenList(*listb) != 0)
        *listb = rotate_rev(*listb);
    else if (ft_strcmp(buffer, "rr") == 0)
    {
        if (lenList(*lista) != 0)
            *lista = rotate_up(*lista);
        if (lenList(*listb) != 0)
            *listb = rotate_up(*listb);
    }
    else if (ft_strcmp(buffer, "rrr") == 0)
    {
        if (lenList(*lista) != 0)
            *lista = rotate_rev(*lista);
        if (lenList(*listb) != 0)
            *listb = rotate_rev(*listb);
    }
    else
        ft_putstr("Instruction don’t exist and/or is incorrectly formatted\n");
}

int parsing(char *cmd, t_list **lista, t_list **listb)
{
    if (cmd[0] == 's')
        parse_swap(lista, listb, cmd);
    else if (cmd[0] == 'p')
        parse_push(lista, listb, cmd);
    else if (cmd[0] == 'r')
        parse_rotate(lista, listb, cmd);
    printList(*lista);
    printf("a\n---\n");
    printList(*listb);
    printf("b\n");
    printf("\n\n\n");
    return (0);
}
