/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mov.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qjungo <qjungo@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 15:52:19 by qjungo            #+#    #+#             */
/*   Updated: 2022/12/01 15:58:19 by qjungo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../push_swap.h"

/// repeat an operation n time
static void	repeat_op(t_list **a, t_list **b, int n, t_operation op)
{
	while (n > 0)
	{
		operation_handler(a, b, op);
		n--;
	}
}

/// push a value to the top of the stack in the quickest direction
static void	to_stack_top(t_list **stack, int val, t_stack s_from)
{
	int			distance;
	t_list		*ptr;
	int			lstsize;
	
	ptr = *stack;
	lstsize = ft_lstsize(ptr);
	distance = 0;
	while (*(int *)ptr->content != val && distance++ != -1)
		ptr = get_next_(ptr, stack, stack, s_from);

	if (distance > lstsize / 2)
	{
		if (s_from == A)
			repeat_op(stack, NULL, lstsize - distance, RRA);
		else
			repeat_op(NULL, stack, lstsize - distance, RRB);
	}
	else
	{
		if (s_from == A)
			repeat_op(stack, NULL, distance, RA);
		else
			repeat_op(NULL, stack, distance, RB);
	}
}

/// push the value to the top of the other stack by the quickest way
void	to_other_stack(t_list **a, t_list **b, int val, t_stack s_from)
{
	if (s_from == A)
	{
		to_stack_top(a, val, s_from); 
		operation_handler(a, b, PB);
	}
	else
	{
		to_stack_top(b, val, s_from); 
		operation_handler(a, b, PA);
	}
}
