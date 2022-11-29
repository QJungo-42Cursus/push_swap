
#include "../libft/libft.h"

///	return the number of digit of a number
int	n_digit(int number)
{
	int		digit;

	digit = 1;
	while (TRUE)
	{
		if (number / ft_pow(10, digit) != 0)
			digit++;
		else
			return (digit);
	}
}

/// return le plus grand nombre de digit present dans la list
/// vu que les int_max et int_min sont a 10 digits, pas besoin
/// de chercher plus
int	most_significant_digit(t_list *a)
{
	int		number;
	int		test;

	number = 1;
	while (a != NULL)
	{
		test = n_digit(*((int *)a->content));
		if (test == 10)
			return (10);
		if (test > number)
			number = test;
		a = a->next;
	}
	return (number);
}

/*
void	radix_sort(t_list **a, t_list **b)
{
	int		msd;

	msd = most_significant_digit(*a);
}
*/


/*
 * TESTS
 */

#include "../tests/tests.h"
#include <stdio.h>
#include "limits.h"
int	main()
{
	printf("n_digit of %d = %d\n", 8437, n_digit(8437));
	printf("n_digit of %d = %d\n", 0, n_digit(0));
	int i = 0;
	while (i != 1000000)
	{
		//printf("n_digit of %d = %d\n", 123456789, n_digit(123456789));
		n_digit(123456789);
		i++;
	}
	printf("100000 calculs effectue...\n");
	return 0;

	int	av[5] = {1, 3, 4, 200, 1000000000};
	t_list *a = NULL;
	init_stack(5, av, &a);
	log_lists(a, NULL);
	printf("msd : %d\n", most_significant_digit(a));
}
