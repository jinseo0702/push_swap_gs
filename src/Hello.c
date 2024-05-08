#include "../include/push_swap.h"

int main(int argc, char **argv)
{
    t_node *new1;
    int num;

    num = argc - 1;
    if (argc > 2)
    {
        // new1 = ft_new_doubly(ft_atoi(argv[num]));
        // new1 = ft_inputargv(num, &argv, new1);
        // ft_print_list(new1);
        ft_argc_over2(&new1, argv, num);
    }
    else if (argc == 2)
    return (0);    
}
