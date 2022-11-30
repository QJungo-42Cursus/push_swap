/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   most_significant_digit.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qjungo <qjungo@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 12:53:20 by qjungo            #+#    #+#             */
/*   Updated: 2022/11/30 12:53:21 by qjungo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"

///	return the number of digit of a number
static int	n_digit(int number)
	// TODO libft ??
{
	int		digit;

	digit = 1;
	while (TRUE)
	{
		if (number / ft_pow(10, digit) != 0)
			digit++;
		else
			return (digit);
	}
}

/// return le plus grand nombre de digit present dans la list
/// vu que les int_max et int_min sont a 10 digits, pas besoin
/// de chercher plus
int	most_significant_digit(t_list *a)
{
	int		number;
	int		test;

	number = 1;
	while (a != NULL)
	{
		test = n_digit(*((int *)a->content));
		if (test == 10)
			return (10);
		if (test > number)
			number = test;
		a = a->next;
	}
	return (number);
}
