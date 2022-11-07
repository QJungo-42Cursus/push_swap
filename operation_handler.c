#include"libft/libft.h"
#include"push_swap.h"

static void	op2(t_list **stack_a, t_list **stack_b, t_operation operation);
static void	print_operation(t_operation operation);

void	operation_handler(t_list **stack_a, t_list **stack_b, t_operation operation)
{
#ifdef LOG
	static int	calls = 0;

	calls++;
	ft_printf("%d\t", calls);
#endif
	print_operation(operation);
	if (operation == SA)
		swap_top(*stack_a);
	else if (operation == SB)
		swap_top(*stack_a);
	else if (operation == SS)
	{
		swap_top(*stack_a);
		swap_top(*stack_b);
	}
	else if (operation == PA)
		push(stack_b, stack_a);
	else if (operation == PB)
		push(stack_a, stack_b);
	else
		op2(stack_a, stack_b, operation);
}


static void	print_operation(t_operation operation)
{
	if (operation == SA)
		ft_putendl_fd("sa", 1);
	if (operation == SB)
		ft_putendl_fd("sb", 1);
	if (operation == SS)
		ft_putendl_fd("ss", 1);
	if (operation == PA)
		ft_putendl_fd("pa", 1);
	if (operation == PB)
		ft_putendl_fd("pb", 1);
	if (operation == RA)
		ft_putendl_fd("ra", 1);
	if (operation == RB)
		ft_putendl_fd("rb", 1);
	if (operation == RR)
		ft_putendl_fd("rr", 1);
	if (operation == RRA)
		ft_putendl_fd("rra", 1);
	if (operation == RRB)
		ft_putendl_fd("rrb", 1);
	if (operation == RRR)
		ft_putendl_fd("rrr", 1);
}

static void	op2(t_list **stack_a, t_list **stack_b, t_operation operation)
{
	if (operation == RA)
		rotate(stack_a);
	else if (operation == RB)
		rotate(stack_b);
	else if (operation == RR)
	{
		rotate(stack_a);
		rotate(stack_b);
	}
	else if (operation == RRA)
		r_rotate(stack_a);
	else if (operation == RRB)
		r_rotate(stack_b);
	else if (operation == RRR)
	{
		r_rotate(stack_a);
		r_rotate(stack_b);
	}
}
