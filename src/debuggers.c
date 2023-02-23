
#include <stdio.h>
#include "push_swap.h"

void	ft_print_bundle(t_bundle bundle)
{
	int size_a;
	int size_b;
	int i;

	i = 0;
	size_a = ft_lstsize(bundle.stack_a);
	size_b = ft_lstsize(bundle.stack_b);

	if (size_a > size_b)
	{
		while (i < size_a - size_b)
		{
			printf("%u @ %p \n", *(unsigned int *)bundle.stack_a->content, bundle.stack_a);
			bundle.stack_a = bundle.stack_a->next;
			i++;
		}
		while (i < size_a)
		{
			printf("%u @ %p \t\t\t %u @ %p \n", *(unsigned int *)bundle.stack_a->content, bundle.stack_a, *(unsigned int *)bundle.stack_b->content, bundle.stack_b);
			bundle.stack_b = bundle.stack_b->next;
			bundle.stack_a = bundle.stack_a->next;
			i++;
		}
	}
	else
	{
		while (i < size_b - size_a)
		{
			printf("               \t\t\t %u @ %p \n", *(unsigned int *)bundle.stack_b->content, bundle.stack_b);
			bundle.stack_b = bundle.stack_b->next;
			i++;
		}
		while (i < size_b)
		{
			printf("%u @ %p \t\t\t %u @ %p \n", *(unsigned int *)bundle.stack_a->content, bundle.stack_a, *(unsigned int *)bundle.stack_b->content, bundle.stack_b);
			bundle.stack_b = bundle.stack_b->next;
			bundle.stack_a = bundle.stack_a->next;
			i++;
		}
	}
	printf("---------------a\t\t----------------b\n");
}


void	ft_print_bundle_contents(t_bundle *bundle)
{
	unsigned int i;

	i = -1;
	while (++i < bundle->params_nbr)
		printf("[%u]", bundle->uint_lst[i]);
	printf("\n");
		
}


void	ft_print_list(t_list *stack)
{
	while (stack->next)
	{
		printf("content: %u @ %p\n", *(unsigned int *)stack->content, stack->content);
		stack = stack->next;
	}
	printf("content: %u @ %p\n", *(unsigned int *)stack->content, stack->content);
}

void	printf_params_str_lst(t_bundle *bundle)
{
	unsigned int	i;

	i = -1;
	printf("-----str_lst-----\n");
	while (++i < bundle->params_nbr)
		printf("param n%u:%s\n", i, bundle->params_str_lst[i]);
}

void	printf_uint_lst(t_bundle *bundle)
{
	unsigned int	i;

	i = -1;
	printf("-----uint_lst-----\n");
	while (++i < bundle->params_nbr)
		printf("param n%u:%u\n", i, bundle->uint_lst[i]);
}