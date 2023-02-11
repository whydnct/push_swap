#include "src/libft.h"
#include <stdio.h>

int	main(void)
{
	t_list	*first;
	int		cont;

	cont = 5;
	first = ft_lstnew((void *)&cont);
	printf("first content: %d\n", *(int *)(first->content));
}
