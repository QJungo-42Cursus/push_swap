#include "libft/libft.h"
#include "push_swap.h"


/// push tout ceux en dessous (jusquau pivot) qui sont superieux dans
/// l'autre stack (+ recup les infos des nouvelles stacks)
static void	loop(t_list **a, t_list **b, t_list *stack, t_partition *c_partition, t_partition *great, t_partition *less)
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

///	renvoie un noeud du bon cote de son parent
// on bouge le pivot ?? sur ??
static void	back_to_parent(t_list **a, t_list **b, t_partition c_partition)
{
	t_list	*ptr;
	t_bool	is_child_greater;
	int		up;
	int		down;

	is_child_greater = c_partition.parent_pivot < c_partition.pivot;

	// S'il sont deja a cote...
	ptr = *b;
	while (1)
	{
		up = *(int *)ptr->content;
		ptr = get_next_(ptr, NULL, b, B);
		down = *(int *)ptr->content;
		if (up == c_partition.parent_pivot && down == c_partition.pivot)
		{
			if (!is_child_greater)
			{
				to_stack_top(b, up, B);
				operation_handler(a, b, SB);
			}
			log_lists(*a, *b);
			return ;
		}
		if (up == c_partition.pivot && down == c_partition.parent_pivot)
		{
			if (is_child_greater)
			{
				to_stack_top(b, up, B);
				operation_handler(a, b, SB);
			}
			log_lists(*a, *b);
			return ;
		}
		// si y'a l'un des deux mais pas l'autre, on continue
		if (up == c_partition.parent_pivot || up == c_partition.pivot)
			break;
	}

	// si c'est deja chez b, on le met au top de a 
	if (c_partition.stack == B)	
	{
		ft_printf("to other stack\n");
		to_other_stack(a, b, c_partition.pivot, B);
	}

	// rotate b pour etre au bon endroit quand ca va arriver
	to_stack_top(b, c_partition.parent_pivot, B);
	ft_printf("parent to stack top -> ");
	log_lists(*a, *b);
	// si l'enfant est est plus grand, on met le parent en dessous
	if (!is_child_greater)
	{
		operation_handler(a, b, RB);	
		ft_printf("invert if child is greater -> ");
		log_lists(*a, *b);
	}

	// on insert l'enfant
	to_other_stack(a, b, c_partition.pivot, A);
	ft_printf("child to good stack -> ");
	log_lists(*a, *b);

	greater_to_top(b, B);
	ft_printf("greater_to_top -> ");
	log_lists(*a, *b);
}

/// depuis l'index de debut et de fin de la partition
/// comparer le nombre de fin au reste et envoyer en 
/// haut de l'autre pile (peu importe laquelle) tout ceux qui 
/// son superieur a celui la. En meme temp -> actualiser les infos
/// des partitions qu'on creer
void	partition(t_list **a, t_list **b, t_partition c_partition)
{
#ifdef LOG
	ft_printf("NEW PARTITIONING\n");
#endif
	t_partition		less;
	t_partition		great;
	t_list			*stack;

	if (c_partition.stack == A)
		stack = init_partitions(a, c_partition, &great, &less);
	else
		stack = init_partitions(b, c_partition, &great, &less);
	loop(a, b, stack, &c_partition, &great, &less);
	// si dans a, on met le current (le parent des suivants) dans b
	if (c_partition.stack == A)
	{
		to_other_stack(a, b, c_partition.pivot, A);
		c_partition.stack = B;
	}
	

	log_lists(*a, *b);
	//log_partition(a, b, c_partition, "current");
	ft_printf("\n---- c_pivot ---- \n%d (dans stack %c)\n----\n", c_partition.pivot, c_partition.stack);
	log_partition(a, b, less, "less", c_partition.pivot);
	log_partition(a, b, great, "great", c_partition.pivot);

	// TODO si le truc est a deux, on peut le foutre ailleur...
	if (!c_partition.is_first && (great.size == 0 || less.size == 0))
	{
		ft_printf("2 enfants a 0 -> ");
		ft_printf("on le fous derriere sont parrent : %d (->%d)\n", c_partition.pivot, c_partition.parent_pivot);
		back_to_parent(a, b, c_partition);
	}

	if (great.size > 1)
		partition(a, b, great);
	else if (great.size == 1)
	{
		ft_printf("great) on le fous derriere sont parrent : %d (->%d)\n", great.pivot, great.parent_pivot);
		back_to_parent(a, b, great);
	}
	if (less.size > 1)
		partition(a, b, less);
	else if (less.size == 1)
	{
		ft_printf("less) on le fous derriere sont parrent : %d (->%d)\n", less.pivot, less.parent_pivot);
		back_to_parent(a, b, less);
	}
}

void	quicksort(t_list **a, t_list **b)
{
	t_partition		first_partition;
	t_list			*last;

	first_partition = new_partition(A, 0);
	first_partition.top = *(int *)((*a)->content);
	last = ft_lstlast(*a);
	first_partition.pivot = *(int *)((last)->content);
	first_partition.size = ft_lstsize(*a);
	first_partition.is_first = TRUE;
	partition(a, b, first_partition);
	log_lists(*a, *b);


	// TODO mettre le + grand en haut !!!

	greater_to_top(b, B);
	repeat_op(a, b, first_partition.size, PA);
}
