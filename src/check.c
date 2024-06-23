#include "../include/push_swap.h"

int ft_is_sort(t_stack *a, t_stack *b)
{
    t_node *temp;
    t_node *next;

    temp = a->top;
    while (temp->next)
    {
        next = temp->next;
        if (temp->rnk > next->rnk)
            return (1);
        temp = next;
    }
    ft_free_stack(a);
    ft_free_stack(b);
    exit(1);
}

void	ft_basethree(t_stack *a)
{
	t_node	*cur;
    static char base[33];
	static int		num;
	static int		idx;


	cur = a->top;
	while (cur)
	{
		num = cur->rnk;
        idx = 0;
		while (num > 0)
		{
            base[idx] = (num % 2) + 48;
            num /= 2;
            idx++;
		}
        cur->base = (char *)ft_calloc(33, sizeof(char));
        ft_memcpy(cur->base, base, idx);
		cur = cur->next;
	}
    // ft_print_base(a);
}

void	ft_print_base(t_stack *stack)
{
	t_node	*temp;
	t_node	*next;

	temp = stack->top;
	while (temp)
	{
		next = temp->next;
		ft_printf("%s == len is : %d \n", temp->base, ft_strlen(temp->base));
		temp = next;
	}
}

void	ft_free_base(t_stack *stack)
{
	t_node	*temp;
	t_node	*next;

	temp = stack->top;
	while (temp)
	{
		next = temp->next;
		free(temp->base);
		temp->base = NULL;
		temp = next;
	}
}
