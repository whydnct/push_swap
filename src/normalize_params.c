/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normalize_params.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperez-m <aperez-m@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 19:18:30 by aperez-m          #+#    #+#             */
/*   Updated: 2023/03/05 20:56:18 by aperez-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	up_to_params_nbr(t_bundle *bundle)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	min;
	unsigned int	min_j;

	i = 0;
	min_j = 0;
	while (i < bundle->params_nbr)
	{
		j = 0;
		min = UINT_MAX;
		while (j < bundle->params_nbr)
		{
			if (min >= bundle->uint_lst[j] && bundle->uint_lst[j] >= i)
			{
				min = bundle->uint_lst[j];
				min_j = j;
			}
			j++;
		}
		bundle->uint_lst[min_j] = i;
		i++;
	}
}

void	down_to_zero(t_bundle *bundle)
{
	unsigned int	i;
	unsigned int	min;

	i = -1;
	min = UINT_MAX;
	while (++i < bundle->params_nbr)
	{
		check_duplicate(i, bundle);
		if (bundle->uint_lst[i] < min)
			min = bundle->uint_lst[i];
	}
	i++;
	while (--i >= 1)
		bundle->uint_lst[i - 1] -= min;
}

void	fill_stack_a(t_bundle *bundle)
{
	unsigned int	i;

	i = 0;
	while (i < bundle->params_nbr)
	{
		ft_lstadd_back(&bundle->stack_a, ft_lstnew(&bundle->uint_lst[i]));
		i++;
	}
}
