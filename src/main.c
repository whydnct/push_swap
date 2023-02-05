/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperez-m <aperez-m@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 12:37:37 by aperez-m          #+#    #+#             */
/*   Updated: 2023/02/05 21:09:44 by aperez-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "push_swap.h"
/* Checks the validity of the arguments*/
/*TODO checkar que todos son int*/
/*
int	check_argv(char **argv)
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
	while (i < argc)
	{
		content = ft_atoi(argv[i]);
		new = ft_lstnew(&content);
		printf("%p\n", new->next);
		ft_lstadd_front(stack_a, new);
		i++;
		printf("%d\n", *(int *)((**stack_a).content));
		//printf("%p\n", ft_lstlast(*stack_a)->next);
	}
}

void	ft_del(void *content)
{
	free(content);
}

void	ft_print_list(void *stack_a_el)
{
	printf("%d \n", *(int *)stack_a_el);
	printf("%p \n", (stack_a_el+4));
}

int	main(int argc, char **argv)
{
	t_list	**stack_a;
	//t_list	**stack_b;

	//check_argv(argv);
	stack_a = malloc(sizeof(t_list **));
	read_list(argc, argv, stack_a);
//	push_b(stack_a, stack_b);
//	push_swap(stack_a, stack_b);
	ft_lstiter(*stack_a, &ft_print_list);
	ft_lstclear(stack_a, &ft_del);
}
