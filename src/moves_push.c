/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_push.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperez-m <aperez-m@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 20:17:55 by aperez-m          #+#    #+#             */
/*   Updated: 2023/01/20 19:05:24 by aperez-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	push_a(t_list **stack_b, t_list **stack_a)
{
	t_list	*temp;

	temp = (*stack_b)->next;
	ft_lstadd_front(stack_a, *stack_b);
	*stack_b = temp;
	ft_putstr_fd("pa\n", 1);
}

void	push_b(t_list **stack_a, t_list **stack_b)
{
	t_list	*temp;

	temp = (*stack_b)->next;
	ft_lstadd_front(stack_a, *stack_b);
	*stack_b = temp;
	ft_putstr_fd("pb\n", 1);
}
