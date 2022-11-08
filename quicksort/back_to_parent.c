#include "../libft/libft.h"
#include "../push_swap.h"
#include "quicksort.h"

static int	if_side(t_list **a, t_list **b, t_partition c_partition, int is_child_greater);

///	renvoie un noeud du bon cote de son parent
// on bouge le pivot ?? sur ??
void	back_to_parent(t_list **a, t_list **b, t_partition c_partition)
{
	t_bool	is_child_greater;

	is_child_greater = c_partition.parent_pivot < c_partition.pivot;
	// si c'est deja chez b, on check s'il sont a cote on le met au top de a 
	if (c_partition.stack == B)	
	{
		if (if_side(a, b, c_partition, is_child_greater))
			return ;
		to_other_stack(a, b, c_partition.pivot, B);
	}

	// rotate b pour etre au bon endroit quand ca va arriver
	to_stack_top(b, c_partition.parent_pivot, B);
	//ft_printf("parent to stack top -> ");
	//log_lists(*a, *b);
	// si l'enfant est est plus grand, on met le parent en dessous
	if (!is_child_greater)
	{
		operation_handler(a, b, RB);	
		//ft_printf("invert if child is greater -> ");
		//log_lists(*a, *b);
	}

	// on insert l'enfant
	to_other_stack(a, b, c_partition.pivot, A);
}

static int	if_side(t_list **a, t_list **b, t_partition c_partition, int is_child_greater)
{
	t_list	*ptr;
	int		up;
	int		down;

	// S'il sont deja a cote...
	ptr = *b;
	while (1)
	{
		up = *(int *)ptr->content;
		/// en cherchant le suivant direct,
		/// ca enleve le besoin d'avoir une function
		/// qui check en haut et en bas
		ptr = get_next_(ptr, NULL, b, B);
		down = *(int *)ptr->content;
		if (up == c_partition.parent_pivot && down == c_partition.pivot)
		{
			/// Le parent est au dessus,
			/// donc l'enfant devrait etre plus grand
			if (is_child_greater)
			{
				to_stack_top(b, up, B);
				operation_handler(a, b, SB);
			}
			return (TRUE);
		}
		if (up == c_partition.pivot && down == c_partition.parent_pivot)
		{
			if (!is_child_greater)
			{
				to_stack_top(b, up, B);
				operation_handler(a, b, SB);
			}
			return (TRUE);
		}
		// si y'a l'un des deux mais pas l'autre, on continue
		if (up == c_partition.parent_pivot || up == c_partition.pivot)
			return (FALSE);
	}
}
