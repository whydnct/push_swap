/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperez-m <aperez-m@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 12:37:37 by aperez-m          #+#    #+#             */
/*   Updated: 2023/02/17 18:52:40 by aperez-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "push_swap.h"

void	read_list(int argc, t_bundle *bundle)
{
	int		i;

	i = 0;
	while (i < argc - 1)
	{
		ft_lstadd_back(&bundle->stack_a, ft_lstnew(bundle->contents + i));
		i++;
	}
}

/*do not free, i haven't malloc'ed*/
void	ft_del(void *content)
{
	*(unsigned int*)content = 0;
}

void	ft_print_list(void *stack_a_el)
{
	printf("content: %u \n", *(unsigned int *)stack_a_el);
	printf("address: %p \n", stack_a_el);
}

/*stack_a = malloc(sizeof(t_list *)); si aloco stack_a
ft_lstaddback entra en el if, dejando un primer elemento
de la lista vacío de contenido, no debo alocar, ni lo necesito
*/
int	main(int argc, char **argv)
{
	//t_list					*stack_a;
	//t_list					*stack_b;
	t_bundle	bundle;

	bundle.contents = malloc(sizeof(unsigned int) * (argc - 1));
	if (!bundle.contents)
		exit(1);
	check_argv(argc, argv, &bundle);
	read_list(argc, &bundle);
//	push_b(stack_a, stack_b);
//	push_swap(stack_a, stack_b);
	ft_lstiter(bundle.stack_a, &ft_print_list);
	printf("clearing memory\n");
	ft_lstclear(&bundle.stack_a, &ft_del);
	free(bundle.contents);
}
