/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinseo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 15:13:44 by jinseo            #+#    #+#             */
/*   Updated: 2024/05/16 15:14:47 by jinseo           ###   ########.fr       */
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
	// quick_swap_first(a, b, 1, a->size);
	ft_printf("\n-----first-----\n");
	for (int c = 1; c < a->size; c++){
		int d = c + 1;
		quick_swap_no(a, b, c, d);
	}
	// quick_swap_no(a, b, 1, 4);
	ft_print_stack_rnk(a);
	ft_printf("stack_a is\n");
	ft_print_stack(a);
	ft_printf("stack_b is\n");
	ft_print_stack(b);
	ft_printf("--stack_size == %d\n", a->size);
	ft_free_stack(a);
	ft_free_stack(b);
	return (0);
}