/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperez-m <aperez-m@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 12:37:37 by aperez-m          #+#    #+#             */
/*   Updated: 2023/03/05 11:45:19 by aperez-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "push_swap.h"

int main(int argc, char **argv)
{
	t_bundle		bundle;
	unsigned int	chars_nbr;

	chars_nbr = get_chars_nbr(argc, argv);
	if(chars_nbr != 1)
	{
		bundle.params_str = malloc(sizeof(char)*(chars_nbr + 1));
		if (!bundle.params_str)
			exit(1);
		get_params_str(argc, argv, &bundle);
		get_params_nbr(&bundle, ' ');
		bundle.params_str_lst = ft_split(bundle.params_str, ' ');
		//printf_params_str_lst(&bundle);
		bundle.uint_lst = malloc(sizeof(unsigned int) * (bundle.params_nbr));
		if (!bundle.uint_lst)
			exit(1);
		get_uint_lst(&bundle);
		//printf_uint_lst(&bundle);	
		down_to_zero(&bundle);
		//printf_uint_lst(&bundle);	
		check_ordered(&bundle);
		up_to_params_nbr(&bundle);
		//printf_uint_lst(&bundle);
		fill_stack_a(&bundle);
		//ft_print_list(bundle.stack_a);
		// ft_print_bundle(bundle);
		if (bundle.params_nbr > 5)
			radix_all_positions(&bundle);
		else
			sort_5(&bundle);
		//ft_print_bundle(bundle);
		//ft_print_bundle_contents(&bundle);
		//printf("%d moves\n", bundle.moves);
		//  ft_lstiter(bundle.stack_a, &ft_print_list);
		//ft_print_bundle(bundle);
		ft_lstclear(&bundle.stack_a, &ft_del);
		ft_lstclear(&bundle.stack_b, &ft_del);
		free_all(&bundle);
	}
}