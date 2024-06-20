#include "../include/push_swap.h"
#include <stdio.h>

void ft_is_base(int num)
{
    int num2;

    num2 = num;
    while (num2 > 0)
    {
        printf("%d ", num2 % 2);
        num2 /= 2;
    }

}

void ft_is_re(int num)
{
    if (num < 2)
    {
        printf("%d ", num);
        return ;
    }
    ft_is_re(num / 2);
    printf("%d ", num % 2);
}

void ft_is_re2(int num, char **str)
{
    if (num < 2)
    {
        (*str) = num;
        (str++);
        // (*cnt)++;
        return ;
    }
    ft_is_re2(num / 2, str);
    (*str) = num % 2;
    (str++);
    // (*cnt)++;
}

int main(int argc, char **argv)
{
    if(argc == 2)
    {
        int num = ft_atoi(argv[1]);
        ft_is_base(num);
        printf("\n------------------------------\n");
        static char arr[40];
        int cnt = 0;
        ft_is_re(num);
        printf("\n------------------------------\n");
        ft_is_re2(num, &arr);
        for (int a = 0; a < 40; a++)
            printf("%d ", arr[a]); 
        printf("\n%d\n", cnt);
    }
    else
        printf("failed !!\n");
    /*static char arr[40];
    for(int a = 0; a < 30; a++)
    {
        printf ("%d, cnt : %d\n", arr[a], a + 1);
    }*/
    printf("\n printf all!!!\n");
    return (0);
}