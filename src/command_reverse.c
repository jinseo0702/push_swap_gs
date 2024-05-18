/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_reverse.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinseo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 11:24:16 by jinseo            #+#    #+#             */
/*   Updated: 2024/05/16 19:05:53 by jinseo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ra(t_stack *a)
{
	t_node	*temp;
	t_node *last_temp;

	if (a->size <= 1)
		return ;
	temp = a->top;
	last_temp = a->bottom;
	a->top = a->top->next;
	a->top->prev = NULL;
	a->bottom->next = temp;
	a->bottom = temp;
	a->bottom->prev = last_temp->prev->prev;
	temp->next = NULL;
	ft_printf("ra\n");
}


void	rb(t_stack *b)
{
	t_node	*temp;
	t_node *last_temp;

	if (b->size <= 1)
		return ;
	temp = b->top;
	last_temp = b->bottom;
	b->top = b->top->next;
	b->top->prev = NULL;
	b->bottom->next = temp;
	b->bottom = temp;
	b->bottom->prev = last_temp->prev->prev;
	temp->next = NULL;
	ft_printf("rb\n");
}

void	rr(t_stack *a, t_stack *b)
{
	t_node	*temp_a;
	t_node	*temp_b;
	t_node *last_temp;

	if (a->size <= 1 || b->size <= 1)
		return ;
	temp_a = a->top;
	last_temp = a->bottom;
	a->top = a->top->next;
	a->top->prev = NULL;
	a->bottom->next = temp_a;
	a->bottom = temp_a;
	a->bottom->prev = last_temp->prev->prev;
	temp_a->next = NULL;
	temp_b = b->top;
	last_temp = b->bottom;
	b->top = b->top->next;
	b->top->prev = NULL;
	b->bottom->next = temp_b;
	b->bottom = temp_b;
	a->bottom->prev = last_temp->prev->prev;
	temp_b->next = NULL;
	ft_printf("rr\n");
}
