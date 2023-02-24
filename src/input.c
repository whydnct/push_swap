/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperez-m <aperez-m@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 19:18:30 by aperez-m          #+#    #+#             */
/*   Updated: 2023/02/24 21:20:38 by aperez-m         ###   ########.fr       */
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
	printf("chars_nbr: %u\n", ret - 1);
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
			{
				ft_putstr_fd("Error\n", 2);
				free(bundle->params_str);
				exit(1);
			}
			bundle->params_str[k] = argv[i][j];
			k++;
			j++;
		}
		bundle->params_str[k] = ' ';
		k++;
		i++;
	}
	bundle->params_str[k] = '\0';
	printf("params_str:%s\n", bundle->params_str);
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
	printf("params_nbr:%u\n", bundle->params_nbr);
}

void up_to_params_nbr(t_bundle *bundle)
{
	unsigned int i;
	unsigned int j;
	unsigned int min;
	unsigned int min_j;

	i = 0;
	min_j = 0;
	// ft_print_bundle_contents(bundle);
	while (i < bundle->params_nbr)
	{
		j = 0;
		min = UINT_MAX;
		while (j < bundle->params_nbr)
		{
			if (min > bundle->uint_lst[j] && bundle->uint_lst[j] >= i)
			{
				min = bundle->uint_lst[j];
				min_j = j;
			}
			j++;
		}
		bundle->uint_lst[min_j] = i;
		i++;
	}
	// ft_print_bundle_contents(bundle);
}