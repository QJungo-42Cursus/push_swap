#include "push_swap.h"
#include "libft/libft.h"
#include "tests/tests.h"


#include <stdio.h>

static t_bool	is_sorted(t_list *a)
{
	int		i;

	i = get_littlest(a, 0);
	while (a != NULL)
	{
		if (i != *(int *)a->content)
			return (FALSE);
		a = a->next;
		i++;
	}
	return (TRUE);
}

static t_bool	is_sorted_order(t_list **a)
{
	int		i;
	int		value;
	t_list	*ptr;
	int		littlest;

	littlest = get_littlest(*a, 0);
	ptr = *a;
	while (*(int *)ptr->content != littlest)
		ptr = get_next_(ptr, a, NULL, A);
	i = littlest;
	while (1)
	{
		value = *(int *)ptr->content;
		if (i != littlest && value == littlest)
			break ; // on a fait le tour
		if (value != i)
			return (FALSE);
		i++;
		ptr = get_next_(ptr, a, NULL, A);
	}
	return (TRUE);
}

void	three_sort(t_list **a, t_list **b, int size)
{
	if (size == 2)
		operation_handler(a, b, SA);
	else if (is_sorted_order(a))
		while (!is_sorted(*a))
			operation_handler(a, b, RA);
	else
	{
		operation_handler(a, b, SA);
		while (!is_sorted(*a))
			operation_handler(a, b, RA);
	}
}

static void	send_lesser_greater(t_list **a, t_list **b, int pivot, t_stack current_stack, t_bool lesser)
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
}

void	less_than_six_sort(t_list **a, t_list **b, int size)
{
	int		pivot;

	send_lesser_greater(a, b, size - 2, A, TRUE);
	three_sort(a, b, ft_lstsize(*a));
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
	if (size <= 3)
		three_sort(a, b, size);
	else if (size <= 6)
		less_than_six_sort(a, b, size);
	else if (size <= 100)
		bubble_sort(a, b);
	else
		stupid_sort_in_my_opinion(a, b);
}
