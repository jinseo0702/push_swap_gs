#include "../include/push_swap.h"

// int main(int argc, char **argv)
// {
//     t_node *new1;
//     int num;

//     num = argc - 1;
//     if (argc > 2)
// 	{
//         ft_argc_over2(&new1, argv, num);
// 	}
//     else if (argc == 2)
//         ft_argc_like2(&new1, argv, num);
//     else if (argc == 1)
//     {
//         ft_putstr_fd("Error\n", 2);
//         exit (1);
//     }
//     return (0);
// }

int main(int argc, char **argv)
{
    t_stack *a;
    t_stack *b;
    int idx;
    (void)argc;

    idx = 1;
    a = ft_creat_stack();
    b = ft_creat_stack();
    while (argv[idx])
    {
        ft_insert_node(a, ft_new_node(ft_atoi(argv[idx]), a));
        idx++;
    }
    ft_print_stack(a);
}