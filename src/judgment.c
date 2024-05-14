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

void ft_judge(t_stack *stacka, t_stack *stackb, char **argv, int argc)
{
    if (argc >= 2)
        ft_argc_input(stacka, stackb, argv);
    else
        {
            ft_putendl_fd("Error", 2);
            ft_free_stack(stacka);
            ft_free_stack(stackb);
            exit(1);
        }
}

void ft_argc_input(t_stack *stack_a, t_stack *stack_b, char **argv)
{
    int idx;
    int idx_sp;
    static char **split_argv;

    idx = 1;
    idx_sp = 0;
    while (argv[idx] != NULL)
    {
    	if (ft_strncmp(argv[idx], "", 1) == 0)
    	{
		    ft_free_stack(stack_a);
            ft_free_stack(stack_b);
		    ft_putendl_fd("Error", 2);
		    exit(2);
	    }
        split_argv = ft_split(argv[idx], ' ');
        idx_sp = 0;
        while (split_argv[idx_sp])
        {
            ft_insert_node(stack_a, ft_new_node(ft_atoi_re(stack_b, stack_a, split_argv, idx_sp), stack_a));
            idx_sp++;
        }
        ft_strfree(split_argv, idx_sp);
        idx++;
    }
    ft_check_dup(stack_a, stack_b);
    ft_print_stack(stack_a);
}

void	ft_strfree(char **split_argv, int idx)
{
	int	i;
	int	size;

	i = 0;
	size = 0;
	while (size <= idx)
	{
		free(split_argv[i]);
		i++;
		size++;
	}
	free(split_argv);
    split_argv = NULL;
}