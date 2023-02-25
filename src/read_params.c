/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_params.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperez-m <aperez-m@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 12:18:07 by aperez-m          #+#    #+#             */
/*   Updated: 2023/02/25 13:26:30 by aperez-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

unsigned int	get_chars_nbr(int argc, char **argv)
{
	int				i;
	int				j;
	unsigned int	ret;

	i = 1;
	ret = 0;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j])
		{
			ret++;
			j++;
		}
		if (i < argc - 1)
			ret++;
		i++;
	}
	ret++;
	//printf("chars_nbr: %u\n", ret - 1);
	return (ret);
}

void get_params_str(int argc, char **argv, t_bundle *bundle)
{
	int i;
	int k;
	int j;

	i = 1;
	k = 0;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j])
		{
			if (!valid_chars(argv[i][j]))
				error(bundle, 1);
			bundle->params_str[k] = argv[i][j];
			k++;
			j++;
		}
		bundle->params_str[k] = ' ';
		k++;
		i++;
	}
	bundle->params_str[k] = '\0';
	//printf("params_str:%s\n", bundle->params_str);
}

void get_params_nbr(t_bundle *bundle, char c)
{
	int i;

	i = 0;
	bundle->params_nbr = 0;
	while (bundle->params_str[i])
	{
		while (bundle->params_str[i] == c)
			i++;
		if (bundle->params_str[i] != c && bundle->params_str[i])
			bundle->params_nbr++;
		while (bundle->params_str[i] != c && bundle->params_str[i])
			i++;
	}
	//printf("params_nbr:%u\n", bundle->params_nbr);
}

void	get_uint_lst(t_bundle *bundle)
{
	unsigned int	i;

	i = -1;
	while (++i < bundle->params_nbr)
		bundle->uint_lst[i] = atoi_unsigned(bundle, i);
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
		error(bundle, 4);
	//printf("%u added to uint_lst\n", (unsigned int)(INT_MIN_ABS + sign*res));
	return (INT_MIN_ABS + sign * res);
}
