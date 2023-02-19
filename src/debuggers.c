
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
	while (++i < bundle->size)
		printf("[%u]", bundle->contents[i]);
	printf("\n");
		
}


void	ft_print_list(void *stack_a_el)
{
	printf("content: %u @ %p\n", *(unsigned int *)stack_a_el, stack_a_el);
}