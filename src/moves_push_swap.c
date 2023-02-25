/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_push_swap.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperez-m <aperez-m@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 18:46:41 by aperez-m          #+#    #+#             */
/*   Updated: 2023/02/25 21:59:16 by aperez-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>
/*
pb : push b - toma el primer elemento del stack a y lo pone encima 
del stack b. No hace nada si a está vacío.
*/
void	push_b(t_bundle *bundle)
{
	t_list	*dummy;

	if (bundle->stack_a)
	{
		dummy = bundle->stack_a->next;
		ft_lstadd_front(&bundle->stack_b, bundle->stack_a);
		bundle->stack_a = dummy;
		bundle->moves++;
		ft_putstr_fd("pb\n", 1);
	}
}

/*
pa: push a - toma el primer elemento del stack b y lo pone encima 
del stack a. No hace nada si b está vacío.
*/
void	push_a(t_bundle *bundle)
{
	t_list	*dummy;

	if (bundle->stack_b)
	{
		dummy = bundle->stack_b->next;
		ft_lstadd_front(&bundle->stack_a, bundle->stack_b);
		bundle->stack_b = dummy;
		//ft_print_list(bundle->stack_b);
		ft_print_bundle(*bundle);
		bundle->moves++;
		ft_putstr_fd("pa\n", 1);
	}
}

/*
sa: swap a - intercambia los dos primeros elementos encima del stack a. No hace
nada si hay uno o menos elementos.
*/
void	swap_a(t_bundle *bundle)
{
	t_list	*dummy_second;

	dummy_second = bundle->stack_a->next;
	bundle->stack_a->next = dummy_second->next;
	dummy_second->next = bundle->stack_a;
	bundle->stack_a = dummy_second;
	bundle->moves++;
	ft_putstr_fd("sa\n", 1);
}

/*
sa: swap a - intercambia los dos primeros elementos encima del stack a. No hace
nada si hay uno o menos elementos.
*/
void	swap_b(t_bundle *bundle)
{
	t_list	*dummy_second;

	dummy_second = bundle->stack_b->next;
	bundle->stack_b->next = dummy_second->next;
	dummy_second->next = bundle->stack_b;
	bundle->stack_b = dummy_second;
	bundle->moves++;
	ft_putstr_fd("sb\n", 1);
}

/*
sb: swap b - intercambia los dos primeros elementos encima del stack b.
	No hace nada si hay uno o menos elementos.
ss: swap a y swap b a la vez.
rb : rotate b - desplaza hacia arriba todos los elementos del stack b
	una posición, de forma que el primer elemento se convierte en el último.
rr : rotate a y rotate b - desplaza al mismo tiempo todos los elementos del
	stack a y del stack b una posición hacia arriba, de forma que el primer
	elemento se convierte en el último.
rrb : reverse rotate b - desplaza hacia abajo todos los elementos del stack
	b una posición, de forma que el último elemento se convierte en el primero.
rrr : reverse rotate a y reverse rotate b - desplaza al mismo tiempo todos los
	elementos del stack a y del stack b una posición hacia abajo, de forma
	que el último elemento se convierte en el primero.
*/