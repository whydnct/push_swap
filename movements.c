/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperez-m <aperez-m@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 16:32:09 by aperez-m          #+#    #+#             */
/*   Updated: 2023/01/14 17:41:47 by aperez-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* swaps the first two elements of the stack*/
/* doesn't do anything if #elements < 2*/
/* this las part wont be coded, bause this function*/
/* won´t be called if #elements <2*/
void	swap(int *stack, char stack_name)
{
	int		temp;

	temp = stack[0];
	stack[0] = stack[1];
	stack[1] = temp;
	if (stack_name == 'a' || stack_name == 'b')
	{
		ft_putchar_fd('s', 1);
		ft_putchar_fd(stack_name, 1);
	}
}

void	swap_both(int *stack_a, int *stack_b)
{
	swap(stack_a, '-');
	swap(stack_b, '-');
	write(1, &"ss", 2);
}


void	push(int *stack_to, int *stack_from, char stack_to, char stack_from)
{
	/*TODO*/

}

void rotate(int *stack)
{
	/*TODO*/
}

void rotate_both(int *stack_a, int *stack_b)
{
	/*TODO*/
}

void reverse_rotate(int *stack)
{
	/*TODO*/
}

void reverse_rotate_both(int *stack_a, int *stack_b)
{
	/*TODO*/
}