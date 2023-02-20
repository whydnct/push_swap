/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperez-m <aperez-m@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 12:37:37 by aperez-m          #+#    #+#             */
/*   Updated: 2023/02/20 20:54:19 by aperez-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "push_swap.h"

int	get_argc(char const *s, char c)
{
	int	i;
	int	w_nbr;

	i = 0;
	w_nbr = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i] != c && s[i])
			w_nbr++;
		while (s[i] != c && s[i])
			i++;
	}
	return (w_nbr);
}

void fill_stack_a(t_bundle *bundle)
{
	unsigned int i;

	i = 0;
	while (i < bundle->size)
	{
		ft_lstadd_back(&bundle->stack_a, ft_lstnew(bundle->contents + i));
		i++;
	}
}

/*do not free, i haven't malloc'ed*/
void ft_del(void *content)
{
	*(unsigned int *)content = 0;
}

void	normalize2(t_bundle	*bundle)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	min;
	unsigned int	min_j;

	i = 0;
	min_j = 0;
	//ft_print_bundle_contents(bundle);
	while (i < bundle->size)
	{
		j = 0;
		min = UINT_MAX;
		while (j < bundle->size)
		{
			if (min > bundle->contents[j] && bundle->contents[j] >= i)
			{
				min = bundle->contents[j]; 
				min_j = j;
			}
			j++;
		}
		bundle->contents[min_j] = i;
		i++;
	}
	//ft_print_bundle_contents(bundle);
}

void normalize(t_bundle *bundle)
{
	unsigned int i;
	unsigned int j;
	unsigned int previous;
	int flag;

	//ft_print_bundle_contents(bundle);
	i = 0;
	j = 0;
	flag = 1;
	while (flag == 1)
	{
		flag = 0;
		i = 0;
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
			//ft_print_bundle_contents(bundle);
			j = 0;
			i++;
		}
	}
	//ft_print_bundle_contents(bundle);
}

void check_ordered(t_bundle *bundle)
{
	unsigned int i;

	i = 0;
	while (i < bundle->size - 1)
	{
		if (bundle->contents[i] > bundle->contents[i + 1])
			return;
		i++;
	}
	if (i == bundle->size - 1)
	{
		// ft_putstr_fd("Nothing to do, it's already ordered.\n", 1);
		free(bundle->contents);
		exit(0);
	}
}

/*stack_a = malloc(sizeof(t_list *)); si aloco stack_a
ft_lstaddback entra en el if, dejando un primer elemento
de la lista vacío de contenido, no debo alocar, ni lo necesito
*/
int main(int argc, char **argv)
{
	t_bundle bundle;

	if (argc < 2)
		return (0);
	if (argc == 2)
	{
		argc = get_argc(argv[1], ' ') + 1;
		argv = ft_split(ft_strjoin(ft_strjoin(argv[0], " "), argv[1]), ' ');
	}
	bundle.contents = malloc(sizeof(unsigned int) * (argc - 1));
	if (!bundle.contents)
		exit(1);
	check_argv(argc, argv, &bundle);
	check_ordered(&bundle);
	normalize2(&bundle);
	fill_stack_a(&bundle);
	//ft_print_bundle(bundle);
	radix_all_positions(&bundle);
	//ft_print_bundle(bundle);
	// printf("%d moves\n", bundle.moves);
	// ft_lstiter(bundle.stack_a, &ft_print_list);
	ft_lstclear(&bundle.stack_a, &ft_del);
	ft_lstclear(&bundle.stack_b, &ft_del);
	// printf("memory cleared.\n");
	free(bundle.contents);
	free(argv);
}
