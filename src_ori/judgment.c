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

int ft_is_mix(char **split_argv)
{
    int idx;

    idx = 0;
    while (split_argv[idx])
        idx++;
    return (idx);
}

void ft_argc_over2(t_node **new1, char **argv, int num)
{
    static char **split_argv;
    int idx;
    int cnt;

    idx = 1;
    cnt = 0;
    while (idx < num + 1)
    {
        cnt = 0;
        split_argv = ft_split(argv[idx], ' ');
        cnt = ft_is_mix(split_argv);
        ft_printf("cnt: %d\n", idx);
        free(split_argv);
        if (cnt > 1)
            {
                ft_putstr_fd("Error\n", 2);
                exit (1);
            }
        idx++;
    }
    *new1 = ft_new_doubly(ft_atoi(argv[num]));
    *new1 = ft_inputargv(num, &argv, *new1, 0);
    ft_print_list(*new1);
}

void ft_argc_like2(t_node **new1, char **argv, int num)
{
    char **split_argv;
    int idx;
    
    idx = 0;
    split_argv = ft_split(argv[num], ' ');
    idx = ft_is_mix(split_argv);
    ft_printf("idx: %d\n", idx);
    idx--;
    *new1 = ft_new_doubly(ft_atoi(split_argv[idx]));
    *new1 = ft_inputargv(idx, &split_argv, *new1, 1);
    ft_print_list(*new1);
}