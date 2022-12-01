#ifndef QUICKSORT_H
# define QUICKSORT_H
# include "../libft/libft.h"
# include "../push_swap.h"

void	back_to_parent(t_list **a, t_list **b, t_partition c_partition);
void	loop(t_list **a, t_list **b, t_list *stack, t_partition *c_partition, t_partition *great, t_partition *less);
void	partition(t_list **a, t_list **b, t_partition c_partition);

#endif /* QUICKSORT_H */
