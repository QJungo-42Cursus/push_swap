/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qjungo <qjungo@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 13:41:14 by qjungo            #+#    #+#             */
/*   Updated: 2022/08/13 21:51:51 by qjungo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include"libft/libft.h"

typedef enum {
	SA,
	SB,
	SS,
	PA,
	PB,
	RA,
	RB,
	RR,
	RRA,
	RRB,
	RRR,
}	t_operation;

void	push_swap(t_list **initial_stack);

void	operation_handler(t_list **stack_a, t_list **stack_b, t_operation operation);
void	swap_top(t_list *stack); // SA & SB
void	push(t_list **stack_from, t_list **stack_to);
void	rotate(t_list **stack);
void	r_rotate(t_list **stack);

#endif /* PUSH_SWAP_H */
