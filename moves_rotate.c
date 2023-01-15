/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_rotate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperez-m <aperez-m@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 12:53:07 by aperez-m          #+#    #+#             */
/*   Updated: 2023/01/15 13:01:27 by aperez-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	rotate_a(int **stack, int size, int in_both_call)
{
	int	temp;
	int	first;
	int	i;

	if (size > 1)
	{
		i = -1;
		first = stack[0][0];
		while (++i < size - 1)
			stack[0][i] = stack[0][i + 1];
		stack[0][size - 1] = first;
		if (!in_both_call)
			write(1, &"ra", 2);
	}
}

void	rotate_b(int **stack, int size, int in_both_call)
{
	int	temp;
	int	first;
	int	i;

	if (size > 1)
	{
		i = -1;
		first = stack[0][0];
		while (++i < size - 1)
			stack[0][i] = stack[0][i + 1];
		stack[0][size - 1] = first;
		if (!in_both_call)
			write(1, &"rb", 2);
	}
}

void	rotate_both(int *stack_a, int *stack_b, int *size_a, int *size_b)
{
	rotate_a(stack_a, size_a, 1);
	rotate_b(stack_b, size_b, 1);
	write(1, &"rr", 2);
}