#include "../libft/libft.h"
#include "../push_swap.h"

static void	print_op(t_operation op)
{
	if (op == SA)
		ft_putendl_fd("sa", 1);
	if (op == SB)
		ft_putendl_fd("sb", 1);
	if (op == SS)
		ft_putendl_fd("ss", 1);
	if (op == PA)
		ft_putendl_fd("pa", 1);
	if (op == PB)
		ft_putendl_fd("pb", 1);
	if (op == RA)
		ft_putendl_fd("ra", 1);
	if (op == RB)
		ft_putendl_fd("rb", 1);
	if (op == RR)
		ft_putendl_fd("rr", 1);
	if (op == RRA)
		ft_putendl_fd("rra", 1);
	if (op == RRB)
		ft_putendl_fd("rrb", 1);
	if (op == RRR)
		ft_putendl_fd("rrr", 1);
}

static void	rotate_handler(t_list **stack_a, t_list **stack_b, t_operation op)
{
	if (op == RA)
		rotate(stack_a);
	else if (op == RB)
		rotate(stack_b);
	else if (op == RR)
	{
		rotate(stack_a);
		rotate(stack_b);
	}
	else if (op == RRA)
		r_rotate(stack_a);
	else if (op == RRB)
		r_rotate(stack_b);
	else if (op == RRR)
	{
		r_rotate(stack_a);
		r_rotate(stack_b);
	}
}

void	operation_handler(t_list **stack_a, t_list **stack_b, t_operation op)
{
	//static int	calls = 0;
	//calls++;
	//ft_color(BLUE, 0);
	//ft_printf("\t%d-", calls);
	print_op(op);
	//ft_color(RESET, 0);

	if (op == SA)
		swap_top(*stack_a);
	else if (op == SB)
		swap_top(*stack_b);
	else if (op == SS)
	{
		swap_top(*stack_a);
		swap_top(*stack_b);
	}
	else if (op == PA)
		push(stack_b, stack_a);
	else if (op == PB)
		push(stack_a, stack_b);
	else
		rotate_handler(stack_a, stack_b, op);
}
