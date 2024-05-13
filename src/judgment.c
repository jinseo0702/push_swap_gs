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
    if (argc > 2)
        ft_argc_input(stacka, argv);
    else
        {
            ft_putendl_fd("Error", 2);
            ft_free_stack(stacka);
            ft_free_stack(stackb);
            exit(1);
        }
}

void ft_argc_input(t_stack *stack, char **argv)
{
    int idx;
    int idx_sp;
    static char **split_argv;

    idx = 1;
    idx_sp = 0;
    while (argv[idx] != NULL)
    {
        split_argv = ft_split(argv[idx], ' ');
        idx_sp = 0;
        if (split_argv[idx][0] == '\0')
        {
            ft_free_stack(stack);
            ft_strfree(split_argv, idx_sp);
            ft_putendl_fd("Error", 2);
            exit(2);
        }
        while (split_argv[idx_sp])
        {
            ft_insert_node(stack, ft_new_node(ft_atoi_re(split_argv[idx_sp], stack, split_argv, idx_sp), stack));
            idx_sp++;
        }
        ft_strfree(split_argv, idx_sp);
        idx++;
    }
    ft_print_stack(stack);
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
// int ft_check_num(char c)
// {
//     if (c >= '0' && c <= '9')
//         return (1);
//     return (0);
// }

// int ft_check_argv(t_stack *stack, char **str_ori)
// {
//     int idx;
//     int idx_2;

//     idx = 0;
//     idx_2 = 0;
//     while (str_ori[idx])
//     {
//         idx_2 = 0;
//         if (str_ori[idx][idx_2] == '+' || str_ori[idx][idx_2] == '-')
//             idx_2++;
//         while (str_ori[idx][idx_2])
//         {
//             if (!ft_check_num(str_ori[idx][idx_2]))
//                 return (0);
//             idx_2++;
//         }
//         idx++;
//     }
//     return (1);
// }