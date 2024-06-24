#include "../include/push_swap.h"

int is_max(t_stack *a)
{
    t_node *temp;
    int max;
    int cnt;
    int cnt2;

    temp = a->top;
    max = temp->rnk;
    cnt = 1;
    cnt2 = 1;
    while(temp)
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

int ft_is_sort2(t_stack *a)
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
    return (0);
}

void three_hard_coding(t_stack *a, t_stack *b)
{
    int cnt;
    // int num = 1;

    pb(a, b);
    pb(a, b);
    cnt = is_max(a);
    if (cnt == 1)
        rra(a);
    if (cnt == 2)
        ra(a);
    if (ft_is_sort2(a))
        sa(a);
    if (!ft_is_sort2(b))
        sb(b);
    ft_print_stack_rnk(b);
    // while(b->top != NULL)
    // {
    //     if(b->top->rnk == num)
    //         pa(a, b);
    //     ra(a);
    //     num++;
    // }
    ft_print_stack_rnk(a);
}