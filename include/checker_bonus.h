#ifndef CHECKER_BONUS_H
# define CHECKER_BONUS_H
# include "../libft/libft.h"
# include "../libft/gnl_check_bonus/get_next_line.h"
# include "../libft/gnl_check_bonus/get_next_line_bonus.h"
# include "../ft_printf/libftprintf.h"
# include "../include/push_swap.h"
# include <stdlib.h>
# include <unistd.h>

void is_error(t_stack *a, t_stack *b, char *cmd, char *str);
int is_cmd(t_stack *a, t_stack *b, char *cmd);
void input_cmd(t_stack *a, t_stack *b);
int	rra_b(t_stack *a);
int	rrb_b(t_stack *b);
int	rrr_b(t_stack *a, t_stack *b);
void	less_size_b(t_stack *a, t_stack *b);
int	pb_b(t_stack *stack_a, t_stack *stack_b);
int	pa_b(t_stack *stack_a, t_stack *stack_b);
int	ra_b(t_stack *a);
int	rb_b(t_stack *b);
int	rr_b(t_stack *a, t_stack *b);
int	sa_b(t_stack *a);
int	sb_b(t_stack *b);
int	ss_b(t_stack *a, t_stack *b);

#endif