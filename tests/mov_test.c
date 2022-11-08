# include "../libft/libft.h"
# include "../push_swap.h"
# include "../quicksort/quicksort.h"
# include "tests.h"

///		repeat_op(t_list **a, t_list **b, int n, t_operation op) -> pas besoin de tester (les autres le font pour elle)

///		greater_to_top(t_list **list, t_stack stack)
///		-> la plus haute valeur en haut
static void	greater_to_top_test(int as, int *av, t_stack stack)
{
	t_list	*a;
	
	a = NULL;
	init_stack(as, av, &a);
	log_lists(a, NULL);
	greater_to_top(&a, A);
	log_lists(a, NULL);

	ft_lstclear(&a, free);
}

///		to_stack_top(t_list **stack, int val, t_stack s_from)
///		-> met val en haut de sa stack respective
static void	to_stack_top_test(int as, int *av, int bs, int *bv, int val, t_stack stack)
{
	t_list	*a;
	t_list	*b;
	
	a = NULL;
	b = NULL;
	init_stack(as, av, &a);
	init_stack(bs, bv, &b);
	if (stack == A)
	{
		to_stack_top(&a, val, stack);
		if (val == top_val(a, b, A))
			ok();
		else
			ft_printf("KO. After to stack top (val: %d), top is : %d\n", val, top_val(a, b, A));
	}
	else
	{
		to_stack_top(&b, val, stack);
		if (val == top_val(a, b, B))
			ok();
		else
			ft_printf("KO. After to stack top (val: %d), top is : %d\n", val, top_val(a, b, B));
	}
	ft_lstclear(&a, free);
	ft_lstclear(&b, free);
}

///		to_other_stack(t_list **a, t_list **b, int val, t_stack s_from)
static void	to_other_stack_test(int as, int *av, int bs, int *bv, int val, t_stack stack)
{
	t_list	*a;
	t_list	*b;
	
	a = NULL;
	b = NULL;
	init_stack(as, av, &a);
	init_stack(bs, bv, &b);
	if (stack == A)
	{
		to_other_stack(&a, &b, val, stack);
		if (val == top_val(a, b, B))
			ok();
		else
			ft_printf("KO. After to stack top (val: %d), top is : %d\n", val, top_val(a, b, B));
	}
	else
	{
		to_other_stack(&a, &b, val, stack);
		if (val == top_val(a, b, A))
			ok();
		else
			ft_printf("KO. After to stack top (val: %d), top is : %d\n", val, top_val(a, b, B));
	}
	ft_lstclear(&a, free);
	ft_lstclear(&b, free);
}

int main()
{
	//t_partition	p;

	int			a[5] = {1, 3, 4, 200, 500};
	int			b[4] = {98, 100, 85, -5};

	title(BLUE, "TO STACK TOP");
	to_stack_top_test(5, a, 4, b, 1, A);
	to_stack_top_test(5, a, 4, b, 3, A);
	to_stack_top_test(5, a, 4, b, 4, A);
	to_stack_top_test(5, a, 4, b, 200, A);
	to_stack_top_test(5, a, 4, b, 500, A);
	to_stack_top_test(5, a, 4, b, 100, B);
	to_stack_top_test(5, a, 4, b, 98, B);
	to_stack_top_test(5, a, 4, b, 85, B);
	to_stack_top_test(5, a, 4, b, -5, B);

	title(BLUE, "TO OTHER STACK (TOP)");
	to_stack_top_test(5, a, 4, b, 1, A);
	to_stack_top_test(5, a, 4, b, 3, A);
	to_stack_top_test(5, a, 4, b, 4, A);
	to_stack_top_test(5, a, 4, b, 200, A);
	to_stack_top_test(5, a, 4, b, 500, A);
	to_stack_top_test(5, a, 4, b, 100, B);
	to_stack_top_test(5, a, 4, b, 98, B);
	to_stack_top_test(5, a, 4, b, 85, B);
	to_stack_top_test(5, a, 4, b, -5, B);

	title(BLUE, "GREATER TO TOP 1");
	greater_to_top_test(5, a, A);
	title(BLUE, "GREATER TO TOP 2");
	greater_to_top_test(4, b, A);
	int	c[15] = {1, 3, 4, 200, 500, 10000, -500, 9, 8, 555, 7, 50, 89, 999, 5};
	int	d[20] = {98, 100, 85, -5, 500, 501, 502, -55, -555, -5555, 666, 667, 48546, 741, 9879, 5556, -1, -2, -3, -7};
	title(BLUE, "GREATER TO TOP 3");
	greater_to_top_test(15, c, A);
	title(BLUE, "GREATER TO TOP 4");
	greater_to_top_test(20, d, A);
}
