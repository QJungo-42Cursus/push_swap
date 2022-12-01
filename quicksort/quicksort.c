#include "../libft/libft.h"
#include "../push_swap.h"
#include "quicksort.h"

// Trouve un chiffre qui n'est pas dans la stack de depart pour l'utiliser
// comme premier parent (qui n'existe donc pas)
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

static void	first_pivot_to_bottom(t_list **a, int pivot)
{
	if (pivot == bottom_val(*a))
		return ;
	to_stack_top(a, pivot, A);
	operation_handler(a, NULL, RA);
}

#include <stdio.h>
void	quicksort(t_list **a, t_list **b)
{
	t_partition		first_partition;

	first_partition = new_partition(A, find_unused(a));
	first_partition.size = ft_lstsize(*a);
	first_partition.pivot = first_partition.size / 2;
	//first_partition.pivot = bottom_val(*a);
	first_partition.is_first = TRUE;
	first_pivot_to_bottom(a, first_partition.pivot);
	first_partition.top = *(int *)((*a)->content);
	//printf("first_partition.pivot = %d, first_partition.top = %d, first_partition.size = %d\n", first_partition.pivot, first_partition.top, first_partition.size);

	partition(a, b, first_partition);

	greater_to_top(b, B);
	repeat_op(a, b, first_partition.size, PA);
}
