/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   less_than_six_sort.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qjungo <qjungo@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 15:52:10 by qjungo            #+#    #+#             */
/*   Updated: 2022/12/02 11:06:01 by qjungo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../push_swap.h"

typedef struct s_norm {
	int		pivot;
	t_stack	current_stack;
	t_bool	lesser;
}	t_norm;

static void	send_lesser_greater(t_list **a, t_list **b, t_norm norm)
{
	int		value;
	t_list	*stack;

	if (norm.current_stack == A)
		stack = *a;
	else
		stack = *b;
	while (stack != NULL)
	{
		value = *(int *)stack->content;
		stack = stack->next;
		if (norm.lesser && value < norm.pivot)
			to_other_stack(a, b, value, norm.current_stack);
		else if (!norm.lesser && value > norm.pivot)
			to_other_stack(a, b, value, norm.current_stack);
	}
}

void	less_than_six_sort(t_list **a, t_list **b, int size)
{
	t_norm	norm;

	norm.current_stack = A;
	norm.lesser = TRUE;
	norm.pivot = size - 2;
	send_lesser_greater(a, b, norm);
	three_sort(a, b);
	norm.pivot = size;
	norm.current_stack = B;
	norm.lesser = FALSE;
	while (norm.pivot != 0)
	{
		send_lesser_greater(a, b, norm);
		norm.pivot--;
	}
	send_lesser_greater(a, b, norm);
}
