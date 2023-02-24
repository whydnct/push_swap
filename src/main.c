/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperez-m <aperez-m@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 12:37:37 by aperez-m          #+#    #+#             */
/*   Updated: 2023/02/24 21:18:00 by aperez-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "push_swap.h"


void fill_stack_a(t_bundle *bundle)
{
	unsigned int i;

	i = 0;
	while (i < bundle->params_nbr)
	{
		ft_lstadd_back(&bundle->stack_a, ft_lstnew(&bundle->uint_lst[i]));
		printf("%u added to stack_a\n", bundle->uint_lst[i]);
		i++;
	}
	printf("exited the while on fill_stack_a\n");
}

/*do not free, i haven't malloc'ed*/
void ft_del(void *content)
{
	*(unsigned int *)content = 0;
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
		while (i < bundle->params_nbr)
		{
			previous = 0;
			while (j < bundle->params_nbr)
			{
				if (bundle->uint_lst[j] < bundle->uint_lst[i] && bundle->uint_lst[j] > previous)
					previous = bundle->uint_lst[j];
				j++;
			}
			if (bundle->uint_lst[i] > previous + 1)
			{
				bundle->uint_lst[i] = previous + 1;
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
	while (i < bundle->params_nbr - 1)
	{
		if (bundle->uint_lst[i] > bundle->uint_lst[i + 1])
			return;
		i++;
	}
	if (i == bundle->params_nbr - 1)
	{
		// ft_putstr_fd("Nothing to do, it's already ordered.\n", 1);
		free(bundle->uint_lst);
		exit(0);
	}
printf("---they're not ordered---\n");
}

/*stack_a = malloc(sizeof(t_list *)); si aloco stack_a
ft_lstaddback entra en el if, dejando un primer elemento
de la lista vacío de contenido, no debo alocar, ni lo necesito
*/

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
	unsigned int	i;

	i = -1;
	while (++i < bundle->params_nbr)
		bundle->uint_lst[i] = atoi_unsigned(bundle, i);

}

int main(int argc, char **argv)
{
	t_bundle		bundle;
	unsigned int	chars_nbr;

	chars_nbr = get_chars_nbr(argc, argv);
	if(chars_nbr != 1)
	{
		bundle.params_str = malloc(sizeof(char)*chars_nbr);
		if (!bundle.params_str)
			exit(1);
		get_params_str(argc, argv, &bundle);
		get_params_nbr(&bundle, ' ');
		bundle.params_str_lst = ft_split(bundle.params_str, ' ');
		printf_params_str_lst(&bundle);
		bundle.uint_lst = malloc(sizeof(unsigned int) * (bundle.params_nbr));
		if (!bundle.uint_lst)
			exit(1);
		get_uint_lst(&bundle);
		printf_uint_lst(&bundle);	
		down_to_zero(&bundle);
		printf_uint_lst(&bundle);	
		check_ordered(&bundle);
		up_to_params_nbr(&bundle);
		printf_uint_lst(&bundle);
		fill_stack_a(&bundle);
		ft_print_list(bundle.stack_a);
		// ft_print_bundle(bundle);
		radix_all_positions(&bundle);
		ft_print_bundle(bundle);
		//  printf("%d moves\n", bundle.moves);
		//  ft_lstiter(bundle.stack_a, &ft_print_list);
		ft_lstclear(&bundle.stack_a, &ft_del);
		ft_lstclear(&bundle.stack_b, &ft_del);
		// printf("memory cleared.\n");
		free(bundle.uint_lst);
		while (bundle.params_nbr)
		{
			free(bundle.params_str_lst[bundle.params_nbr]);
			bundle.params_nbr--;
		}
		free(bundle.params_str_lst[0]);
		free(bundle.params_str_lst);
		free(bundle.params_str);
	}
}