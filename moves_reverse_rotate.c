/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_reverse_rotate.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperez-m <aperez-m@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 13:01:48 by aperez-m          #+#    #+#             */
/*   Updated: 2023/01/15 13:16:30 by aperez-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	r_rotate_a(int **stack, int size, int in_both_call)
{
	int	temp;
	int	last;
	int	i;

	if (size > 1)
	{
		i = -1;
		last = stack[0][size - 1];
		while (++i < size - 1)
			stack[0][i + 1] = stack[0][i];
		stack[0][0] = last;
		if (!in_both_call)
			write(1, &"rra", 3);
	}
}

void	r_rotate_b(int **stack, int size, int in_both_call)
{
	int	temp;
	int	last;
	int	i;

	if (size > 1)
	{
		i = -1;
		last = stack[0][size - 1];
		while (++i < size - 1)
			stack[0][i + 1] = stack[0][i];
		stack[0][0] = last;
		if (!in_both_call)
			write(1, &"rrb", 3);
	}
}

void	r_rotate_both(int **stack_a, int **stack_b, int size_a, int size_b)
{
	r_rotate_a(stack_a, size_a, 1);
	r_rotate_b(stack_b, size_b, 1);
	write(1, &"rrr", 3);
}
