CC = cc
CFLAG = -Wall -Wextra -Werror -g
AR = ar -rcs
RM = rm -rf

SRCS = src/input_argv.c \
src/judgment.c \
src/push_swap.c \
src/doubly_linked_list.c \
src/command_push.c \
src/command_swap.c \
src/command_reverse.c \
src/command_double_reverse.c \
src/ft_atoi_re.c \
src/check.c \
src/radix.c \
src/five_or_less.c

SRCSBONUS = checker_b/checker_bonus.c \
checker_b/command_double_reverse_bonus.c \
checker_b/command_push_bonus.c \
checker_b/command_reverse_bonus.c \
checker_b/command_swap_bonus.c \

OBJS = $(SRCS:.c=.o)
OBJSBONUS = $(SRCSBONUS:_bonus.c=_bonus.o)
NAME = push_swap
BONUS = checker
LIB = libpush_swap.a
LIBBONUS = checker.a

all : $(NAME)
bonus : $(BONUS)

$(NAME) : $(LIB)
	@make -C libft/
	@make -C ft_printf/
	@$(CC) $(CFLAG) -o $@ $^ -L libft/ -lft -L ft_printf/ -lftprintf
	@touch $@

$(BONUS) : $(LIBBONUS)
	@make all
	@$(CC) $(CFLAG) -o $@ $^ libpush_swap.a -L libft/ -lft -L ft_printf/ -lftprintf
	@touch $@

$(LIB) : $(OBJS)
	@$(AR) $@ $^

$(LIBBONUS) : $(OBJSBONUS)
	@$(AR) $@ $^

%.o : %.c
	@$(CC) $(CFLAG) -c $< -o $@

%_bonus.o : _bonus.c
	@$(CC) $(CFLAG) -c $< -o $@

clean :
	@make clean -C libft/
	@make clean -C ft_printf/
	@$(RM) $(OBJS)
	@$(RM) $(OBJSBONUS)

fclean : 
	@make fclean -C libft/
	@make fclean -C ft_printf/
	@$(RM) $(OBJS) $(NAME) $(LIB)
	@$(RM) $(OBJSBONUS) $(BONUS) $(LIBBONUS)

re : 
	@make fclean
	@make all

.PHONY: all clean fclean re bonus
