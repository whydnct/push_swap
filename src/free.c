/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperez-m <aperez-m@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 12:37:57 by aperez-m          #+#    #+#             */
/*   Updated: 2023/03/05 20:53:50 by aperez-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_del(void *content)
{
	*(unsigned int *)content = 0;
}

void	free_all(t_bundle	*bundle)
{
	unsigned int	i;

	i = -1;
	free(bundle->uint_lst);
	while (++i < bundle->params_nbr)
		free(bundle->params_str_lst[i]);
	free(bundle->params_str_lst);
	free(bundle->params_str);
}
