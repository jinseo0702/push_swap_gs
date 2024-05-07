/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   circle_link_stack.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinseo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 10:25:39 by jinseo            #+#    #+#             */
/*   Updated: 2024/05/07 10:25:40 by jinseo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void    ft_init_list(t_list *new)
{
    new = NULL;
    new->first_node = NULL;
    new->next = NULL;
    new->tail = NULL;
    new->num = NULL;
}

t_list *ft_circle_new(int n)
{
    t_list *new;
    
    new = (t_list *)malloc(sizeof(t_list));
    if (!new)
        return (NULL);
    ft_init_list(new);
    new->num = n;
    new->next = new;
    new->first_node = new;
    new->tail = new;
    return(new);
}

void    ft_insert_front(t_list *lst, int n)
{
    t_list *new_front;
    
    new_front = (t_list *)malloc(sizeof(t_list));
    if (!new_front || !lst)
        return ;
    ft_init_list(new_front);
    new_front->num = n;
    new_front->next = lst->first_node;
    lst->first_node = new_front;
    lst->tail->next = new_front;
}

void    ft_insert_back(t_list *lst, int n)
{
    t_list *new_last;
    
    new_last = (t_list *)malloc(sizeof(t_list));
    if (!new_last || !lst)
        return ;
    ft_init_list(new_last);
    new_last->num = n;
    new_last->next = lst->first_node;
    new_last->first_node = lst->first_node;
    lst->tail->next = new_last;
    lst->tail = new_last;
}

void    delete_lst(t_list **lst, int size)
{
    t_list *tmep;
    int     cmp;

    cmp = 0;
    tmep = *lst;
    // while (cmp < size)
    // {
    //     (*lst)->first_node        
    // }
}
