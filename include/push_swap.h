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

// add + pcmver.double linked list
void    ft_init_list(t_node *new);
t_stack *ft_creat_stack(void);
void ft_insert_node(t_stack *stack, t_node *node);
t_node *ft_new_node(int num, t_stack *stack);
void    ft_free_stack(t_stack *stack);
//in input_argv
void ft_print_stack(t_stack *stack);
//ver.2 judgment
void ft_argc_over2_2(t_stack *stack, char **argv);
int ft_is_mix2_2(char **split_argv);
void ft_judge(t_stack *stacka, t_stack *stackb, char **argv, int argc);
void ft_argc_like2_2(t_stack *stack, char **argv);
void	ft_strfree(char **split_argv, int idx);
//command_push.c
void pb(t_stack *stack_a, t_stack *stack_b);
void pa(t_stack *stack_a, t_stack *stack_b);
//command_swap.c
void sa(t_stack *a);
void sb(t_stack *b);
void ss(t_stack *a, t_stack *b);
//command_reverse.c
void ra(t_stack *a);
void rb(t_stack *b);
void rr(t_stack *a, t_stack *b);

#endif
