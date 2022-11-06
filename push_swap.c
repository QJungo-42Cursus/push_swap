#include"libft/libft.h"
#include"push_swap.h"

#include <stdio.h>

t_bool	is_close_to_top(int len, int pos)
{
	int	bottom_dif;

	bottom_dif = len - pos;

	if (bottom_dif == pos)
		return (TRUE);
	else if (bottom_dif > pos)
		return (TRUE);
	else
		return (FALSE);
}

void	print_stack_el(void *val)
{
	int	*v;

	v = (int *)val;
	printf("%d\n", *v);
}

void	lazy_one(t_list **stack_a, t_list **stack_b)
///	1er algo pas tres malin :
///		il va prendre le plus petit et le mettre dans la stack b, 
///		rotate et ainsi de suite...
{
	int	*min;
	int	min_pos;
	short	i;
	t_list	*ptr;

	while (*stack_a)
	{
		ptr = *stack_a;
		/* Commence par trouver le plus petit de a */
		min = (int*)ptr->content;
		i = 1;
		while (ptr)
		{
			if (*min > (*(int*)ptr->content))
			{
				min_pos = i;
				min = (int*)ptr->content;
			}
			ptr = ptr->next;
			i++;
		}

		/* Push le plus petit dans b */
		t_bool	is_closer_top = is_close_to_top(i, min_pos);
		while (min_pos != 1 && min_pos < i)
		{
			//printf("min %d min_pos %d i %d \n ", *min, min_pos, i);
			if (is_closer_top)
			{
				operation_handler(stack_a, stack_b, RA);
				min_pos--;
			}
			else 
			{
				operation_handler(stack_a, stack_b, RRA);
				min_pos++;
			}
		}
		operation_handler(stack_a, stack_b, PB);
	}
	while (*stack_b)
		operation_handler(stack_a, stack_b, PA);
}

void	push_swap(t_list **initial_stack)
{
	t_list	*stack_b;
	t_list	*stack_a;	

	stack_a = *initial_stack;
	stack_b = NULL;


	//operation_handler(&stack_a, &stack_b, PB);
	lazy_one(&stack_a, &stack_b);	

	/* TEST */
	printf("\n\nliste a : \n");
	ft_lstiter(stack_a, print_stack_el);
	printf("\nliste b\n");
	ft_lstiter(stack_b, print_stack_el);
	printf("\n\n");



	// TODO clean lists...
}
