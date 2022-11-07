#include"libft/libft.h"
#include"push_swap.h"

//#define LOG


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
	/*
	if (c_partition.size <= 1)
	{
#ifdef LOG
		ft_printf("less or equal to 1..., top %d, pivot %d\n", c_partition.top, c_partition.pivot);
#endif
		return ;
	}
	*/
	t_partition		less; // la partion plus petite qu'on va creer
	t_partition		great; // la plus grande qu'on envoie dans l'autre stack
	t_list			*stack;
	int				contento;

	/// choose partition
	stack = *b;
	great = new_partition(A, c_partition.pivot);
	if (c_partition.stack == A)
	{
		stack = *a;
		great.stack = B;
	}
	less = new_partition(c_partition.stack, c_partition.pivot);
	
	/// go to top of the partition
	while (*(int *)stack->content != c_partition.top)
		stack = get_next_(stack, a, b, c_partition.stack);

	/// push tout ceux en dessous (jusquau pivot) qui sont superieux dans
	/// l'autre stack (+ recup les infos des nouvelles stacks)
	while (*(int *)stack->content != c_partition.pivot)
	{
		contento = *(int *)stack->content;
		if (contento > c_partition.pivot)
		{
			great.size++;
			great.top = contento; // -> set auto le dernier...
			if (!great.is_pivot_set)
			{
				great.pivot = contento;
				great.is_pivot_set = TRUE;
			}
			//ft_printf("contento %d \n", contento);
			stack = get_next_(stack, a, b, c_partition.stack); 
			to_other_stack(a, b, contento, c_partition.stack);

			// le nouveau top est forcemtn celui d'apres
			// donc le top de la current stack (vu qu'il vient d'etre push)
			// TODO bien de changer ca ???
			if (contento == c_partition.top)
				c_partition.top = top_val(*a, *b, c_partition.stack);
		}
		else
		{
			if (!less.is_top_set) // vu que c'est le premier + petit, il sera au top
			{
				less.top = contento;
				less.is_top_set = TRUE;
			}
			less.size++;
			less.pivot = contento; // -> sa le set auto au dernier avant le pivot actuel...
			stack = get_next_(stack, a, b, c_partition.stack); 
		}
	}
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
	}



	if (great.size > 1)
	{
#ifdef LOG
		ft_printf("\t\tgreat\t");
#endif
		partition(a, b, great);
	}
	else if (great.size == 1)
	{
		ft_printf("on le fous derriere sont parrent : %d (->%d)\n", great.pivot, great.parent_pivot);
		/*
		ft_printf("great a %d, c a %d\n", great.size, c_partition.size);
		ft_printf("current : pivot %d, top %d\n", c_partition.pivot, c_partition.top);
		ft_printf("great : pivot %d, top %d\n", great.pivot, great.top);
		*/
		//log_partition(a, b, great, "premier great a 1 ?", c_partition.pivot);
	}


	if (less.size > 1)
	{
#ifdef LOG
		ft_printf("\t\tless\t");
#endif
		partition(a, b, less);
	}
	else if (less.size == 1)
	{
		ft_printf("on le fous derriere sont parrent : %d (->%d)\n", less.pivot, less.parent_pivot);
		/*
		ft_printf("less a %d, c a %d\n", less.size, c_partition.size);
		ft_printf("current : pivot %d, top %d\n", c_partition.pivot, c_partition.top);
		ft_printf("less : pivot %d, top %d\n", less.pivot, less.top);
		*/
		//log_partition(a, b, less, "premier less a 1 ?", c_partition.pivot);

	}
}
