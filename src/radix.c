/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperez-m <aperez-m@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 06:37:33 by aperez-m          #+#    #+#             */
/*   Updated: 2023/02/25 21:51:35 by aperez-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int	get_max_iters(t_bundle bundle)
{
	int counter;
	
	counter = 0;
	while (bundle.params_nbr > 0)
	{
		bundle.params_nbr>>=1;
		//printf("bundle.params_nbr:%u\n", bundle.params_nbr);
		counter++;
	}
	//printf("max iters:%d\n", counter);
	return (counter);
}

void	radix_one_position(t_bundle *bundle, int i)
{
	int		first_rotation;
	t_list	*first_rotated;


	first_rotation = 0;
	first_rotated = NULL;
	while (bundle->stack_a != first_rotated && bundle->stack_a->next)
	{	
		if (((*(int *)bundle->stack_a->content >> i)&1) == 0)
			push_b(bundle);
		else
		{
			if (bundle->stack_a->next)
			{
				if (first_rotation == 0)
				{
					first_rotated = bundle->stack_a;
					first_rotation = 1;
				}
				rotate_a(bundle);
			}
		}
	}
	while (bundle->stack_b)
	{
		//ft_print_bundle(*bundle);
		//ft_print_list(bundle->stack_b);
		push_a(bundle);
	}
	printf("finished sending them back to a\n");
}

void	radix_all_positions(t_bundle *bundle)
{
	int	i;
	int	max_iters;

	i = 0;
	max_iters = get_max_iters(*bundle);
	printf("max iters: %d\n", max_iters);
	while (i < max_iters)
	{
		radix_one_position(bundle, i);
		printf("%dº position rotated\n", i);
		i++;
	}
	//printf("exit radix all positions\n");
}