#include "../include/push_swap.h"
#include <stdio.h>

int main(int argc, char **argv)
{
    t_node *new1;
    t_node *cur = new1;
    int num;
    num = argc - 1;
 
    new1 = ft_new_doubly(ft_atoi(argv[num]));
    new1 = ft_inputargv(num, &argv, new1);
    // while(--num > 0)
    // {
    //     insert_front_Node(new1, ft_atoi(argv[num]));
    //     new1 = new1->prev;
    //     cur = new1;
    // }
    while(new1->next != NULL)
    {
        printf("%d ", new1->num);
        new1 = new1->next;
    }
    printf("\n");
    return (0);    
}
