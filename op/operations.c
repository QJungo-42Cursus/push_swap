#include "../libft/libft.h"

///	swap a/b - swap the to element at the top
void	swap_top(t_list *stack) // SA & SB
{
	void	*temp_top_el;

	if (ft_lstsize(stack) < 2)
		return ;
	temp_top_el = stack->content;
	stack->content = stack->next->content;
	stack->next->content = temp_top_el;
}

///	pa & pb
///	prend le top de stack_from et le met au top de stack_to
void	push(t_list **stack_from, t_list **stack_to)
{
	t_list	*to_push;

	if (ft_lstsize(*stack_from) == 0)
		return ;
	to_push = *stack_from;		// set le to push
	*stack_from = to_push->next;	// set le debut de la liste from
	
	to_push->next = *stack_to;	// set le next au debut de la stack
	*stack_to = to_push;		// set le debut de la list to

	/*
	t_list	*to_del;

	if (ft_lstsize(*stack_from) == 0)
		return ;
	ft_lstadd_front(stack_to, ft_lstnew((*stack_from)->content));
	to_del = *stack_from;
	*stack_from = to_del->next; // set le deuxieme comme le premier
				    // */
}

void	rotate(t_list **stack)
{
	t_list	*top;
	t_list	*bottom;

	top = *stack;
	*stack = top->next;
	top->next = NULL;
	bottom = ft_lstlast(*stack);
	bottom->next = top;	
}

void	r_rotate(t_list **stack)
{
	t_list	*lst;
	t_list	*bottom;

	lst = *stack;
	while(lst->next->next) // get the avant dernier
		lst = lst->next;
	bottom = ft_lstlast(*stack);
	bottom->next = *stack;
	

	lst->next = NULL;


	*stack = bottom;
}
