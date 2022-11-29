//#ifdef BTP_TEST
# include "../libft/libft.h"
# include "../push_swap.h"
# include "../quicksort/quicksort.h"
# include "tests.h"

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
static void	test(int as, int *av, int bs, int *bv, t_partition partition)
{
	t_list	*a = NULL;
	t_list	*b = NULL;
	t_bool	is_child_greater = partition.parent_pivot < partition.pivot;
	init_stack(as, av, &a);
	init_stack(bs, bv, &b);
	//log_lists(a, b);

	back_to_parent(&a, &b, partition);
	if (is_child_greater)
	{
		if (*(int *)b->content == partition.pivot && *(int *)b->next->content == partition.parent_pivot)
			ok();
		else
		{
			ko();
			ft_printf("Pivot %d should be at first place, Parent %d second\n", partition.pivot, partition.parent_pivot);
			log_lists(a, b);
			ft_color(RESET, 0);
		}
	}
	else
	{
		if (*(int *)b->content == partition.pivot && bottom_val(b) == partition.parent_pivot)
			ok();
		else
		{
			ko();
			ft_printf("Pivot %d should be at first place, Parent %d to the bottom\n", partition.pivot, partition.parent_pivot);
			log_lists(a, b);
			ft_color(RESET, 0);
		}
	}
	ft_lstclear(&a, free);
	ft_lstclear(&b, free);
}

/*
t_partition	new_partition(t_stack stack, int parent_pivot)
{
	t_partition	n;

	n.stack = stack;
	n.size = 0;
	n.top = 0;
	n.pivot = 0;
	n.parent_pivot = parent_pivot;
	n.is_pivot_set = FALSE;
	n.is_top_set = FALSE;
	n.is_first = FALSE;
	return (n);
}
*/

int main()
{
	t_partition	p = new_partition(A, 100);
	int	a[5] = {1, 3, 4, 200, 500};
	int	b[4] = {98, 100, 85, -5};

	title(BLUE, "TEST 1\n");
	p.pivot = 1;
	test(5, a, 4, b, p);

	title(BLUE, "TEST 2\n");
	p.pivot = 3;
	test(5, a, 4, b, p);

	title(BLUE, "TEST 3\n");
	p.pivot = 4;
	test(5, a, 4, b, p);

	title(BLUE, "TEST 4\n");
	p.pivot = 200;
	test(5, a, 4, b, p);

	title(BLUE, "TEST 5\n");
	p.pivot = 500;
	test(5, a, 4, b, p);

	p.stack = B;
	title(BLUE, "TEST 6\n"); // TODO 
	p.pivot = 98;
	test(5, a, 4, b, p);

	title(BLUE, "TEST 7\n");
	p.pivot = 85;
	test(5, a, 4, b, p);

	title(BLUE, "TEST 8\n");
	p.pivot = -5;
	test(5, a, 4, b, p);

	int			a1[5] = {1, 3, 4, 200, 500};
	int			b1[4] = {100, 101, 85, -5};

	title(BLUE, "TEST 9\n");
	p.stack = B;
	p.parent_pivot = 100;
	p.pivot = 101;
	test(5, a1, 4, b1, p);

	int			a2[4] = {3, 4, 700, 500};
	int			b2[4] = {701};

	title(BLUE, "TEST 10");
	p.stack = A;
	p.parent_pivot = 701;
	p.pivot = 700;
	test(4, a2, 4, b2, p);
}

//#endif /* BTP_TEST */
