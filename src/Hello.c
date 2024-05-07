#include "../include/push_swap.h"
#include <stdio.h>

int main(int argc, char **argv)
{
    t_node *new1;
    t_node *cur = new1;
    int num = 2;
    
    new1 = ft_new_doubly(ft_atoi(argv[1]));
    while(num < argc)
    {
        insert_front_Node(new1, ft_atoi(argv[num]));
        new1 = new1->prev;
        cur = new1;
        num++;
    }
    while(cur->next != NULL)
    {
        printf("%d ", cur->num);
        cur = cur->next;
    }
    printf("\n");
    return (0);    
}