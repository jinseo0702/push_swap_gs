#include "../include/push_swap.h"

int main(int argc, char **argv)
{
    t_node *new1;
    int num;

    num = argc - 1;
    if (argc > 2)
        ft_argc_over2(&new1, argv, num);
    else if (argc == 2)
        ft_argc_like2(&new1, argv, num);
    else if (argc == 1)
    {
        ft_putstr_fd("Error\n", 2);
        exit (1);
    }
    return (0);
}