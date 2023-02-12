#include "src/libft.h"
#include <stdio.h>

int	main(void)
{
	t_list	*first;
	t_list	*second;
	int		cont;
	int		cont2;

	cont = 1;
	cont2 = 2;
	first = ft_lstnew((void *)&cont);
	second = ft_lstnew((void *)&cont2);
	ft_lstadd_back(&first, second);
//	ft_lstiter(first, &ft_putstr_fd);
	while (first)
	{
		printf("%d\n", *(int *)first->content);
		first = first->next;
	}
	//printf("first content: %d\n", *(int *)(first->content));
}
