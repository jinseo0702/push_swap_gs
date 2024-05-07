/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinseo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 10:09:58 by jinseo            #+#    #+#             */
/*   Updated: 2024/05/07 10:10:02 by jinseo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
#include "../libft/libft.h"
#include <stdlib.h>
#include <unistd.h>

typedef struct s_list
{
    int num;
    struct s_list *first_node;
    struct s_list *next;
    struct s_list *tail;
} t_list;

typedef struct s_node
{
    int num;
    struct s_node   *prev;
    struct s_node   *next;
} t_node;

typedef struct s_stack
{
    struct s_node *top;
    struct s_node *bottom;
} t_stack;

void    ft_init_list(t_node *new);
t_node *ft_new_doubly(int num);
void    insert_front_Node(t_node *lst, int num);
t_node *ft_first_loca(int flag);
void    insert_back_Node(t_node *lst, int num);

#endif