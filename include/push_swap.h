/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinseo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 10:09:58 by jinseo            #+#    #+#             */
/*   Updated: 2024/05/08 16:41:22 by jinseo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
#include "../libft/libft.h"
#include "../ft_printf/libftprintf.h"
#include <stdlib.h>
#include <unistd.h>

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
    int size;
} t_stack;

void    ft_init_list(t_node *new);
t_node *ft_new_doubly(int num);
void    insert_front_Node(t_node *lst, int num);
t_node *ft_first_loca(int flag);
void    insert_back_Node(t_node *lst, int num);
t_node    *ft_inputargv(int argc, char ***argv, t_node *new1, int flag);
void    ft_print_list(t_node *new1);
void ft_argc_over2(t_node **new1, char **argv, int num);
void ft_argc_like2(t_node **new1, char **argv, int num);
// add + pcmver.double linked list
void    ft_init_list2(t_node *new);
t_stack *ft_creat_stack(void);
void ft_insert_node(t_stack *stack, t_node *node);
t_node *ft_new_node(int num, t_stack *stack);
void    ft_free_stack(t_stack *stack);
// finish_pcm.ver
//in input_argv
void ft_print_stack(t_stack *stack);
//
#endif
