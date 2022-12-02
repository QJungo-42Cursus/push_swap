/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bubble_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qjungo <qjungo@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 15:51:31 by qjungo            #+#    #+#             */
/*   Updated: 2022/12/02 10:36:49 by qjungo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../push_swap.h"

///	1er algo pas tres malin :
///		il va prendre le plus petit et le mettre dans la stack b, 
///		rotate et ainsi de suite...
void	bubble_sort(t_list **stack_a, t_list **stack_b)
{
	int		current_value;

	current_value = FIRST_VALUE;
	while (ft_lstsize(*stack_a) != 0)
		to_other_stack(stack_a, stack_b, current_value++, A);
	while (*stack_b)
		operation_handler(stack_a, stack_b, PA);
}
