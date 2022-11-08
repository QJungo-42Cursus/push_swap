#include "../libft/libft.h"
#include "../push_swap.h"

void	quicksort(t_list **a, t_list **b)
{
	t_partition		first_partition;
	t_list			*last;

	first_partition = new_partition(A, 0);
	first_partition.top = *(int *)((*a)->content);
	last = ft_lstlast(*a);
	first_partition.pivot = *(int *)((last)->content);
	first_partition.size = ft_lstsize(*a);
	first_partition.is_first = TRUE;
	partition(a, b, first_partition);
	log_lists(*a, *b);


	// TODO mettre le + grand en haut !!!

	greater_to_top(b, B);
	repeat_op(a, b, first_partition.size, PA);
}
