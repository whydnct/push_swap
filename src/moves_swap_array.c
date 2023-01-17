/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_swap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperez-m <aperez-m@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 12:52:16 by aperez-m          #+#    #+#             */
/*   Updated: 2023/01/15 17:06:08 by aperez-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/* swaps the first two elements of the stack*/
/* doesn't do anything if #elements < 2*/
/* this las part wont be coded, bause this function*/
/* won´t be called if #elements <2*/
void	swap_a(int **stack_a, int *stack_size, int in_both_call)
{
	int		temp;

	if (*stack_size > 1)
	{
		temp = *stack_a[0];
		*stack_a[0] = *stack_a[1];
		*stack_a[1] = temp;
		write(1, "sa", 2);
		if (in_both_call == 0)
			write(1, "sb", 2);
	}
}

void	swap_b(int **stack_b, int *stack_size, int in_both_call)
{
	int		temp;

	if (*stack_size > 1)
	{
		temp = *stack_b[0];
		*stack_b[0] = *stack_b[1];
		*stack_b[1] = temp;
		if (in_both_call == 0)
			write(1, "sb", 2);
	}
}

void	swap_both(int **stack_a, int **stack_b, int *size_a, int *size_b)
{
	swap_a(stack_a, size_a, 1);
	swap_b(stack_b, size_b, 1);
	write(1, &"ss", 2);
}