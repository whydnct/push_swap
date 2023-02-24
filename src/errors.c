/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperez-m <aperez-m@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 12:37:37 by aperez-m          #+#    #+#             */
/*   Updated: 2023/02/24 20:27:15 by aperez-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	error(t_bundle *bundle, int type_error)
{
	if (type_error == 1)
		ft_putstr_fd("Error"/*, parametre too long."*/"\n", 2);
	else if (type_error == 2)
		ft_putstr_fd("Error"/*, parametre is not a number."*/"\n", 2);
	else if (type_error == 3)
		ft_putstr_fd("Error"/*, parametre out of bounds."*/"\n", 2);
	else if (type_error == 4)
		ft_putstr_fd("Error"/*, repeated parametre too long."*/"\n", 2);
	free(bundle->uint_lst);
	exit(1);
}

unsigned int	atoi_unsigned(t_bundle *bundle, unsigned int i)
{
	int				sign;
	long			res;
	int				j;

	sign = 1;
	res = 0;
	j = 0;
	if (valid_chars(bundle->params_str_lst[i][j]) == 3)
	{
		if (bundle->params_str_lst[i][j] == '-')
			sign = -1;
		j++;
	}	
	if (!ft_isdigit(bundle->params_str_lst[i][j]))
		error(bundle, 2);
	while (ft_isdigit(bundle->params_str_lst[i][j]))
	{
		res = res * 10 + bundle->params_str_lst[i][j] - '0';
		j++;
	}
	if (bundle->params_str_lst[i][j])
		error(bundle, 2);
	if (sign * res < INT_MIN || INT_MAX < sign * res)
		error(bundle, 3);
	printf("%u added to uint_lst\n", (unsigned int)(INT_MIN_ABS + sign*res));
	return (INT_MIN_ABS + sign * res);
}

void	check_duplicate(int i, t_bundle *bundle)
{
	int	j;

	j = 0;
	while (j < i)
	{
		if (bundle->uint_lst[j] == bundle->uint_lst[i])
			error(bundle, 4);
		j++;
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
