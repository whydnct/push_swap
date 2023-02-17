/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperez-m <aperez-m@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 12:37:37 by aperez-m          #+#    #+#             */
/*   Updated: 2023/02/17 22:13:25 by aperez-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error(t_bundle *bundle, int type_error)
{
	if (type_error == 1)
		ft_putstr_fd("Error, parametre too long.\n", 2);
	else if (type_error == 2)
		ft_putstr_fd("Error, parametre is not a number.\n", 2);
	else if (type_error == 3)
		ft_putstr_fd("Error, parametre out of bounds.\n", 2);
	else if (type_error == 4)
		ft_putstr_fd("Error, repeated parametre.\n", 2);
	free(bundle->contents);
	exit(1);
}

unsigned int	check_bounds(char *number, t_bundle *bundle)
{
	int			sign;
	long		res;

	sign = 1;
	res = 0;
	if (*number == '-' || *number == '+')
	{
		if (*number == '-')
			sign = -1;
		number++;
	}	
	else if (!ft_isdigit(*number))
		error(bundle, 2);
	while (*number >= '0' && *number <= '9')
	{
		res = res * 10 + *number - '0';
		number++;
	}
	if (*number)
		error(bundle, 2);
	if (sign * res < -2147483648 || 2147483647 < sign * res)
		error(bundle, 3);
	return ((unsigned int)(-2147483648 + sign * res));
}

void	check_length(char *number, t_bundle *bundle)
{
	if (ft_strlen(number) > 11)
		error(bundle, 1);
}

void	check_duplicate(int i, t_bundle *bundle, unsigned int dummy)
{
	int	j;

	j = 0;
	while (j < i - 1)
	{
		if (bundle->contents[j] == dummy)
			error(bundle, 4);
		j++;
	}
}

void	check_argv(int argc, char **argv, t_bundle *bundle)
{
	int				i;
	unsigned int	dummy;

	i = 0;
	bundle->bounds[0] = 4294967295;
	while (++i < argc)
	{
		check_length(argv[i], bundle);
		dummy = check_bounds(argv[i], bundle);
		check_duplicate(i, bundle, dummy);
		bundle->contents[i - 1] = dummy;
		if (dummy < bundle->bounds[0])
			bundle->bounds[0] = dummy;
	}
	while (--i >= 1)
	{
		bundle->contents[i - 1] -= bundle->bounds[0];
		if (bundle->contents[i - 1] > bundle->bounds[1])
			bundle->bounds[1] = bundle->contents[i - 1];
	}
	bundle->bounds[0] = 0;
	bundle->size = argc - 1;
}
