#include "../include/push_swap.h"

int	chunk_rotate(t_stack *stack, int chunk_value)
{
	t_node	*p;
	int		i;

	i = 0;
	p = stack->top;
	while (p->rnk > chunk_value)
	{
		p = p->next;
		i++;
	}
	if (i <= stack->size / 2)
		return (1);
	return (-1);
}


void ft_sand_onestep2(t_stack *a, t_stack *b)
{
	int	head;
    int i = 1;
    int chunk = ft_chunk(a->size);

	while (a->size != 0)
	{
		head = a->top->rnk;
		if (head <= i)
		{
			pb(a, b);
			i++;
		}
		else if ((head > i) && (head <= i + chunk))
		{
			pb(a, b);
			rb(b);
			i++;
		}
		else if (head > i + chunk)
		{
			if (chunk_rotate(a, i + chunk) > 0)
				ra(a);
			else
				rra(a);
		}
	}
}



void ft_sand_onestep(t_stack *a, t_stack *b)
{
    int cnt;
    int chunk;
    int num;

    cnt = 1;
    chunk = ft_chunk(a->size);
    while (a->top != NULL)
    {
        num = a->top->rnk;
        if (num <= cnt)
        {
            pb(a, b);
            cnt++;
        }
        else if ((num > cnt) && (num <= chunk + cnt))
        {
            pb(a, b);
            ra(a);
            cnt++;
        }
        else if(num > cnt + chunk)
        {
            if (a->size / 2 >= cnt)
                rra(a);
            else
                ra(a);
        }
    }
}


int ft_chunk(int size)
{
    return ((0.000000053 * (size * size)) + (0.03 * (size)) + 14.5);
}