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
}


int ft_chunk(int size)
{
    return ((0.000000053 * (size * size)) + (0.03 * (size)) + 14.5);
}