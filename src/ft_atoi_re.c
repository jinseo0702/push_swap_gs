/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinseo <jinseo@student.42gyeongsan.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 14:55:42 by jinseo            #+#    #+#             */
/*   Updated: 2024/02/29 22:27:30 by jinseo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	ft_atoi_re(t_stack *b, t_stack *a, char **split_argv, int idx_sp)
{
	long  long nb;
	const char *nptr = split_argv[idx_sp];
	int nb2;
	int	mi;

	nb = 0;
	nb2 = 0;
	mi = 1;
	if ((*nptr == '+' || *nptr == '-') && *(nptr + 1) == '\0')
	{
		ft_free_stack(a);
		ft_free_stack(b);
		ft_strfree(split_argv, idx_sp);
		ft_putendl_fd("Error", 2);
		exit(2);
	}
	if (*nptr == '+' || *nptr == '-')
	{
		if (*nptr == '-')
			mi *= -1;
		nptr++;
	}
	while (*nptr != '\0')
	{
		if (*nptr >= '0' && *nptr <= '9')
			nb = (*nptr - 48) + (nb * 10);
		else
		{
			ft_free_stack(a);
			ft_free_stack(b);
			ft_strfree(split_argv, idx_sp);
			ft_putendl_fd("Error", 2);
			exit(2);
		}
		nptr++;
	}
	nb *= mi;
	if (nb < -2147483648 || nb > 2147483647)
	{
		ft_free_stack(a);
		ft_free_stack(b);
		ft_strfree(split_argv, idx_sp);
		ft_putendl_fd("Error", 2);
		exit(2);
	}
	nb2 = nb;
	return (nb2);
}
