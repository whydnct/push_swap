/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperez-m <aperez-m@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 12:37:37 by aperez-m          #+#    #+#             */
/*   Updated: 2023/01/31 22:30:56 by aperez-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "push_swap.h"
/* Checks the validity of the arguments*/
/*TODO checkar que todos son int*/
/*
int	arg_checker(char *argv)
{
	int	i;

	i = 0;
	(void)i;
	(void)argv;
	return (1);
}
*/
void	read_list(int argc, char **argv, t_list **stack_a)
{
	int		content;
	int		i;
	t_list	*new;

	i = 1;
	(void)argc;
	//while (i < argc)
	//{
		content = ft_atoi(argv[i]);
		new = ft_lstnew(&content);
		printf("%d\n", (int)new->content);
		//if (arg_checker(argv[i]))
			ft_lstadd_front(stack_a, new);
	printf("%d \n", (*stack_a)->content);
		i++;
	//}	
}

int	main(int argc, char **argv)
{
	t_list	**stack_a;
	//t_list	**stack_b;
	(void)argc;

	stack_a = malloc(sizeof(t_list **));
	read_list(argc, argv, stack_a);
//	push_b(stack_a, stack_b);
//	push_swap(stack_a, stack_b);
	printf("%d \n", (*stack_a)->content);

	free(stack_a);
}
