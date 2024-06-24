/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_push.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinseo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 11:23:08 by jinseo            #+#    #+#             */
/*   Updated: 2024/06/24 21:14:02 by jinseo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/checker_bonus.h"

void	less_size_b(t_stack *a, t_stack *b)
{
	b->size++;
	a->size--;
}

int	pb_b(t_stack *stack_a, t_stack *stack_b)
{
	t_node	*temp;

	if (!stack_a->top || !stack_a)
		return (-1);
	temp = stack_a->top;
	stack_a->top = stack_a->top->next;
	if (!stack_b->top)
	{
		stack_b->top = temp;
		stack_b->bottom = temp;
		temp->next = NULL;
		if (stack_a->top)
			stack_a->top->prev = NULL;
		less_size_b(stack_a, stack_b);
	}
	else
	{
		stack_b->top->prev = temp;
		temp->next = stack_b->top;
		stack_b->top = temp;
		if (stack_a->top)
			stack_a->top->prev = NULL;
		less_size_b(stack_a, stack_b);
	}
	return (1);
}

int	pa_b(t_stack *stack_a, t_stack *stack_b)
{
	t_node	*temp;

	if (!stack_b->top || !stack_b)
		return (-1);
	temp = stack_b->top;
	stack_b->top = stack_b->top->next;
	if (!stack_a->top)
	{
		stack_a->top = temp;
		stack_a->bottom = temp;
		temp->next = NULL;
		if (stack_b->top)
			stack_b->top->prev = NULL;
		less_size_b(stack_b, stack_a);
	}
	else
	{
		stack_a->top->prev = temp;
		temp->next = stack_a->top;
		stack_a->top = temp;
		if (stack_b->top)
			stack_b->top->prev = NULL;
		less_size_b(stack_b, stack_a);
	}
	return (1);
}
