/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   five_or_less.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinseo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 21:17:45 by jinseo            #+#    #+#             */
/*   Updated: 2024/06/24 21:22:38 by jinseo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	is_max(t_stack *a)
{
	t_node	*temp;
	int		max;
	int		cnt;
	int		cnt2;

	temp = a->top;
	max = temp->rnk;
	cnt = 1;
	cnt2 = 1;
	while (temp)
	{
		if (max < temp->rnk)
		{
			max = temp->rnk;
			cnt2 = cnt;
		}
		cnt++;
		temp = temp->next;
	}
	return (cnt2);
}

int	ft_is_sort2(t_stack *a)
{
	t_node	*temp;
	t_node	*next;

	temp = a->top;
	while (temp->next)
	{
		next = temp->next;
		if (temp->rnk > next->rnk)
			return (1);
		temp = next;
	}
	return (0);
}

void	ft_middle(t_stack *a, t_stack *b)
{
	t_node	*temp;
	int		num;

	num = 0;
	temp = a->top;
	while (num != 2)
	{
		if (temp->rnk < 3)
		{
			pb(a, b);
			num++;
		}
		rra(a);
		temp = a->top;
	}
}

void	three_hard_coding(t_stack *a, t_stack *b)
{
	int	cnt;

	ft_middle(a, b);
	cnt = is_max(a);
	if (cnt == 1)
		ra(a);
	if (cnt == 2)
		rra(a);
	if (ft_is_sort2(a))
		sa(a);
	if (!ft_is_sort2(b))
		sb(b);
	while (b->top != NULL)
		pa(a, b);
}

void	ft_less_five(t_stack *a, t_stack *b)
{
	static int	cnt;

	if (a->size == 2)
		sa(a);
	else if (a->size == 3)
	{
		cnt = is_max(a);
		if (cnt == 1)
			ra(a);
		if (cnt == 2)
			rra(a);
		if (ft_is_sort2(a))
			sa(a);
	}
	else
		three_hard_coding(a, b);
}
