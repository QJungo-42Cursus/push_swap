#include "../libft/libft.h"
#include "../push_swap.h"

static int	find_unused(t_list **a)
{
	t_list	*ptr;
	int		res;

	res = INT_MIN;
	ptr = *a;
	while (ptr != NULL)
	{
		if (res == *(int *)ptr->content)
		{
			ptr = *a;
			res++;
			if (res == INT_MAX)
				return (0);
			continue ;
		}
		ptr = ptr->next;
	}
	return (res);
}

void	quicksort(t_list **a, t_list **b)
{
	t_partition		first_partition;

	first_partition = new_partition(A, find_unused(a));
	first_partition.top = *(int *)((*a)->content);
	first_partition.pivot = bottom_val(*a);
	first_partition.size = ft_lstsize(*a);
	first_partition.is_first = TRUE;

	partition(a, b, first_partition);

	greater_to_top(b, B);
	repeat_op(a, b, first_partition.size, PA);
}
