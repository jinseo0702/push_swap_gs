#include "../include/push_swap.h"

int quick_cnt(t_stack *a, int num)
{
    t_node *temp;
    t_node *next;
    int num2;

    if (!a->top)
        return (-2);
    temp = a->top;
    num2 = -1;
    while (temp->rnk != num && temp)
    {
        next = temp->next;
        temp = next;
        ++num2;
    }
    return (num2);
}

void quick_swap_first(t_stack *a, t_stack *b, int min, int max)
{
    t_node *temp;
    t_node *next;
    int cnt_min;
    int cnt_max;

    temp = a->top;
    cnt_min = quick_cnt(a, min);
    if (cnt_min == -2)
        return ;
    if (((cnt_min + a->size) % a->size) > ((a->size - cnt_min) % a->size))
    {
        while (a->top->rnk != min && temp)
        {
            next = temp->next;
            rra(a);
            temp = next;
        }
    }
    else
    {
        while (a->top->rnk != min && temp)
        {
            next = temp->next;
            ra(a);
            temp = next;
        }
    }
    pb(a, b);
    temp = a->top;
    cnt_max = quick_cnt(a, max);
    if (cnt_max == -2)
        return ;
    if (((cnt_max + a->size) % a->size) > ((a->size - cnt_max) % a->size))
    {
        while (a->top->rnk != max && temp)
        {
            next = temp->next;
            rra(a);
            temp = next;
        }
    }
    else
    {
        while (a->top->rnk != max && temp)
        {
            next = temp->next;
            ra(a);
            temp = next;
        }
    }
    pa(a, b);
    sa(a);
}

void quick_swap_no(t_stack *a, t_stack *b, int min, int max)
{
    t_node *temp;
    t_node *next;
    int cnt_min;
    int cnt_max;

    temp = a->top;
    cnt_min = quick_cnt(a, min);
    if (((cnt_min + a->size) % a->size) > ((a->size - cnt_min) % a->size))
    {
        while (a->top->rnk != min && temp)
        {
            next = temp->next;
            rra(a);
            temp = next;
        }
    }
    else
    {
        while (a->top->rnk != min && temp)
        {
            next = temp->next;
            ra(a);
            temp = next;
        }
    }
    pb(a, b);
    temp = a->top;
    cnt_max = quick_cnt(a, max);
    if (((cnt_max + a->size) % a->size) > ((a->size - cnt_max) % a->size))
    {
        while (a->top->rnk != max && temp)
        {
            next = temp->next;
            rra(a);
            temp = next;
        }
    }
    else
    {
        while (a->top->rnk != max && temp)
        {
            next = temp->next;
            ra(a);
            temp = next;
        }
    }
    pa(a, b);
}