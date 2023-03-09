/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperez-m <aperez-m@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 06:37:33 by aperez-m          #+#    #+#             */
/*   Updated: 2023/03/09 17:46:36 by aperez-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int	get_max_iters(t_bundle bundle)
{
	int	counter;

	counter = 0;
	while (bundle.params_nbr > 0)
	{
		bundle.params_nbr >>= 1;
		counter++;
	}
	return (counter);
}

void	radix_one_position(t_bundle *bundle, int i)
{
	t_list			*first_rotated;
	unsigned int	size_b;

	first_rotated = NULL;
	while (bundle->stack_a != first_rotated && bundle->stack_a->next)
	{	
		if (((*(int *)bundle->stack_a->content >> i) & 1) == 0)
			push_b(bundle);
		else if (bundle->stack_a->next)
		{
			if (first_rotated == NULL)
				first_rotated = bundle->stack_a;
			rotate_a(bundle);
		}
	}
	size_b = ft_lstsize(bundle->stack_b);
	while (size_b)
	{
		if (i < bundle->max_iters - 1
			&& ((*(int *)bundle->stack_b->content >> (i + 1)) & 1) == 0)
			rotate_b(bundle);
		else
			push_a(bundle);
		size_b--;
	}
}

void	radix_all_positions(t_bundle *bundle)
{
	int	i;

	i = 0;
	bundle->max_iters = get_max_iters(*bundle);
	while (i < bundle->max_iters)
	{
		radix_one_position(bundle, i);
		i++;
	}
}
