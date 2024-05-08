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

t_node    *ft_inputargv(int argc, char ***argv, t_node *new1)
{
    t_node *cur;
    
    cur = new1;
    while(--argc > 0)
    {
        insert_front_Node(cur, ft_atoi((*argv)[argc]));
        new1 = new1->prev;
        cur = new1;
    }
    return (cur);
}