/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperez-m <aperez-m@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 06:37:33 by aperez-m          #+#    #+#             */
/*   Updated: 2023/02/18 20:51:40 by aperez-m         ###   ########.fr       */
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

void	radix_one_pos(t_bundle *bundle, int i)
{
	int		first_rotation;
	t_list	*first_rotated;


	while (bundle->stack_a != first_rotated)
	{	
		if (*(int *)(bundle)->stack_a->content >> i == 0)
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
	int	first_rotation;
	t_list	*first_rotated;

	i = 0;
	first_rotation = 0;
	first_rotated = NULL;
	max_iters = get_max_iters(*bundle);
	while (i < max_iters)
	{
		radix_one_position(bundle, i);
		i++;
	}
}