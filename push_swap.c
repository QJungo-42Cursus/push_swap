#include"libft/libft.h"
#include"push_swap.h"

void	push_swap(t_list **a, t_list **b)
{
	/*
	t_list	*stack_b;
	t_list	*stack_a;	

	stack_a = *a;
	stack_b = *b;
	*/


	bubble_sort(a, b);	
	/* TEST
	printf("\n\nliste a : \n");
	ft_lstiter(stack_a, print_stack_el);
	printf("\nliste b\n");
	ft_lstiter(stack_b, print_stack_el);
	printf("\n\n");
	 */
}
