#include "../libft/libft.h"
#include "radix_sort.h"

#include <stdio.h>
#include "../tests/tests.h"
void	radix_sort(t_list **a, t_list **b)
{
	int		msd;

	msd = most_significant_digit(*a);
	printf("msd : %d\n", msd);
	(void)b;
}


/*
 * TESTS

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
	int	av[5] = {1, 3, 4, 200, 1000000000};
	t_list *a = NULL;
	init_stack(5, av, &a);
	log_lists(a, NULL);
	printf("msd : %d\n", most_significant_digit(a));
}

*/
