/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperez-m <aperez-m@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 12:37:37 by aperez-m          #+#    #+#             */
/*   Updated: 2023/02/15 20:53:54 by aperez-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error(unsigned int *contents, int type_error)
{
	if (type_error == 1)
		ft_putstr_fd("Error, parametre too long.\n", 2);
	else if (type_error == 2)
		ft_putstr_fd("Error, parametre is not a number.\n", 2);
	else if (type_error == 3)
		ft_putstr_fd("Error, parametre out of bounds.\n", 2);
	else if (type_error == 4)
		ft_putstr_fd("Error, repeated parametre.\n", 2);
	free(contents);
	exit(1);
}

long	ft_atoi_error(char *number, unsigned int *contents)
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
		error(contents, 2);
	while (*number >= '0' && *number <= '9')
	{
		res = res * 10 + *number - '0';
		number++;
	}
	if (*number)
		error(contents, 2);
	return (sign * res);
}

void	check_length(char *number, unsigned int *contents)
{
	if (ft_strlen(number) > 11)
		error(contents, 1);
}

unsigned int	check_range(long number, unsigned int *contents)
{
	if (number < -2147483648 || 2147483647 < number)
		error(contents, 3);
	return (2147483648 + (unsigned int)number);
}

void	check_argv(int argc, char **argv, unsigned int *contents)
{
	int				i;
	unsigned int	dummy;
	int				j;

	i = 0;
	j = 0;
	while (++i < argc)
	{
		check_length(argv[i], contents);
		dummy = check_range(ft_atoi_error(argv[i], contents), contents);
		while (j < i - 1)
		{
			if (contents[j] == dummy)
				error(contents, 4);
			j++;
		}
		j = 0;
		contents[i - 1] = dummy;
	}
}
