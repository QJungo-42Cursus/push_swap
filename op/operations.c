/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qjungo <qjungo@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 15:52:24 by qjungo            #+#    #+#             */
/*   Updated: 2022/12/02 10:39:18 by qjungo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"

///	swap a/b - swap the to element at the top
void	swap_top(t_list *stack)
{
	void	*temp_top_el;

	if (ft_lstsize(stack) < 2)
		return ;
	temp_top_el = stack->content;
	stack->content = stack->next->content;
	stack->next->content = temp_top_el;
}

///	pa & pb
///	prend le top de stack_from et le met au top de stack_to
void	push(t_list **stack_from, t_list **stack_to)
{
	t_list	*to_push;

	if (ft_lstsize(*stack_from) == 0)
		return ;
	to_push = *stack_from;
	*stack_from = to_push->next;
	to_push->next = *stack_to;
	*stack_to = to_push;
}

void	rotate(t_list **stack)
{
	t_list	*top;
	t_list	*bottom;

	top = *stack;
	*stack = top->next;
	top->next = NULL;
	bottom = ft_lstlast(*stack);
	bottom->next = top;
}

void	r_rotate(t_list **stack)
{
	t_list	*lst;
	t_list	*bottom;

	lst = *stack;
	while (lst->next->next)
		lst = lst->next;
	bottom = ft_lstlast(*stack);
	bottom->next = *stack;
	lst->next = NULL;
	*stack = bottom;
}
