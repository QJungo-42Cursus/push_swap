#include"libft/libft.h"
#include"push_swap.h"

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
	return (n);
}
