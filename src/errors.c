/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperez-m <aperez-m@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 12:37:37 by aperez-m          #+#    #+#             */
/*   Updated: 2023/03/05 20:54:30 by aperez-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
Errores
- No hay parámetros
	- nada
- Sólo hay un parámetro
	- nada
- Los parámetros no son números, + o - (1)
	- free(bundle.params_str)
- Hay +-, -, +, ++, -- (2)
- Los parámetros están repetidos (3)
- Los parámetros están fuera de rango (4)
	- free(bundle.params_str)
	- free(bundle.params_str_lst)
	- while(i < bundle.params_nbr - 1)
		free(bundle.params_str_lst[i])
	- free(bundle.uint_lst)
*/

int	valid_chars(char c)
{
	if (ft_isdigit(c))
		return (1);
	if (c == ' ')
		return (2);
	if (c == '-' || c == '+')
		return (3);
	return (0);
}

void	error(t_bundle *bundle, int type_error)
{
	if (type_error > 1)
		free_all(bundle);
	if (type_error == 1)
		free(bundle->params_str);
	ft_putstr_fd("Error\n", 2);
	exit(1);
}

void	check_duplicate(int i, t_bundle *bundle)
{
	int	j;

	j = 0;
	while (j < i)
	{
		if (bundle->uint_lst[j] == bundle->uint_lst[i])
			error(bundle, 3);
		j++;
	}
}

void	check_ordered(t_bundle *bundle)
{
	unsigned int	i;

	i = 0;
	while (i < bundle->params_nbr - 1)
	{
		if (bundle->uint_lst[i] > bundle->uint_lst[i + 1])
			return ;
		i++;
	}
	if (i == bundle->params_nbr - 1)
	{
		free_all(bundle);
		exit(0);
	}
}
