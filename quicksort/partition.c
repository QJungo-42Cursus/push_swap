#include "../libft/libft.h"
#include "../push_swap.h"
#include "quicksort.h"

void	partition(t_list **a, t_list **b, t_partition c_partition)
{
	t_partition		less;
	t_partition		great;
	t_list			*stack;

	if (c_partition.stack == A)
		stack = init_partitions(a, c_partition, &great, &less);
	else
		stack = init_partitions(b, c_partition, &great, &less);
	loop(a, b, stack, &c_partition, &great, &less);
	// si dans a, on met le current (le parent des suivants) dans b
	if (c_partition.stack == A)
	{
		//ft_printf("after a loop, node go to B (if A)\n");
		to_other_stack(a, b, c_partition.pivot, A);
		c_partition.stack = B;
	}
	

	//log_lists(*a, *b);
	//log_partition(a, b, c_partition, "current");
	//ft_printf("\n---- c_pivot ---- \n%d (dans stack %c)\n----\n", c_partition.pivot, c_partition.stack);
	//log_partition(a, b, less, "less", c_partition.pivot);
	//log_partition(a, b, great, "great", c_partition.pivot);

	// TODO si le truc est a deux, on peut le foutre ailleur...
	if (!c_partition.is_first && (great.size == 0 || less.size == 0 || c_partition.size == 0))
	{
		//log_lists(*a, *b);
		//ft_color(RED, BOLD);
		/*
		if (great.size == 0)
			ft_printf("great mort -> ");
		if (less.size == 0)
			ft_printf("less mort -> ");
			*/
		//ft_printf("on le fous derriere sont parrent : %d (->%d)\n", c_partition.pivot, c_partition.parent_pivot);
		//ft_color(RESET, 0);
		back_to_parent(a, b, c_partition);
		//log_lists(*a, *b);
	}

	if (great.size > 1)
		partition(a, b, great);
	else if (great.size == 1)
	{
		//log_lists(*a, *b);
		//ft_color(RED, BOLD);
		//ft_printf("great) on le fous derriere sont parrent : %d (->%d)\n", great.pivot, great.parent_pivot);
		//ft_color(RESET, 0);
		back_to_parent(a, b, great);
		//log_lists(*a, *b);
	}


	if (less.size > 1)
		partition(a, b, less);
	else if (less.size == 1)
	{
		//log_lists(*a, *b);
		//ft_color(RED, BOLD);
		//ft_printf("less) on le fous derriere sont parrent : %d (->%d)\n", less.pivot, less.parent_pivot);
		//ft_color(RESET, 0);
		back_to_parent(a, b, less);
		//log_lists(*a, *b);
	}
}
