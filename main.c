# include "libft/libft.h"
# include "push_swap.h"

static int	init_stack(int argc, char **argv, t_list **stack);
static int	test_list(int argc, char **argv);

int main(int argc, char **argv)
{
	t_list	*a;
	t_list	*b;
	
	argc--;
	argv++;
	a = NULL;
	b = NULL;
	if (argc == 0 || test_list(argc, argv) || init_stack(argc, argv, &a))
	{
		ft_printf("Error\n");
		return (0);
	}
	push_swap(&a, &b);
	ft_lstclear(&a, free);
	ft_lstclear(&b, free);
}

static int	is_long(char *str)
{
	long	num;

	num = long_atoi(str);
	if (num < INT_MIN)
		return (TRUE);
	if (num > INT_MAX)
		return (TRUE);
	return (FALSE);
}

static int	test_list(int argc, char **argv)
{
	int		i;
	int		j;

	i = 0;
	while (i < argc)
	{
		j = 0;
		if (is_long(argv[i]))
			return (ERROR);
		if (argv[i][0] == '-')
			j++;
		while (argv[i][j] != '\0')
		{
			if (!ft_isdigit(argv[i][j]))
				return (ERROR);
			j++;
		}
		i++;
	}
	return (SUCCESS);
}

static int init_stack(int argc, char **argv, t_list **stack)
{
	int		i;
	int		*numbers;
	t_list	*ptr;

	i = 0;
	while (i < argc)
	{
		numbers = malloc(sizeof(int));
		*numbers = ft_atoi(argv[i]);
		ptr = *stack;
		while (ptr != NULL)
		{
			if (*(int *)ptr->content == *numbers)
			{
				ft_lstclear(stack, free);
				free(numbers);
				return (ERROR);
			}
			ptr = ptr->next;
		}
		ft_lstadd_back(stack, ft_lstnew(numbers));
		i++;
	}
	return (SUCCESS);
}
