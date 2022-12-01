/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qjungo <qjungo@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 15:51:12 by qjungo            #+#    #+#             */
/*   Updated: 2022/12/01 15:56:03 by qjungo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../push_swap.h"

///		Renvoie le prochain element de la list.
///		Si le next est NULL, renvoie le premier element de la list
// TODO libft
static t_list	*get_next_node(t_list *current, t_list **list)
{
	if (current->next != NULL)
		return (current->next);
	return (*list);
}

///		Version pratique dans les fonctions
///		Choisi entre les stack
t_list	*get_next_(t_list *current, t_list **a, t_list **b, t_stack stack)
{
	if (stack == A)
		return (get_next_node(current, a));
	else
		return (get_next_node(current, b));
}
