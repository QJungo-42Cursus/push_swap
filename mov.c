#include"libft/libft.h"
#include"push_swap.h"

void	to_top(t_list **stack, int pos, t_stack s)
{
	while (pos >= 1)
	{
		if (s == A)
			operation_handler(stack, NULL, RA);
		else
			operation_handler(NULL, stack, RB);
		pos--;
	}
}

void	to_bottom(t_list **stack, int pos, int len, t_stack s)
{
	while (pos < len && pos != 1)
	{
		if (s == A)
			operation_handler(stack, NULL, RRA);
		else
			operation_handler(NULL, stack, RRB);
		pos++;
	}
}

void	to_other_stack(t_list **a, t_list **b, int val, t_stack s_from)
{
	t_operation	op;
	int			distance;
	t_list		*ptr;
	t_list		**from;
	int			lstsize;
	
	ptr = *a;
	from = a;
	op = PB;
	if (s_from == B)
	{
		ptr = *b;
		from = b;
		op = PA;
	}
	lstsize = ft_lstsize(ptr);
	distance = 0;
	while (*(int *)ptr->content != val && ptr != NULL)
	{
		distance++;
		ptr = ptr->next;
	}
	if (distance > lstsize / 2)
		to_bottom(from, distance, lstsize, s_from);
	else
		to_top(from, distance, s_from);
	operation_handler(a, b, op);
}
