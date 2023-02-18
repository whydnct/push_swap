/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperez-m <aperez-m@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 18:46:41 by aperez-m          #+#    #+#             */
/*   Updated: 2023/02/18 20:49:57 by aperez-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
/*
sa: swap a - intercambia los dos primeros elementos encima del stack a. No hace nada si hay uno o menos elementos.
sb: swap b - intercambia los dos primeros elementos encima del stack b. No hace nada si hay uno o menos elementos.
ss: swap a y swap b a la vez.
rb : rotate b - desplaza hacia arriba todos los elementos del stack b una posición, de forma que el primer elemento se convierte en el último.
rr : rotate a y rotate b - desplaza al mismo tiempo todos los elementos del stack a y del stack b una posición hacia arriba, de forma que el primer elemento se convierte en el último.
rra : reverse rotate a - desplaza hacia abajo todos los elementos del stack a una posición, de forma que el último elemento se convierte en el primero.
rrb : reverse rotate b - desplaza hacia abajo todos los elementos del stack b una posición, de forma que el último elemento se convierte en el primero.
rrr : reverse rotate a y reverse rotate b - desplaza al mismo tiempo todos los elementos del stack a y del stack b una posición hacia abajo, de forma que el último elemento se convierte en el primero.
*/
/*
pa: push a - toma el primer elemento del stack b y lo pone encima del stack a. No hace nada si b está vacío.
pb : push b - toma el primer elemento del stack a y lo pone encima del stack b. No hace nada si a está vacío.
*/
void	push_b(t_bundle *bundle)
{
	if (bundle->stack_a)
	{
		ft_lstadd_front(&bundle->stack_b, bundle->stack_a);
		bundle->stack_a = bundle->stack_a->next;
		ft_putstr_fd("pb", 1);
	}
}

void	push_a(t_bundle *bundle)
{
	if (bundle->stack_a)
	{
		ft_lstadd_front(&bundle->stack_a, bundle->stack_b);
		bundle->stack_b = bundle->stack_b->next;
		ft_putstr_fd("pa", 1);
	}
}

/*
ra : rotate a - desplaza hacia arriba todos los elementos del stack a una posición, de forma que el primer elemento se convierte en el último.
*/
void	rotate_a(t_bundle *bundle)
{
	t_list	*dummy;

	dummy = bundle->stack_a->next;
	ft_lstlast(bundle->stack_a)->next = bundle->stack_a;
	bundle->stack_a->next = NULL;
	bundle->stack_a = dummy;
	ft_putstr_fd("ra", 1);
}