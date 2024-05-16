/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinseo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 11:22:53 by jinseo            #+#    #+#             */
/*   Updated: 2024/05/16 19:04:36 by jinseo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	sa(t_stack *a)
{
	t_node	*temp;

	if (a->size == 0 || a->size == 1)
		return ;
	temp = a->top;
	a->top = a->top->next;
	temp->prev = a->top;
	temp->next = a->top->next;
	a->top->next = temp;
	a->top->prev = NULL;
	ft_printf("sa\n");
}

void	sb(t_stack *b)
{
	t_node	*temp;

	if (b->size == 0 || b->size == 1)
		return ;
	temp = b->top;
	b->top = b->top->next;
	temp->prev = b->top;
	temp->next = b->top->next;
	b->top->next = temp;
	b->top->prev = NULL;
	ft_printf("sb\n");
}

void	ss(t_stack *a, t_stack *b)
{
	t_node	*temp_a;
	t_node	*temp_b;

	if (a->size <= 1 || b->size <= 1)
		return ;
	temp_a = a->top;
	a->top = a->top->next;
	temp_a->prev = a->top;
	temp_a->next = a->top->next;
	a->top->next = temp_a;
	a->top->prev = NULL;
	temp_b = b->top;
	b->top = b->top->next;
	temp_b->prev = b->top;
	temp_b->next = b->top->next;
	b->top->next = temp_b;
	b->top->prev = NULL;
	ft_printf("ss\n");
}
