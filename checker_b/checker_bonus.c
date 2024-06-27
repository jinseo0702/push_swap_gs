/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinseo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 02:53:26 by jinseo            #+#    #+#             */
/*   Updated: 2024/06/27 17:26:08 by jinseo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/checker_bonus.h"

void	is_error(t_stack *a, t_stack *b, char *cmd, char *str)
{
	ft_putendl_fd(str, 1);
	ft_free_stack(a);
	ft_free_stack(b);
	free(cmd);
	exit(1);
}

int	is_cmd(t_stack *a, t_stack *b, char *cmd)
{
	if (!ft_memcmp("sa\n", cmd, 3))
		return (sa_b(a));
	else if (!ft_memcmp("sb\n", cmd, 3))
		return (sb_b(b));
	else if (!ft_memcmp("ss\n", cmd, 3))
		return (ss_b(a, b));
	else if (!ft_memcmp("pa\n", cmd, 3))
		return (pa_b(a, b));
	else if (!ft_memcmp("pb\n", cmd, 3))
		return (pb_b(a, b));
	else if (!ft_memcmp("ra\n", cmd, 3))
		return (ra_b(a));
	else if (!ft_memcmp("rb\n", cmd, 3))
		return (rb_b(b));
	else if (!ft_memcmp("rr\n", cmd, 3))
		return (rr_b(a, b));
	else if (!ft_memcmp("rra\n", cmd, 4))
		return (rra_b(a));
	else if (!ft_memcmp("rrb\n", cmd, 4))
		return (rrb_b(b));
	else if (!ft_memcmp("rrr\n", cmd, 4))
		return (rrr_b(a, b));
	else
		is_error(a, b, cmd, "KO");
	return (1);
}

void	input_cmd(t_stack *a, t_stack *b)
{
	char	*cmd;

	cmd = get_next_line(0);
	while (cmd)
	{
		if (is_cmd(a, b, cmd) == -1)
			is_error(a, b, cmd, "KO");
		if (cmd)
			free(cmd);
		cmd = get_next_line(0);
	}
	free(cmd);
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	a = ft_creat_stack();
	b = ft_creat_stack();
	ft_judge(a, b, argv, argc);
	if (argc == 2)
	{
		ft_free_stack(a);
		ft_free_stack(b);
	}
	else
	{
		input_cmd(a, b);
		if (!ft_is_sort2(a) && b->top == NULL)
			is_error(a, b, NULL, "OK");
		else
		{
			is_error(a, b, NULL, "KO");
		}
	}
	return (0);
}
