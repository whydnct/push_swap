/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperez-m <aperez-m@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 12:37:37 by aperez-m          #+#    #+#             */
/*   Updated: 2023/02/14 21:33:52 by aperez-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*TODO control que si me han metido negativos no me metan
positivos mayores que int_max*/
void	error(int *contents)
{
	ft_putstr_fd("Error, check your parametres.", 1);
	free(contents);
	exit(1);
}

long	ft_atoi_error(char *number, int *contents)
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
		error(contents);
	while (*number >= '0' && *number <= '9')
	{
		res = res * 10 + *number - '0';
		number++;
	}
	if (*number)
		error(contents);
	return (sign * res);
}

int	check_argv(int argc, char **argv)
{
	int	i;

	i = 0;
	(void)i;
	(void)argv;
	return (1);
}
