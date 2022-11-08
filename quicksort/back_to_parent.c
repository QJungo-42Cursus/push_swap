#include "../libft/libft.h"
#include "../push_swap.h"
#include "quicksort.h"

static int	if_opposite(t_list **a, t_list **b, t_partition c_partition);
static int	if_side(t_list **a, t_list **b, t_partition c_partition);

///	renvoie un noeud du bon cote de son parent
// on bouge le pivot ?? sur ??
void	back_to_parent(t_list **a, t_list **b, t_partition c_partition)
{
	t_bool	is_child_greater;

	is_child_greater = c_partition.parent_pivot < c_partition.pivot;

	if (if_side(a, b, c_partition))
		return ;
	if (if_opposite(a, b, c_partition))
		return ;

	// si c'est deja chez b, on le met au top de a 
	if (c_partition.stack == B)	
	{
		//ft_printf("to other stack\n");
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
	//ft_printf("child to good stack -> ");
	//log_lists(*a, *b);

	greater_to_top(b, B);
	//ft_printf("greater_to_top -> ");
	//log_lists(*a, *b);
}

static int	if_opposite(t_list **a, t_list **b, t_partition c_partition)
{
	// TODO decaler de 1 et if_side
	//if_side(a, b, c_partition);

	return (0);
}

static int	if_side(t_list **a, t_list **b, t_partition c_partition)
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
			//log_lists(*a, *b);
			return (1);
		}
		if (up == c_partition.pivot && down == c_partition.parent_pivot)
		{
			if (is_child_greater)
			{
				to_stack_top(b, up, B);
				operation_handler(a, b, SB);
			}
			//log_lists(*a, *b);
			return (1);
		}
		// si y'a l'un des deux mais pas l'autre, on continue
		if (up == c_partition.parent_pivot || up == c_partition.pivot)
			return (0);
	}
}
