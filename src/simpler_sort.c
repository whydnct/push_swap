/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simpler_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperez-m <aperez-m@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 21:39:09 by aperez-m          #+#    #+#             */
/*   Updated: 2023/02/25 11:47:46 by aperez-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void sort_3(t_bundle *bundle)
{
	if (*(unsigned int *)bundle->stack_a->content == bundle->params_nbr - 1)
		rotate_a(bundle);
	if (*(unsigned int *)bundle->stack_a->next->content == bundle->params_nbr - 1)
		r_rotate_a(bundle);
	if (*(unsigned int *)bundle->stack_a->content > *(unsigned int *)bundle->stack_a->next->content)
		swap_a(bundle);
}

void	reduce_to_3(t_bundle *bundle)
{
	while (ft_lstsize(bundle->stack_a) > 3)
	{
		if (*(unsigned int *)bundle->stack_a->content < 2)
		{
			push_b(bundle);
			continue;
		}
		if (*(unsigned int *)bundle->stack_a->next->content < 2)
		{
			swap_a(bundle);
			continue;
		}
		if (*(unsigned int *)ft_lstlast(bundle->stack_a)->content < 2)
		{
			r_rotate_a(bundle);
			continue;
		}
		else
			rotate_a(bundle);
	}
}

void	sort_5(t_bundle *bundle)
{
	reduce_to_3(bundle);
	sort_3(bundle);
	if (bundle->params_nbr == 5)
	{
		if(*(unsigned int *)bundle->stack_b->content 
		< *(unsigned int *)bundle->stack_b->next->content)
			swap_b(bundle);
		push_a(bundle);
	}
	push_a(bundle);
}