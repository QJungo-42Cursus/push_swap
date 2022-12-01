#include "push_swap.h"
#include "libft/libft.h"
#include "tests/tests.h"


#include <stdio.h>

t_bool	is_sorted(t_list *a)
{
	int		i;
	int		lstsize;


	lstsize = ft_lstsize(a);
	i = 0;
	while (i > lstsize)
	{
		if (i != *(int *)a->content)
			return (FALSE);
		a = a->next;
		i++;
	}
	return (TRUE);
}

void	send_lesser_greater(t_list **a, t_list **b, int pivot, t_stack current_stack, t_bool lesser)
{
	int		value;
	t_list	*stack;

	if (current_stack == A)
		stack = *a;
	else
		stack = *b;
	while (stack != NULL)
	{
		value = *(int *)stack->content;
		stack = stack->next;
		if (lesser && value < pivot)
			to_other_stack(a, b, value, current_stack);
		else if (!lesser && value > pivot)
			to_other_stack(a, b, value, current_stack);
	}
	(void)lesser;
}

void	stupid_sort_in_my_opinion(t_list **a, t_list **b)
{
	int		size;
	int		pivot;
	size = ft_lstsize(*a);
	/// va faire moit moit 
	pivot = size / 2;
	while (pivot != 0)
	{
		send_lesser_greater(a, b, pivot, A, FALSE);
		pivot = pivot / 2;
	}
	send_lesser_greater(a, b, 0, A, FALSE);

	
	pivot = 1;
	while (pivot < size / 2)
	{
		send_lesser_greater(a, b, pivot, B, TRUE);
		pivot = pivot * 2;
	}
	send_lesser_greater(a, b, pivot, B, TRUE);
	send_lesser_greater(a, b, size + 1, B, TRUE);


	int		divider = size / 11;
	pivot = size;
	while (pivot > 0)
	{
		send_lesser_greater(a, b, pivot, A, FALSE);
		pivot = pivot - divider;
	}
	send_lesser_greater(a, b, 0, A, FALSE);




	/// Met tout dans a en partant du plus grand
	pivot = size;
	while (pivot != 0)
	{
		send_lesser_greater(a, b, pivot, B, FALSE);
		pivot--;
	}
	send_lesser_greater(a, b, pivot, B, FALSE);
}

void	push_swap(t_list **a, t_list **b)
{
	int		size;

	size = ft_lstsize(*a);
	first_tri(*a);
	if (is_sorted(*a))
		return ;
	if (size > 300)
		stupid_sort_in_my_opinion(a, b);
	else
	{
		// trier avec les 3 fonctions
	}
}



//log_lists(*a, *b);
