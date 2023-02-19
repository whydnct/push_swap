/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperez-m <aperez-m@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 12:37:37 by aperez-m          #+#    #+#             */
/*   Updated: 2023/02/19 09:25:42 by aperez-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "push_swap.h"

void	fill_stack_a(t_bundle *bundle)
{
	unsigned int		i;

	i = 0;
	while (i < bundle->size)
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
	printf("content: %u @ %p\n", *(unsigned int *)stack_a_el, stack_a_el);
}

void ft_print_bundle(t_bundle bundle)
{
	int	size_a;
	int	size_b;
	int	i;

	i = 0;
	size_a = ft_lstsize(bundle.stack_a);
	size_b = ft_lstsize(bundle.stack_b);

	if (size_a > size_b)
	{
		while (i < size_a - size_b)
		{
			printf("%u @ %p \n", *(unsigned int*)bundle.stack_a->content, bundle.stack_a);
			bundle.stack_a = bundle.stack_a->next;
			i++;
		}
		while (i < size_a)
		{
			printf("%u @ %p \t\t\t %u @ %p \n", *(unsigned int*)bundle.stack_a->content, bundle.stack_a, *(unsigned int*)bundle.stack_b->content, bundle.stack_b);
			bundle.stack_b = bundle.stack_b->next;
			bundle.stack_a = bundle.stack_a->next;
			i++;
		}
	}
	else
	{
		while (i < size_b - size_a)
		{
			printf("               \t\t\t %u @ %p \n", *(unsigned int*)bundle.stack_b->content, bundle.stack_b);
			bundle.stack_b = bundle.stack_b->next;
			i++;
		}
		while (i < size_b)
		{
			printf("%u @ %p \t\t\t %u @ %p \n", *(unsigned int*)bundle.stack_a->content, bundle.stack_a, *(unsigned int*)bundle.stack_b->content, bundle.stack_b);
			bundle.stack_b = bundle.stack_b->next;
			bundle.stack_a = bundle.stack_a->next;
			i++;
		}
	}
	printf("---------------a\t\t----------------b\n");

}

void	normalize(t_bundle *bundle)
{
	unsigned int	i;
	unsigned int 	j;
	unsigned int	previous;
	int				flag;

	i = 0;
	j = 0;
	flag = 1;
	while (flag == 1)
	{
		flag = 0;
		while (i < bundle->size)
		{
			previous = 0;
			while (j < bundle->size)
			{
				if (bundle->contents[j] < bundle->contents[i] && bundle->contents[j] > previous)
					previous = bundle->contents[j];
				j++;
			}
			if (bundle->contents[i] > previous + 1)
			{
				bundle->contents[i] = previous + 1;
				flag = 1;
			}
			j = 0;
			i++;
		}
	}
}

void	check_ordered(t_bundle *bundle)
{
	unsigned int	i;

	i = 1;
	while (i < bundle->size - 1)
	{
		if (bundle->contents[i - 1] > bundle->contents[i] || bundle->contents[i] > bundle->contents[i + 1])
			return;
		i++;
	}
	if (i == bundle->size - 1)
	{
		ft_putstr_fd("Nothing to do, it's already ordered.\n", 1);
		free(bundle->contents);
		exit(0);
	}
}

/*stack_a = malloc(sizeof(t_list *)); si aloco stack_a
ft_lstaddback entra en el if, dejando un primer elemento
de la lista vacío de contenido, no debo alocar, ni lo necesito
*/
int	main(int argc, char **argv)
{
	t_bundle	bundle;

	bundle.contents = malloc(sizeof(unsigned int) * (argc - 1));
	if (!bundle.contents)
		exit(1);
	check_argv(argc, argv, &bundle);
	check_ordered(&bundle);
	normalize(&bundle);
	fill_stack_a(&bundle);
	ft_print_bundle(bundle);
	radix_all_positions(&bundle);
	ft_print_bundle(bundle);
	//ft_lstiter(bundle.stack_a, &ft_print_list);
	ft_lstclear(&bundle.stack_a, &ft_del);
	printf("memory cleared.\n");
	free(bundle.contents);
}
