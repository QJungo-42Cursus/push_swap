/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qjungo <qjungo@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 21:42:46 by qjungo            #+#    #+#             */
/*   Updated: 2022/08/13 21:53:51 by qjungo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdio.h>
#include<unistd.h>
#include<string.h>
#include<stdlib.h>

#include"libft/libft.h"
#include"push_swap.h"

void	init_stack_a(int argc, char **argv, t_list **stack_a)
{
	short	i;
	int	*numbers;

	numbers = malloc(sizeof(int) * argc);
	numbers[0] = atoi(argv[0]);	
	*stack_a = ft_lstnew(&numbers[0]);
	i = 1;
	while (i < argc)
	{
		numbers[i] = atoi(argv[i]);
		ft_lstadd_back(stack_a, ft_lstnew(&numbers[i]));
		i++;
	}
}

int main(int argc, char **argv)
{
	short	i;
	t_list	*stack_a;
	
	argc--;
	argv++;
	if (argc == 0)
	{
		ft_putendl_fd("Error\n (not enought argc)", 1);
		return (0);
	}
	i = 0;
	while (i < argc)
	{
		// TODO : check si ce n'est pas un int (string / long / ...)
		i++;
	}
	stack_a = NULL;
	init_stack_a(argc, argv, &stack_a);
	push_swap(&stack_a);
}
