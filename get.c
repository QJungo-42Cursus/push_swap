#include"libft/libft.h"
#include"push_swap.h"

///		Return la valeur en haut d'une stack
int		top_val(t_list *a, t_list *b, t_stack s)
{
	if (s == A)
		return (*(int *)a->content);
	else
		return (*(int *)b->content);
}

///		Return la valeur en bas d'une stack
int		bottom_val(t_list *list)
{
	while (list != NULL)
		list = list->next;
	return (*(int *)list->content);
}

///		Renvoie le prochain element de la list.
///		Si le next est NULL, renvoie le premier element de la list
static t_list	*get_next_node(t_list *current, t_list **list)
{
// TODO libft
	if (current->next != NULL)
		return (current->next);
	return (*list);
}

///		Version pratique dans les fonctions
///		Choisi entre les stack
t_list	*get_next_(t_list *current, t_list **a, t_list **b, t_stack stack)
{
	if (stack == A)
		return (get_next_node(current, a));
	else
		return (get_next_node(current, b));
}
