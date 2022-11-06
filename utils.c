/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qjungo <qjungo@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 18:51:27 by qjungo            #+#    #+#             */
/*   Updated: 2022/11/06 19:49:27 by qjungo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"

void	print_stack_el(void *val)
{
	int	*v;

	v = (int *)val;
	ft_printf("%d\n", *v);
}

void	log_lists(t_list *a, t_list *b)
{
	ft_printf("\n\nliste a : \n");
	ft_lstiter(a, print_stack_el);
	ft_printf("\nliste b\n");
	ft_lstiter(b, print_stack_el);
	ft_printf("\n\n");
}
