#include "libft/libft.h"
#include "push_swap.h"

static void	init_stack_a(int argc, char **argv, t_list **stack_a);
static int	is_list_correct(int argc, char **argv);

int main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;
	
	argc--;
	argv++;
	if (argc == 0)
	{
		ft_printf("Error\n (not enought argc)");
		return (0);
	}
	if (!is_list_correct(argc, argv))
	{
		ft_printf("Error\n (args are not integers)");
		return (0);
	}
	stack_a = NULL;
	stack_b = NULL;
	init_stack_a(argc, argv, &stack_a);
	push_swap(&stack_a, &stack_b);
	ft_lstclear(&stack_a, free);
	ft_lstclear(&stack_b, free);
}

static void	init_stack_a(int argc, char **argv, t_list **stack_a)
{
	int		i;
	int		*numbers;

	i = 0;
	while (i < argc)
	{
		numbers = malloc(sizeof(int));
		*numbers = ft_atoi(argv[i]);
		ft_lstadd_back(stack_a, ft_lstnew(numbers));
		i++;
	}
}

static int	is_list_correct(int argc, char **argv)
{
	int		i;
	int		j;
	int		*nums;

	i = 0;
	while (i < argc)
	{
		j = 0;
		if (argv[i][0] == '-')
			j++;
		while (argv[i][j] != '\0')
		{
			if (!ft_isdigit(argv[i][j]))
				return (0);
			j++;
		}
		i++;
		// TODO gerer les longs ints ???
	}
	nums = malloc(sizeof(int) * argc);
	i = 0;
	while (i < argc)
	{
		j = i - j;
		nums[i] = ft_atoi(argv[i]);
		while (j > 0)
		{
			if (nums[i] == nums[j])
			j--;
		}
		i++;
	}
	return (1);
}
