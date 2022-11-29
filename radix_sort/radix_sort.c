
#include "../libft/libft.h"

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

/*
int	most_significant_digit(t_list **a)
{


	int		number;

	number = 123456;
	dividende = 1;
	digit = 1;


}

void	radix_sort()
{

}
*/


/*
 * TESTS
 */

#include <stdio.h>
int	main()
{
	printf("n_digit of %d = %d\n", 9, n_digit(9));
	printf("n_digit of %d = %d\n", 8437, n_digit(8437));
	printf("n_digit of %d = %d\n", 0, n_digit(0));
	int i = 0;
	while (i != 100000)
	{
		printf("n_digit of %d = %d\n", 123456789, n_digit(123456789));
		i++;
	}


}
