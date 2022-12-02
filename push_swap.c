/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qjungo <qjungo@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 10:44:04 by qjungo            #+#    #+#             */
/*   Updated: 2022/12/02 10:44:04 by qjungo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"

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

void	push_swap(t_list **a, t_list **b)
{
	int		size;

	size = ft_lstsize(*a);
	first_tri(*a);
	if (is_sorted(*a))
		return ;
	if (size == 2)
		operation_handler(a, b, SA);
	if (size <= 3)
		three_sort(a, b);
	else if (size <= 6)
		less_than_six_sort(a, b, size);
	else if (size <= 50)
		bubble_sort(a, b);
	else
		stupid_sort_in_my_opinion(a, b);
}
