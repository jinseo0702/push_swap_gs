#include "../include/push_swap.h"

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
            rb(b);
            cnt++;
        }
        else if(num > cnt + chunk)
        {
            if (a->size / 2 >= cnt)
                ra(a);
            else
                rra(a);
        }
    }
	ft_sand_twostep(a, b);
}

void ft_sand_twostep(t_stack *a, t_stack *b)
{
	t_node *temp;
	t_node *next;

	while (b->top != NULL)
	{
		temp = b->top;
		while (b->top->rnk != b->size && temp)
		{
			next = temp->next;
			if(quick_cnt(b, b->size))
				rrb(b);
			else
				rb(b);
			temp = next;
		}
		pa(a, b);
	}
}


int ft_chunk(int size)
{
    return ((0.000000053 * (size * size)) + (0.03 * (size)) + 14.5);
}