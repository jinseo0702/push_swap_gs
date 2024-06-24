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

#include "../include/push_swap.h"

static void	less_size(t_stack *a, t_stack *b)
{
	b->size++;
	a->size--;
}

void	pb(t_stack *stack_a, t_stack *stack_b)
{
	t_node	*temp;

	if (!stack_a->top || !stack_a)
		return ;
	temp = stack_a->top;
	stack_a->top = stack_a->top->next;
	if (!stack_b->top)
	{
		stack_b->top = temp;
		stack_b->bottom = temp;
		temp->next = NULL;
		if (stack_a->top)
			stack_a->top->prev = NULL;
		less_size(stack_a, stack_b);
	}
	else
	{
		stack_b->top->prev = temp;
		temp->next = stack_b->top;
		stack_b->top = temp;
		if (stack_a->top)
			stack_a->top->prev = NULL;
		less_size(stack_a, stack_b);
	}
	ft_printf("pb\n");
}

void	pa(t_stack *stack_a, t_stack *stack_b)
{
	t_node	*temp;

	if (!stack_b->top || !stack_b)
		return ;
	temp = stack_b->top;
	stack_b->top = stack_b->top->next;
	if (!stack_a->top)
	{
		stack_a->top = temp;
		stack_a->bottom = temp;
		temp->next = NULL;
		if (stack_b->top)
			stack_b->top->prev = NULL;
		less_size(stack_b, stack_a);
	}
	else
	{
		stack_a->top->prev = temp;
		temp->next = stack_a->top;
		stack_a->top = temp;
		if (stack_b->top)
			stack_b->top->prev = NULL;
		less_size(stack_b, stack_a);
	}
	ft_printf("pa\n");
}
