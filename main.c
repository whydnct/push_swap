/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperez-m <aperez-m@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 12:37:37 by aperez-m          #+#    #+#             */
/*   Updated: 2023/01/15 00:36:08 by aperez-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Checks the validity of the arguments*/
int arg_checker(int argc, char **argv)
{
	int	i;

	i = 0;
	while(++i <= argc)
	{
		if (!ft_atoi(argv[i]))
	}

}

int	*read_list(int argc, char **argv, int *stac_a)
{
	/* TODO */
	arg_checker(argc, argv)
}

int main(int argc, char **argv)
{
	int	*stack_a;
	int	*stack_b;

	stack_a = malloc(sizeof(int)*(argc - 1));
	if (stack_a == NULL)
		return (-1);
	if (read_list(argc, argv, stack_a))
		return (-1);
	push_swap(stack_a, stack_b);

}