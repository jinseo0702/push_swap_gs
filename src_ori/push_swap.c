#include "../include/push_swap.h"

int main(int argc, char **argv)
{
    t_stack *a;
    t_stack *b;

    a = ft_creat_stack();
    b = ft_creat_stack();
    ft_judge(a, b, argv, argc);
    ft_free_stack(a);
    ft_free_stack(b);
    return (0);
}