//#ifdef BTP_TEST
# include "../libft/libft.h"
# include "../push_swap.h"
# include "../quicksort/quicksort.h"

///		back_to_parent(t_list **a, t_list **b, t_partition c_partition)
///		_______________________________________________________________
///		parameters:
///		**a			-> la list a
///		**b			-> la list b
///		c_partition	-> la partition en cours
///			- La fonction est appelee si noeud en cours n'a pas d'enfant.
///			- On part du principe que le parent est forcement dans b.
///		_______________________________________________________________
///		fonctionnement:
///			- Va mettre le noeud a cote de son parent dans la stack b.
///			- Le tri final se veux descendant, dans la stack b,
///				le noeud se mettra donc en dessus/ dessous en consequence
///			- Verifie d'abors si le parent et le noeud ne sont pas a cote
///				ou a la fin et au debut
///			- Si non, le noeud est pousse dans la stack a, le parent est
///				monte au bon endroit (<) et le noeud est pousse dans b
///		_______________________________________________________________
///		return: void

static int init_stack(int argc, int *numbers, t_list **stack_a)
{
	int		i;
	t_list	*ptr;

	i = 0;
	while (i < argc)
	{
		ptr = *stack_a;
		ft_lstadd_back(stack_a, ft_lstnew(&numbers[i]));
		i++;
	}
	return (SUCCESS);
}

static void	test(int as, int *av, int bs, int *bv, t_partition partition)
{
	t_list	*a;
	t_list	*b;
	
	a = NULL;
	b = NULL;
	init_stack(as, av, &a);
	init_stack(bs, bv, &b);

	ft_printf("initial state of the lists :");
	log_lists(a, b);

	ft_printf("initial state of the lists :");
	back_to_parent(&a, &b, partition);
	log_lists(a, b);

	ft_lstclear(&a, free);
	ft_lstclear(&b, free);
}

int main()
{
	t_partition	p;

	int			a[5] = {1, 3, 4, 200, 500};
	int			b[4] = {98, 100, 85, -5};
	test(5, a, 4, b, p);

	return (0);
	int			a1[5] = {1, 3, 4, 200, 500};
	int			b1[4] = {98, 100, 85, -5};
	test(5, a, 4, b, p);

	int			a2[5] = {1, 3, 4, 200, 500};
	int			b2[4] = {98, 100, 85, -5};
	test(5, a, 4, b, p);
}

//#endif /* BTP_TEST */
