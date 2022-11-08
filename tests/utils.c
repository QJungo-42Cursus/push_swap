# include "../libft/libft.h"
# include "../push_swap.h"
# include "../quicksort/quicksort.h"

int init_stack(int argc, int *numbers, t_list **stack_a)
{
	int		i;
	int		*number;

	i = 0;
	while (i < argc)
	{
		number = malloc(sizeof(int));
		*number = numbers[i];
		ft_lstadd_back(stack_a, ft_lstnew(number));
		i++;
	}
	return (SUCCESS);
}


// TODO libft
void	ok()
{
	ft_color(GREEN, BOLD);
	ft_printf("OK.\n");
	ft_color(RESET, 0);
}

void	ko()
{
	ft_color(RED, BOLD);
	ft_printf("KO.\n");
	ft_color(RESET, 0);
}

void	title(t_color color, char *title)
{
	ft_color(color, BOLD);
	ft_printf("%s\n", title);
	ft_color(RESET, 0);
}