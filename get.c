#include"libft/libft.h"
#include"push_swap.h"

/*
int		get_partition_size(t_list *a, t_list *b, t_partition, )
{
}
*/

int		top_val(t_list *a, t_list *b, t_stack s)
{
	if (s == A)
		return (*(int *)a->content);
	else
		return (*(int *)b->content);
}

t_list	*get_next_(t_list *current, t_list **a, t_list **b, t_stack stack) // get next en mode circulaire (donc pas de vrai fin)
{
	if (current->next != NULL)
		return (current->next);
	if (stack == A)
		return (*a);
	else
		return (*b);
}
