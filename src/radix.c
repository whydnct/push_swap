/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperez-m <aperez-m@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 06:37:33 by aperez-m          #+#    #+#             */
/*   Updated: 2023/02/18 10:39:20 by aperez-m         ###   ########.fr       */
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

void	sort(t_bundle *bundle)
{
	int	i;
	int	max_iters;

	i = 0;
	max_iters = get_max_iters(*bundle);
	while (i < max_iters)
	{
		ft_lstiter(bundle->stack_a, &execute_if_0(&push))
		i++;
	}
}