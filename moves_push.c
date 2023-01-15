/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_push.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperez-m <aperez-m@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 12:51:28 by aperez-m          #+#    #+#             */
/*   Updated: 2023/01/15 12:51:48 by aperez-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	add_on_top(int **stack_to, int **stack_from, int *size_to)
{
	int	*temp_stack_to;
	int	i;

	i = 0;
	temp_stack_to = malloc(sizeof(int) * (*size_to + 1));
	if (temp_stack_to)
	{
		temp_stack[0] = *stack_from[0];
		while (++i <= *size_to)
			temp_stack_to[i] = stack_to[0][i - 1];
		free(*stack_to);
		*stack_to = temp_stack_to;
		(*size_to)++;
	}
}

void	remove_from_top(int **stack, int size)
{
	int	*temp_stack;
	int	i;

	i = 0;
	temp_stack = malloc(sizeof(int) * (size - 1));
	while (i < size - 1)
		temp_stack[i] = stack[0][i + 1];
	free(*stack);
	*stack = temp_stack;
	(*size)--;
}

void	push_a(int **stack_b, int **stack_a, int *size_b, int *size_a)
{
	if (*size_b > 0)
	{
		add_on_top(stack_a, stack_b, size_a);
		remove_from_top(stack_b, size_b);
		write(1, &"pa", 2);
	}	
}

void	push_b(int **stack_a, int **stack_b, int *size_a, int *size_b)
{
	if (*size_a > 0)
	{
		add_on_top(stack_b, stack_a, size_b);
		remove_from_top(stack_a, size_a);
		write(1, &"pb", 2);
	}	
}
