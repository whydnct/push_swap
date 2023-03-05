/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_rotate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperez-m <aperez-m@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 18:46:41 by aperez-m          #+#    #+#             */
/*   Updated: 2023/03/05 20:55:12 by aperez-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_a(t_bundle *bundle)
{
	t_list	*dummy;

	if (bundle->stack_a)
	{
		dummy = bundle->stack_a->next;
		ft_lstlast(bundle->stack_a)->next = bundle->stack_a;
		bundle->stack_a->next = NULL;
		bundle->stack_a = dummy;
		bundle->moves++;
		ft_putstr_fd("ra\n", 1);
	}
}

/*
rra : reverse rotate a - desplaza hacia abajo todos los elementos del stack a
una posición, de forma que el último elemento se convierte en el primero.
*/
void	r_rotate_a(t_bundle *bundle)
{
	t_list	*dummy_last;
	t_list	*dummy_head;

	if (bundle->stack_a->next)
	{
		dummy_last = ft_lstlast(bundle->stack_a);
		ft_lstlast(bundle->stack_a)->next = bundle->stack_a;
		dummy_head = bundle->stack_a;
		bundle->stack_a = dummy_last;
		while (dummy_head->next != dummy_last)
			dummy_head = dummy_head->next;
		dummy_head->next = NULL;
		bundle->moves++;
		ft_putstr_fd("rra\n", 1);
	}
}
