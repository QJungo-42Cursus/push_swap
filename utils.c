/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qjungo <qjungo@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 18:51:27 by qjungo            #+#    #+#             */
/*   Updated: 2022/11/06 18:52:07 by qjungo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"

void	print_stack_el(void *val)
{
	int	*v;

	v = (int *)val;
	ft_printf("%d\n", *v);
}