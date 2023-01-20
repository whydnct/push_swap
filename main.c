/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperez-m <aperez-m@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 12:37:37 by aperez-m          #+#    #+#             */
/*   Updated: 2023/01/20 19:15:55 by aperez-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
/* Checks the validity of the arguments*/
/*TODO checkar que todos son int*/
int	arg_checker(char **argv)
{
	int	i;

	i = 0;
	return (1);
}

void	*read_list(int argc, char **argv, int **stack_a)
{
	while (argc-- > 0)
	{
		if (arg_checker(argv[argc]))
			ft_lstadd_back(stack_a, ft_lstnew(ft_atoi(argv[argc])));
	}	
}

int	main(int argc, char **argv)
{
	t_list	**stack_a;
	t_list	**stack_b;

	if (read_list(argc, argv, stack_a))
		return (-1);
	push_b(stack_a, stack_b);
	/* push_swap(stack_a, stack_b);*/
	printf("%d %d \n", (*stack_a)->content, (*stack_b)->content);
}
