/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   judgment.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinseo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 16:47:30 by jinseo            #+#    #+#             */
/*   Updated: 2024/05/08 16:47:31 by jinseo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int ft_is_mix2_2(char **split_argv)
{
    int idx;

    idx = 0;
    while (split_argv[idx])
        idx++;
    return (idx);
}

void ft_judge(t_stack *stacka, t_stack *stackb, char **argv, int argc)
{
    if (argc > 2)
        ft_argc_over2_2(stacka, argv);
    else if (argc == 2)
        ft_argc_like2_2(stacka, argv);
    else
        {
            ft_putendl_fd("Error", 2);
            ft_free_stack(stacka);
            ft_free_stack(stackb);
            exit(1);
        }
}

void ft_argc_over2_2(t_stack *stack, char **argv)
{
    int idx;

    idx = 1;
    char **split_argv;
    while (argv[idx])
    {
        ft_insert_node(stack, ft_new_node(ft_atoi(argv[idx]), stack));
        idx++;
    }
    ft_print_stack(stack);

    
}

void ft_argc_like2_2(t_stack *stack, char **argv)
{
    char **split_argv;
    int idx;
    
    idx = 0;
    split_argv = ft_split(argv[1], ' ');
    while (split_argv[idx])
    {
        ft_insert_node(stack, ft_new_node(ft_atoi(split_argv[idx]), stack));
        idx++;
    }
    ft_print_stack(stack);
}