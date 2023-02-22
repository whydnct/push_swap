/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperez-m <aperez-m@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 12:37:37 by aperez-m          #+#    #+#             */
/*   Updated: 2023/02/22 22:18:29 by aperez-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "push_swap.h"


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

void up_to_params_nbr(t_bundle *bundle)
{
	unsigned int i;
	unsigned int j;
	unsigned int min;
	unsigned int min_j;

	i = 0;
	min_j = 0;
	// ft_print_bundle_contents(bundle);
	while (i < bundle->params_nbr)
	{
		j = 0;
		min = UINT_MAX;
		while (j < bundle->params_nbr)
		{
			if (min > bundle->uint_lst[j] && bundle->uint_lst[j] >= i)
			{
				min = bundle->uint_lst[j];
				min_j = j;
			}
			j++;
		}
		bundle->uint_lst[min_j] = i;
		i++;
	}
	// ft_print_bundle_contents(bundle);
}

void normalize(t_bundle *bundle)
{
	unsigned int i;
	unsigned int j;
	unsigned int previous;
	int flag;

	// ft_print_bundle_contents(bundle);
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
			// ft_print_bundle_contents(bundle);
			j = 0;
			i++;
		}
	}
	// ft_print_bundle_contents(bundle);
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
	t_bundle		bundle;
	unsigned int	chars_nbr;

	chars_nbr = 0;
	get_chars_nbr(argc, argv, &chars_nbr);
	if(chars_nbr)
	{
		bundle.params_str = malloc(sizeof(char)*chars_nbr);
		if (!bundle.params_str)
			exit(1);
		get_params_str(argc, argv, &bundle);
		get_params_nbr(&bundle, ' ');
		bundle.params_str_lst = ft_split(bundle.params_str, ' ');
		bundle.contents = malloc(sizeof(unsigned int) * (bundle.params_nbr));
		if (!bundle.contents)
			exit(1);
		get_uint_lst(&bundle);
		down_to_zero(&bundle);
		check_ordered(&bundle);
		up_to_params_nbr(&bundle);
		fill_stack_a(&bundle);
		// ft_print_bundle(bundle);
		radix_all_positions(&bundle);
		// ft_print_bundle(bundle);
		//  printf("%d moves\n", bundle.moves);
		//  ft_lstiter(bundle.stack_a, &ft_print_list);
		ft_lstclear(&bundle.stack_a, &ft_del);
		ft_lstclear(&bundle.stack_b, &ft_del);
		// printf("memory cleared.\n");
		free(bundle.contents);
		free(bundle.params_str);
	}
}

void	get_chars_nbr(int argc, char **argv, unsigned int *chars_nbr)
{
	int				i;
	int				j;

	i = 1;
	while (i < argc - 1)
	{
		j = 0;
		while (argv[i][j])
		{
			(*chars_nbr)++;
			j++;
		}
		i++;
	}
	*chars_nbr++;
	printf("chars_nbr: %u\n", *chars_nbr - 1);
}

void get_params_str(int argc, char **argv, t_bundle *bundle)
{
	int i;
	int k;
	int j;

	i = 1;
	k = 0;
	while (i < argc - 1)
	{
		j = 0;
		while (argv[i][j])
		{
			if (!valid_chars(argv[i][j]))
			{
				ft_putstr_fd("Error\n", 2);
				free(bundle->params_str);
				exit(1);
			}
			bundle->params_str[k] = argv[i][j];
			k++;
			j++;
		}
		i++;
	}
	bundle->params_str[k] = '\0';
}

void get_params_nbr(t_bundle *bundle, char c)
{
	int i;

	i = 0;
	bundle->params_nbr = 0;
	while (bundle->params_str[i])
	{
		while (bundle->params_str[i] == c)
			i++;
		if (bundle->params_str[i] != c && bundle->params_str[i])
			bundle->params_nbr++;
		while (bundle->params_str[i] != c && bundle->params_str[i])
			i++;
	}
}

int	valid_chars(char c)
{
	if(ft_isdigit(c))
		return (1);
	if (c == ' ')
		return (2);
	if (c == '-' || c == '+')
		return (3);
	return (0);
}

void	get_uint_lst(t_bundle *bundle)
{
	int	i;

	i = -1;
	while (++i < bundle->params_nbr)
		bundle->uint_lst[i] = atoi_unsigned(bundle, i);

}