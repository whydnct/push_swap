/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperez-m <aperez-m@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 12:37:37 by aperez-m          #+#    #+#             */
/*   Updated: 2023/03/06 12:38:28 by aperez-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_stacks(t_bundle *bundle)
{
	bundle->stack_a = NULL;
	bundle->stack_b = NULL;
	fill_stack_a(bundle);
}

void	init_params(t_bundle *bundle)
{
	get_uint_lst(bundle);
	down_to_zero(bundle);
	check_ordered(bundle);
	up_to_params_nbr(bundle);
}

void	free_on_success(t_bundle *bundle)
{
	ft_lstclear(&bundle->stack_a, &ft_del);
	ft_lstclear(&bundle->stack_b, &ft_del);
	free_all(bundle);
}

int	main(int argc, char **argv)
{
	t_bundle		bundle;
	unsigned int	chars_nbr;

	if (argc < 2)
		return (0);
	chars_nbr = get_chars_nbr(argc, argv);
	if (chars_nbr != 1)
	{
		bundle.params_str = malloc(sizeof(char) * (chars_nbr + 1));
		if (!bundle.params_str)
			exit(1);
		get_params_str(argc, argv, &bundle);
		get_params_nbr(&bundle, ' ');
		bundle.params_str_lst = ft_split(bundle.params_str, ' ');
		bundle.uint_lst = malloc(sizeof(unsigned int) * (bundle.params_nbr));
		if (!bundle.uint_lst)
			exit(1);
		init_params(&bundle);
		init_stacks(&bundle);
		if (bundle.params_nbr > 5)
			radix_all_positions(&bundle);
		else
			sort_5(&bundle);
		free_on_success(&bundle);
	}
}
