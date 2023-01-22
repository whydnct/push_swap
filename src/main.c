/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperez-m <aperez-m@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 12:37:37 by aperez-m          #+#    #+#             */
/*   Updated: 2023/01/22 23:05:41 by aperez-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "push_swap.h"
/* Checks the validity of the arguments*/
/*TODO checkar que todos son int*/
int	arg_checker(char *argv)
{
	int	i;

	i = 0;
	(void)i;
	(void)argv;
	return (1);
}

void	read_list(int argc, char **argv, t_list **stack_a)
{
	int	content;

	while (argc-- > 0)
	{
		content = ft_atoi(argv[argc]);
		if (arg_checker(argv[argc]))
			ft_lstadd_back(stack_a, ft_lstnew(&content));
	}	
}

int	main(int argc, char **argv)
{
	t_list	**stack_a;
/*	t_list	**stack_b;
*/
	stack_a = malloc(sizeof(stack_a));
	read_list(argc, argv, stack_a);
/*	push_b(stack_a, stack_b);
	push_swap(stack_a, stack_b);
	printf("%d %d \n", (*(*stack_a)->content), (*(*stack_b)->content));
*/
}
