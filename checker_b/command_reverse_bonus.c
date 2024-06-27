/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_reverse.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinseo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 11:24:16 by jinseo            #+#    #+#             */
/*   Updated: 2024/05/21 15:47:06 by jinseo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/checker_bonus.h"

int	ra_b(t_stack *a)
{
	t_node	*temp;

	if (a->size <= 1)
		return (-1);
	temp = a->top;
	a->top = a->top->next;
	a->top->prev = NULL;
	a->bottom->next = temp;
	temp->prev = a->bottom;
	a->bottom = temp;
	temp->next = NULL;
	return (1);
}

int	rb_b(t_stack *b)
{
	t_node	*temp;

	if (b->size <= 1)
		return (-1);
	temp = b->top;
	b->top = b->top->next;
	b->top->prev = NULL;
	b->bottom->next = temp;
	temp->prev = b->bottom;
	b->bottom = temp;
	temp->next = NULL;
	return (1);
}

int	rr_b(t_stack *a, t_stack *b)
{
	if (a->size > 1)
		ra_b(a);
	if (b->size > 1)
		rb_b(b);
	return (1);
}
