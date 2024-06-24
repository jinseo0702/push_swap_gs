/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinseo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 20:59:26 by jinseo            #+#    #+#             */
/*   Updated: 2024/06/24 21:22:56 by jinseo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	lst_size(t_stack *stack)
{
	int		num;
	t_node	*temp;

	num = 0;
	temp = stack->top;
	while (temp)
	{
		num++;
		temp = temp->next;
	}
	return (num);
}

void	radix(t_stack *a, t_stack *b)
{
	int		len;
	int		size;
	char	*str;

	len = 0;
	while (ft_is_sort(a, b))
	{
		size = lst_size(a);
		while (size > 0)
		{
			str = a->top->base;
			if (str[len] == '0' || str[len] == 0)
				pb(a, b);
			else
				ra(a);
			size--;
		}
		while (b->top != NULL)
			pa(a, b);
		len++;
	}
}