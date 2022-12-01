#include "../libft/libft.h"
#include "../push_swap.h"

t_partition	new_partition(t_stack stack, int parent_pivot)
{
	t_partition	n;

	n.stack = stack;
	n.size = 0;
	n.top = 0;
	n.pivot = 0;
	n.parent_pivot = parent_pivot;
	n.is_pivot_set = FALSE;
	n.is_top_set = FALSE;
	n.is_first = FALSE;
	return (n);
}

/// choose partition
/// and go to top of the partition
t_list *init_partitions(t_list **list, t_partition c_partition, t_partition *great, t_partition *less)
{
	t_list	*stack;

	stack = *list;
	*great = new_partition(A, c_partition.pivot);
	if (c_partition.stack == A)
		great->stack = B;
	*less = new_partition(c_partition.stack, c_partition.pivot);
	while (*(int *)stack->content != c_partition.top)
		stack = get_next_(stack, list, list, c_partition.stack);
	return (stack);
}
