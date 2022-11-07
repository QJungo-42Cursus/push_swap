#include "libft/libft.h"
#include "push_swap.h"

static void	print_stack_el(void *val)
{
	if (val == NULL)
		return ;
	int	*v;

	v = (int *)val;
	ft_printf("%d\n", *v);
}

void	log_lists(t_list *a, t_list *b)
{
	(void)a;
	(void)b;
	print_stack_el(NULL);
	if (ft_lstsize(a) > 0)
	{
		ft_printf("\n----- A -----\n");
		ft_lstiter(a, print_stack_el);
		ft_printf("-----");
	}
	if (ft_lstsize(b) > 0)
	{
		ft_printf("\n----- B -----\n");
		ft_lstiter(b, print_stack_el);
		ft_printf("-----");
	}
	ft_printf("\n");
}

void	log_partition(t_list **a, t_list **b, t_partition c_partition, char *msg, int from_pivot)
{
	t_list			*stack;

	ft_printf("---- %s (%d) -----\n", msg, from_pivot);
	//ft_printf("(top, %d pivot %d)\n", c_partition.top, c_partition.pivot);

	if (c_partition.size == 0)
	{
		ft_printf("size: %d\n", c_partition.size);
		ft_printf("stack: %c\n", c_partition.stack);
		ft_printf("----\n\n");
		return ;
	}

	stack = *b;
	if (c_partition.stack == A)
		stack = *a;
	while (*(int *)stack->content != c_partition.top)
		stack = get_next_(stack, a, b, c_partition.stack);

	ft_printf("top \t%d\n", *(int *)stack->content);
	stack = get_next_(stack, a, b, c_partition.stack);
	while (1)
	{
		if (*(int *)stack->content == c_partition.pivot)
		{
			ft_printf("pivot \t%d\n", *(int *)stack->content);
			break;
		}
		ft_printf("\t%d\n", *(int *)stack->content);
		stack = get_next_(stack, a, b, c_partition.stack);
	}
	ft_printf("size: %d\n", c_partition.size);
	ft_printf("stack: %c\n", c_partition.stack);
	//ft_printf("size: %d\n", c_partition.size);
	//ft_printf("size: %d\n", c_partition.size);
	ft_printf("----\n\n");
}
