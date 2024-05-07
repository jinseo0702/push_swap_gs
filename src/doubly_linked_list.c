/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dobly_linked_list.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinseo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 12:13:45 by jinseo            #+#    #+#             */
/*   Updated: 2024/05/07 12:13:46 by jinseo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void    ft_init_list(t_node *new)
{
    new->prev = NULL;
    new->next = NULL;
    new->num = 0;
}

t_node *ft_first_loca(int flag)
{
    t_node *tmp;
    
    flag += 1;
    tmp = (t_node *)malloc(sizeof(t_node));
    if (!tmp)
        return (NULL);
    ft_init_list(tmp);
    return (tmp);
}

t_node *ft_new_doubly(int num)
{
    t_stack *new;

    new = (t_stack *)malloc(sizeof(t_stack));
    if (!new)
    {
        ft_putstr_fd("Error\n", 2);
        return (NULL);
    }
    new->top = ft_first_loca(1);
    new->bottom = ft_first_loca(1);
    if (!(new->top) || !(new->bottom))
    {
        ft_putstr_fd("Error\n", 2);
        return (NULL);
    }   
    new->top->num = num;
    new->top->next = new->bottom;
    new->bottom->prev = new->top;
    return (new->top);
}

void    insert_front_Node(t_node *lst, int num)
{
    t_node *cur;
    t_node *new_front;

    cur = lst;
    new_front = (t_node *)malloc(sizeof(t_node));
    if (!new_front)
    {
        ft_putstr_fd("Error\n", 2);
        return ;
    }
    ft_init_list(new_front);
    new_front->num = num;
    if (lst->prev == NULL)
    {
        new_front->next = lst;
        lst->prev = new_front;
    }
    else
    {
        ft_putstr_fd("Error\n", 2);
        return ;
    }
}