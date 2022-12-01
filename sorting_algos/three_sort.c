/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   three_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qjungo <qjungo@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 15:51:25 by qjungo            #+#    #+#             */
/*   Updated: 2022/12/01 15:51:25 by qjungo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../push_swap.h"

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

void	three_sort(t_list **a, t_list **b)
{
	if (is_sorted_order(a))
		while (!is_sorted(*a))
			operation_handler(a, b, RA);
	else
	{
		operation_handler(a, b, SA);
		while (!is_sorted(*a))
			operation_handler(a, b, RA);
	}
}

