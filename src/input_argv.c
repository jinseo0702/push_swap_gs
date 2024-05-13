/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_argv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinseo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 15:20:19 by jinseo            #+#    #+#             */
/*   Updated: 2024/05/08 15:20:23 by jinseo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void    ft_print_stack(t_stack *stack)
{
    t_node *temp;
    t_node *next;

    temp = stack->top;
    while (temp)
    {
        next = temp->next;
        ft_printf("%d\n", temp->num);
        temp = next;
    }
}

// void    ft_check_dup(t_stack *stack)
// {
//     t_node *temp;
//     t_node *next;

//     temp = stack->top;
//     while (temp)
//     {
//         next = temp->next;
//         ft_printf("%d\n", temp->num);
//         temp = next;
//     }
// }