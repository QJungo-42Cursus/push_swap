#include "../libft/libft.h"
#include "../push_swap.h"
#include "quicksort.h"

/// push (jusquau pivot) les noeuds qui sont superieux dans
/// l'autre stack (+ recup les infos des nouvelles stacks)
void	loop(t_list **a, t_list **b, t_list *stack, t_partition *c_partition, t_partition *great, t_partition *less)
{
	int		contento;
	while (*(int *)stack->content != c_partition->pivot)
	{
		contento = *(int *)stack->content;
		if (contento > c_partition->pivot)
		{
			great->size++;
			great->top = contento;
			if (!great->is_pivot_set)
			{
				great->pivot = contento;
				great->is_pivot_set = TRUE;
			}
			stack = get_next_(stack, a, b, c_partition->stack); 
			to_other_stack(a, b, contento, c_partition->stack);
			// le nouveau top est forcemtn celui d'apres
			// donc le top de la current stack (vu qu'il vient d'etre push)
			if (contento == c_partition->top)
				c_partition->top = top_val(*a, *b, c_partition->stack);
		}
		else
		{
			if (!less->is_top_set)
			{
				less->top = contento;
				less->is_top_set = TRUE;
			}
			less->size++;
			less->pivot = contento;
			stack = get_next_(stack, a, b, c_partition->stack); 
		}
	}
}
