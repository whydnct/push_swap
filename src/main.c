/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperez-m <aperez-m@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 12:37:37 by aperez-m          #+#    #+#             */
/*   Updated: 2023/02/08 20:13:16 by aperez-m         ###   ########.fr       */
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
void	read_list(int argc, int *contents, t_list **stack_a)
{
	int		i;

	i = 0;
	while (i < argc - 1)
	{
		ft_lstadd_front(stack_a, ft_lstnew((void *)(contents + i)));
		i++;
		printf("*content:\t%d\n", *(int *)((**stack_a).content));
		printf("content: \t%p\n", (**stack_a).content);
		printf("next:    \t%p\n", (**stack_a).next);
		printf("&element: \t%p\n", &(**stack_a));
		printf("&content:\t%p\n", &(**stack_a).content);
		printf("&next:   \t%p\n\n", &(**stack_a).next);
	}
}

void	ft_del(void *content)
{
	printf("entering ft_del with address %p\n", content);

//	free(content);
//	*(int*)content = 0;
	content = NULL;
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
	int		*contents;
	int		i;

	//check_argv(argv);
	contents = malloc(sizeof(int)*(argc-1));
	i = 0;
	while(++i < argc)
		contents[i - 1] = ft_atoi(argv[i]);
	stack_a = malloc(sizeof(t_list **));
	read_list(argc, contents, stack_a);
//	push_b(stack_a, stack_b);
//	push_swap(stack_a, stack_b);
//	printf("%d\n",*(int *)(**stack_a).content);
//	ft_lstiter(*stack_a, &ft_print_list);
	printf("clearing memory\n");
	ft_lstclear(stack_a, &ft_del);
	free(contents);
}
