/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperez-m <aperez-m@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 12:37:37 by aperez-m          #+#    #+#             */
/*   Updated: 2023/02/13 21:13:58 by aperez-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "push_swap.h"

/* Checks the validity of the arguments
TODO checkar que todos son int
	Size
		alguno es negativo
			el mayor positivo sólo puede ser INT_MAX
	Tipo
		primer carácter puede ser un más o un menos
		el resto de caracteres son numéricos
		max - min < max_unsigned int
		2147483647 - -2147483648 <= 429496729
	no duplicados
*/
void	error()
{
	ft_putstr_fd("Error, check your parametres.", 1);
	exit(1);
}
/* cambiar por un atoi mejorado que, en lugar de exit con 0 en error, exit con error()*/
int	valid_chars(char *number)
{
	int flag;

	flag = 1;
	if (ft_isdigit(*number) || *number == '+')
			number++;
	else if (*number == '-')
	{
		flag = -1;
		number++;
	}
	else
		error;
	while (*number)
	{
		if (!ft_isdigit(*number))
			error;
		number++;
	}
	return (flag * 1);
}

int	negative_params(int argc, char **argv)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (argv[i][0] == '+' || argv[i][0] == '-' || ft_isdigit(argv[i][0]))
		{
			i++;
			continue;
		}
		return (1);
	}
	return (0);
}

int	check_argv(int argc, char **argv)
{
	int	i;

	i = 0;
	(void)i;
	(void)argv;
	return (1);
}

void	read_list(int argc, int *contents, t_list **stack_a_add)
{
	int		i;

	i = 0;
	while (i < argc - 1)
	{
		ft_lstadd_back(stack_a_add, ft_lstnew(contents + i));
		i++;
	}
}

/*do not free, i haven't malloc'ed*/
void	ft_del(void *content)
{
	*(int*)content = 0;
}

void	ft_print_list(void *stack_a_el)
{
	printf("content: %d \n", *(int *)stack_a_el);
	printf("address: %p \n", stack_a_el);
}

	/*stack_a = malloc(sizeof(t_list *)); si aloco stack_a
	ft_lstaddback entra en el if, dejando un primer elemento
	de la lista vacío de contenido, no debo alocar, ni lo necesito
	*/
int	main(int argc, char **argv)
{
	t_list		*stack_a;
	t_list		*stack_b;
	int			*contents;
	int			i;

	//check_argv(argv);
	contents = malloc(sizeof(int) * (argc - 1));
	i = 0;
	while (++i < argc)
		contents[i - 1] = ft_atoi(argv[i]);
	read_list(argc, contents, &stack_a);
//	push_b(stack_a, stack_b);
//	push_swap(stack_a, stack_b);
	ft_lstiter(stack_a, &ft_print_list);
	printf("clearing memory\n");
	ft_lstclear(&stack_a, &ft_del);
	free(contents);
}
