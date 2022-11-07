#include"libft/libft.h"
#include"push_swap.h"

void	push_swap(t_list **a, t_list **b)
{
	/*
	t_list	*stack_b;
	t_list	*stack_a;	

	stack_a = *a;
	stack_b = *b;
	*/

	t_partition		first_partition; (void)first_partition;
	t_list			*last;


	log_lists(*a, *b);
	//median_of_three(a, ft_lstsize(*a), *(int *)((*a)->content));

	first_partition = new_partition(A, 0);
	first_partition.top = *(int *)((*a)->content);
	last = ft_lstlast(*a);
	first_partition.pivot = *(int *)((last)->content);
	first_partition.size = ft_lstsize(*a);
	partition(a, b, first_partition);
	

#ifdef LOG
#endif
	ft_printf("\nFINAL: \n");
	log_lists(*a, *b);
}

///		va mettre le "median of three" a la fin de la list...
void	median_of_three(t_list **a, int lst_len, int fi)
{
	int		mid;
	int		la;
	t_list	*mid_ptr;
	t_list	*la_ptr;

	la_ptr = ft_lstlast(*a);
	la = *(int *)(la_ptr->content);
	mid_ptr = *a;
	mid = 0;
	while (mid++ != lst_len / 2 - 2) // juste avant le milieu (pour le mid_ptr)
		mid_ptr = mid_ptr->next;
	mid = *(int *)(mid_ptr->next->content);
	if ((la < fi && fi < mid) || (mid < fi && fi < la)) // first
		operation_handler(a, NULL, RA);
	if ((fi < mid && mid < la) || (la < mid && mid < fi)) // middle
	{
		// en vrai ca vaut ptet pas le coup de tout decaler...

	}
}
