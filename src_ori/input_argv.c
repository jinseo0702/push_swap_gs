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

t_node    *ft_inputargv(int argc, char ***argv, t_node *new1, int flag)
{
    t_node *cur;
    
    cur = new1;
    if (flag == 0)
    {
        while(--argc > 0)
        {
            insert_front_Node(cur, ft_atoi((*argv)[argc]));
            new1 = new1->prev;
            cur = new1;
        }
    }
    else if (flag == 1)
    {
        while(argc-- > 0)
        {
            insert_front_Node(cur, ft_atoi((*argv)[argc]));
            new1 = new1->prev;
            cur = new1;
        }
    }
    return (cur);
}

void    ft_print_list(t_node *new1)
{
    while(new1->next != NULL)
    {
        ft_printf("%d ", new1->num);
        new1 = new1->next;
    }
    ft_printf("\n");
}

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