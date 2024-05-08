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

void ft_argc_over2(t_node **new1, char **argv, int num)
{
        *new1 = ft_new_doubly(ft_atoi(argv[num]));
        *new1 = ft_inputargv(num, &argv, *new1);
        ft_print_list(*new1);
}
