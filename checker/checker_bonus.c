#include "../include/checker_bonus.h"

void is_error(t_stack *a, t_stack *b, char *cmd, char *str)
{
    ft_putendl_fd(str, 1);
	ft_free_stack(a);
	ft_free_stack(b);
    free(cmd);
	exit(1);
}

void is_cmd(t_stack *a, t_stack *b, char *cmd)
{
    int f = 0;
    if (!ft_memcmp("sa\n", cmd, 3))
        f = sa_b(a);
    else if (!ft_memcmp("sb\n", cmd, 3))
        f = sb_b(b);
    else if (!ft_memcmp("ss\n", cmd, 3))
        f = ss_b(a, b);
    else if (!ft_memcmp("pa\n", cmd, 3))
        f = pa_b(a, b);
    else if (!ft_memcmp("pb\n", cmd, 3))
        f = pb_b(a, b);
    else if (!ft_memcmp("ra\n", cmd, 3))
        f = ra_b(a);
    else if (!ft_memcmp("rb\n", cmd, 3))
        f = rb_b(b);
    else if (!ft_memcmp("rr\n", cmd, 3))
        f = rr_b(a, b);
    else if (!ft_memcmp("rra\n", cmd, 4))
        f = rra_b(a);
    else if (!ft_memcmp("rrb\n", cmd, 4))
        f = rrb_b(b);
    else if (!ft_memcmp("rrr\n", cmd, 4))
        f = rrr_b(a, b);
    else
        is_error(a, b, cmd, "KO");
    if (f == -1)
        is_error(a, b, cmd, "KO");
}

void input_cmd(t_stack *a, t_stack *b)
{
    char *cmd;

    cmd = get_next_line(0);
    while (cmd)
    {
        is_cmd(a, b, cmd);
        if (cmd)
            free(cmd);
        cmd = get_next_line(0);
    }
    free(cmd);
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	a = ft_creat_stack();
	b = ft_creat_stack();
	ft_judge(a, b, argv, argc);
    input_cmd(a, b);
    if(!ft_is_sort2(a) && b->top == NULL)
        is_error(a, b, NULL, "OK");
    else
    {
        is_error(a, b, NULL, "KO");
    }
	return (0);
}