/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qjungo <qjungo@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 15:52:55 by qjungo            #+#    #+#             */
/*   Updated: 2022/12/02 10:45:01 by qjungo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft/libft.h"

# define FIRST_VALUE 1 // la valeur de depart de la liste (varie entre 0 et 1)

typedef enum e_stack {
	A = 65,
	B = 66,
}	t_stack;

typedef enum e_operation {
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

// push_swap.c
void	push_swap(t_list **a, t_list **b);

// algos
void	bubble_sort(t_list **stack_a, t_list **stack_b);
void	stupid_sort_in_my_opinion(t_list **a, t_list **b);
void	three_sort(t_list **a, t_list **b);
void	less_than_six_sort(t_list **a, t_list **b, int size);

// first_tri.c
void	first_tri(t_list *a);
int		get_littlest(t_list *a, int treshold);

// op
void	operation_handler(t_list **stack_a,
			t_list **stack_b, t_operation operation);
void	swap_top(t_list *stack); // SA & SB
void	push(t_list **stack_from, t_list **stack_to);
void	rotate(t_list **stack);
void	r_rotate(t_list **stack);

// get
t_list	*get_next_(t_list *current, t_list **a, t_list **b, t_stack stack);

// mov
void	to_other_stack(t_list **a, t_list **b, int val, t_stack s_from);

#endif /* PUSH_SWAP_H */
