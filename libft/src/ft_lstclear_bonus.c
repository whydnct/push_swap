/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperez-m <aperez-m@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 16:00:20 by aperez-m          #+#    #+#             */
/*   Updated: 2023/02/08 20:40:56 by aperez-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*Elimina y libera el nodo ’lst’ dado y todos los consecutivos de ese nodo,
utilizando la función ’del’ y free(3). Al final, el puntero a la lista 
debe ser NULL.*/

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*ptr;

	ft_putstr_fd("entering ft_lstclear\n", 1);
	if (lst)
	{
		while (*lst)
		{
			ptr = (*lst)->next;
			ft_lstdelone(*lst, del);
			ft_putstr_fd("jumping to next item in list \n", 1);
			if(ptr == NULL)
				return;
			*lst = ptr;
			ft_putstr_fd("*lst reassigned to ptr\n", 1);
		}
		ft_putstr_fd("exiting while\n", 1);
	}
}
