/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinseo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 15:13:44 by jinseo            #+#    #+#             */
/*   Updated: 2024/05/21 15:41:59 by jinseo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	a = ft_creat_stack();
	b = ft_creat_stack();
	ft_judge(a, b, argv, argc);
	ft_is_sort(a, b);
	if (a->size < 6)
		ft_less_five(a, b);
	else
		radix(a, b);
	ft_free_stack(a);
	ft_free_stack(b);
	return (0);
}
