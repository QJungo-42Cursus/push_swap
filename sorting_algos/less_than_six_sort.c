/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   less_than_six_sort.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qjungo <qjungo@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 15:52:10 by qjungo            #+#    #+#             */
/*   Updated: 2022/12/01 15:52:11 by qjungo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../push_swap.h"

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
	three_sort(a, b);
	pivot = size;
	while (pivot != 0)
	{
		send_lesser_greater(a, b, pivot, B, FALSE);
		pivot--;
	}
	send_lesser_greater(a, b, pivot, B, FALSE);
}
