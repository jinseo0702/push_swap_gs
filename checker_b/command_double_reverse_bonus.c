/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_double_reverse.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinseo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 11:24:27 by jinseo            #+#    #+#             */
/*   Updated: 2024/05/21 15:32:29 by jinseo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/checker_bonus.h"

int	rra_b(t_stack *a)
{
	t_node	*temp;

	if (a->size <= 1)
		return (-1);
	temp = a->bottom;
	a->bottom = a->bottom->prev;
	a->bottom->next = NULL;
	a->top->prev = temp;
	temp->next = a->top;
	a->top = temp;
	a->top->prev = NULL;
	return (1);
}

int	rrb_b(t_stack *b)
{
	t_node	*temp;

	if (b->size <= 1)
		return (-1);
	temp = b->bottom;
	b->bottom = b->bottom->prev;
	b->bottom->next = NULL;
	b->top->prev = temp;
	temp->next = b->top;
	b->top = temp;
	b->top->prev = NULL;
	return (1);
}

int	rrr_b(t_stack *a, t_stack *b)
{
	if (a->size > 1)
		rra_b(a);
	if (b->size > 1)
		rrb_b(b);
	return (1);
}
