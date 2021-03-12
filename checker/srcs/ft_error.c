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

#include "./../includes/push_swap.h"

int ft_error(t_list *list, int code_erreur)
{
    ft_printf("Error\n");
    if (code_erreur == 1)
        ft_putstr("Some arguments are not integers\n");
    else if (code_erreur == 2)
        ft_putstr("Two parameters are duplicates\n");
    else if (code_erreur == 3)
        ft_putstr("Some arguments are bigger than an integer\n");
    else if (code_erreur == 4)
        ft_putstr("Instruction don’t exist and/or is incorrectly formatted\n");
    list = freeList(list);
    return (1);
}

int verif_dup(char *argv, t_list *list)
{
    int i;

    i = 0;
    while (list)
    {
        if (ft_atoi(argv) == list->data)
            return (1);
        list = list->next;
    }
    return (0);
}

int ft_error_parser(char *argv, t_list *list)
{
    int i;

    i = 0;
    if ((ft_atoi(argv) >= 2147483648) || ((ft_atoi(argv) <= -2147483649)))
        return (ft_error(list, 3));
    if (argv[0] == '-' || argv[0] == '+')
        i++;
    if (!(ft_allisdigit(&argv[i])))
        return (ft_error(list, 1));
    if (list)
    {
        if (verif_dup(argv, list))
            return (ft_error(list, 2));
    }
    return (0);
}
