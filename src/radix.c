/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperez-m <aperez-m@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 06:37:33 by aperez-m          #+#    #+#             */
/*   Updated: 2023/02/18 21:23:57 by aperez-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int	get_max_iters(t_bundle bundle)
{
	int counter;
	
	counter = 0;
	while (bundle.size > 0)
	{
		bundle.size>>=1;
		counter++;
	}
	printf("max iters:%d\n", counter);
	return (counter);
}

void	radix_one_position(t_bundle *bundle, int i)
{
	int		first_rotation;
	t_list	*first_rotated;


	first_rotation = 0;
	first_rotated = NULL;
	while (bundle->stack_a != first_rotated)
	{	
		if (((*(int *)(bundle)->stack_a->content >> i)&1) == 0)
			push_b(bundle);
		else
		{
			rotate_a(bundle);
			if (first_rotation == 0)
			{
				first_rotated = (bundle)->stack_a;
				first_rotation = 1;
			}
		}
	}
	while (bundle->stack_b)
		push_a(bundle);
}

void	radix_all_positions(t_bundle *bundle)
{
	int	i;
	int	max_iters;

	i = 0;
	max_iters = get_max_iters(*bundle);
	while (i < max_iters)
	{
		radix_one_position(bundle, i);
		ft_lstiter(bundle->stack_a, &ft_print_list);
		ft_putstr_fd("----a\n",1);
		ft_lstiter(bundle->stack_b, &ft_print_list);
		ft_putstr_fd("----b\n",1);
		i++;
	}
}