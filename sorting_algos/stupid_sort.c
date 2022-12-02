/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stupid_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qjungo <qjungo@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 15:51:19 by qjungo            #+#    #+#             */
/*   Updated: 2022/12/02 11:00:33 by qjungo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include "../libft/libft.h"

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

static void	pass1(t_list **a, t_list **b, int size)
{
	t_norm	norm;

	norm.pivot = size / 2;
	norm.current_stack = A;
	norm.lesser = FALSE;
	while (norm.pivot != 0)
	{
		send_lesser_greater(a, b, norm);
		norm.pivot = norm.pivot / 2;
	}
	norm.pivot = 0;
	send_lesser_greater(a, b, norm);
	norm.pivot = 1;
	norm.current_stack = B;
	norm.lesser = TRUE;
	while (norm.pivot < size / 2)
	{
		send_lesser_greater(a, b, norm);
		norm.pivot = norm.pivot * 2;
	}
	send_lesser_greater(a, b, norm);
	norm.pivot = size + 1;
	send_lesser_greater(a, b, norm);
}

void	stupid_sort_in_my_opinion(t_list **a, t_list **b)
{
	int		size;
	int		divider;
	t_norm	norm;

	size = ft_lstsize(*a);
	pass1(a, b, size);
	divider = size / 11;
	norm.pivot = size;
	norm.current_stack = A;
	norm.lesser = FALSE;
	while (norm.pivot > 0)
	{
		send_lesser_greater(a, b, norm);
		norm.pivot = norm.pivot - divider;
	}
	norm.pivot = 0;
	send_lesser_greater(a, b, norm);
	norm.pivot = size;
	norm.current_stack = B;
	while (norm.pivot != 0)
	{
		send_lesser_greater(a, b, norm);
		norm.pivot--;
	}
	send_lesser_greater(a, b, norm);
}
