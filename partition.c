#include"libft/libft.h"
#include"push_swap.h"


/// choose partition
/// and go to top of the partition
static t_list *init_partitions(t_list **list, t_partition c_partition, t_partition *great, t_partition *less)
{
	t_list	*stack;
	stack = *list;
	*great = new_partition(A, c_partition.pivot);
	if (c_partition.stack == A)
		great->stack = B;
	*less = new_partition(c_partition.stack, c_partition.pivot);
	while (*(int *)stack->content != c_partition.top)
		stack = get_next_(stack, list, list, c_partition.stack);
	return (stack);
}

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
			great->top = contento; // -> set auto le dernier...
			if (!great->is_pivot_set)
			{
				great->pivot = contento;
				great->is_pivot_set = TRUE;
			}
			//ft_printf("contento %d \n", contento);
			stack = get_next_(stack, a, b, c_partition->stack); 
			to_other_stack(a, b, contento, c_partition->stack);

			// le nouveau top est forcemtn celui d'apres
			// donc le top de la current stack (vu qu'il vient d'etre push)
			// TODO bien de changer ca ???
			if (contento == c_partition->top)
				c_partition->top = top_val(*a, *b, c_partition->stack);
		}
		else
		{
			if (!less->is_top_set) // vu que c'est le premier + petit, il sera au top
			{
				less->top = contento;
				less->is_top_set = TRUE;
			}
			less->size++;
			less->pivot = contento; // -> sa le set auto au dernier avant le pivot actuel...
			stack = get_next_(stack, a, b, c_partition->stack); 
		}
	}
}

///	renvoie un noeud du bon cote de son parent
static void	back_to_parent(t_list **a, t_list **b, t_partition c_partition) // TODO on bouge le pivot ?? sur ??
{
	// si c'est deja chez b, on le met au top de a 
	if (c_partition.stack == B)	
		to_other_stack(a, b, c_partition.pivot, B);

	// rotate b pour etre au bon endroit quand ca va arriver
	to_stack_top(b, c_partition.parent_pivot, B);
	// si l'enfant est plus grand, on met le parent en dessous
	if (c_partition.parent_pivot < c_partition.pivot)
		operation_handler(a, b, RRB);	
	// on insert l'enfant
	to_other_stack(a, b, c_partition.pivot, c_partition.stack);
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

#ifdef LOG
	log_lists(*a, *b);
	//log_partition(a, b, c_partition, "current");
	ft_printf("\n---- c_pivot ---- \n%d (dans stack %c)\n----\n", c_partition.pivot, c_partition.stack);
#endif
	log_partition(a, b, less, "less", c_partition.pivot);
	log_partition(a, b, great, "great", c_partition.pivot);

	// TODO si le truc est a deux, on peut le foutre ailleur...
	if (great.size == 0 || less.size == 0)
	{
		ft_printf("on le fous derriere sont parrent : %d (->%d)\n", c_partition.pivot, c_partition.parent_pivot);
		back_to_parent(a, b, c_partition);
	}

	if (great.size > 1)
		partition(a, b, great);
	else if (great.size == 1)
	{
		ft_printf("on le fous derriere sont parrent : %d (->%d)\n", great.pivot, great.parent_pivot);
		back_to_parent(a, b, great);
	}
	if (less.size > 1)
		partition(a, b, less);
	else if (less.size == 1)
	{
		ft_printf("on le fous derriere sont parrent : %d (->%d)\n", less.pivot, less.parent_pivot);
		back_to_parent(a, b, less);
	}
}
