/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_tri.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qjungo <qjungo@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 09:30:35 by qjungo            #+#    #+#             */
/*   Updated: 2022/12/01 14:45:58 by qjungo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"

int	get_littlest(t_list *a, int treshold)
{
	int		littlest;
	int		*content;

	littlest = INT_MAX;
	while (a != NULL)
	{
		content = (int *)a->content;
		if (*content < littlest && *content > treshold)
			littlest = *content;
		a = a->next;
	}
	return (littlest);
}

static void	change_value(t_list *a, int value, int new_value)
{
	int		*content;

	while (a != NULL)
	{
		content = (int *)a->content;
		if (*content == value)
		{
			*content = new_value;
			return ;
		}
		a = a->next;
	}
}

static void	shift_all_value_in_list(t_list *a, int padding)
{
	int		*content;

	while (a != NULL)
	{
		content = (int *)a->content;
		*content -= padding;
		*content += FIRST_VALUE;
		a = a->next;
	}
}

/// commence par trouver le plus petit, le garde a cette valeur qui fera office de 0 !
/// remplacer chaque valeur par sa position finale
/// cherche le plus petit et lui donne le chiffre 0 (ou 1)
/// et augmente de maniere debile jusqua la fin !
/// Enfin, decale tout pour arriver a ce que le plus petit sois a 0 (ou 1)
static void	tri(t_list *a, int littlest, int current, t_bool is_first)
{
	if (is_first)
	{
		littlest = get_littlest(a, INT_MIN);
		current = littlest;
		tri(a, littlest, current, FALSE);
		return ;
	}
	if (current == INT_MAX)
		return ;
	current = get_littlest(a, current);
	littlest++;
	change_value(a, current, littlest);
	tri(a, littlest, current, FALSE);
}

void	first_tri(t_list *a)
{
	tri(a, 0, 0, TRUE);
	shift_all_value_in_list(a, get_littlest(a, INT_MIN));
}
