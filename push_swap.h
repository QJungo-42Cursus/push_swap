#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft/libft.h"

typedef enum e_stack {
	A = 65,
	B = 66,
}	t_stack;

typedef struct s_partition {
	int			top;
	int			pivot;
	int			size;
	int			parent_pivot;
	t_bool		is_pivot_set;
	t_bool		is_top_set;
	t_bool		is_first;
	t_stack		stack;
}	t_partition;

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

void		push_swap(t_list **a, t_list **b);

void		operation_handler(t_list **stack_a, t_list **stack_b, t_operation operation);
void		swap_top(t_list *stack); // SA & SB
void		push(t_list **stack_from, t_list **stack_to);
void		rotate(t_list **stack);
void		r_rotate(t_list **stack);

// log
void		log_lists(t_list *a, t_list *b);
void		log_partition(t_list **a, t_list **b, t_partition c_partition, char *msg, int from_pivot);

// algos
void		bubble_sort(t_list **stack_a, t_list **stack_b);
void		partition(t_list **a, t_list **b, t_partition partition);
void		quicksort(t_list **a, t_list **b);

// get
t_list		*get_next_(t_list *current, t_list **a, t_list **b, t_stack stack);
int			top_val(t_list *a, t_list *b, t_stack s);

// mov
void		to_stack_top(t_list **stack, int val, t_stack s_from);
void		to_other_stack(t_list **a, t_list **b, int val, t_stack s_from);
void		greater_to_top(t_list **list, t_stack stack);
void		repeat_op(t_list **a, t_list **b, int n, t_operation op);

// new
t_partition	new_partition(t_stack stack, int parent_pivot);
t_list		*init_partitions(t_list **list, t_partition c_partition, t_partition *great, t_partition *less);

#endif /* PUSH_SWAP_H */
