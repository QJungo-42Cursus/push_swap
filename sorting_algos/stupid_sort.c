/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stupid_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qjungo <qjungo@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 15:51:19 by qjungo            #+#    #+#             */
/*   Updated: 2022/12/01 15:51:20 by qjungo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include "../libft/libft.h"

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

static void	pass1(t_list **a, t_list **b, int size)
{
	int		pivot;

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
}

void	stupid_sort_in_my_opinion(t_list **a, t_list **b)
{
	int		size;
	int		pivot;
	int		divider;

	size = ft_lstsize(*a);
	pass1(a, b, size);

	divider = size / 11;
	pivot = size;
	while (pivot > 0)
	{
		send_lesser_greater(a, b, pivot, A, FALSE);
		pivot = pivot - divider;
	}
	send_lesser_greater(a, b, 0, A, FALSE);
	pivot = size;
	while (pivot != 0)
	{
		send_lesser_greater(a, b, pivot, B, FALSE);
		pivot--;
	}
	send_lesser_greater(a, b, pivot, B, FALSE);
}
