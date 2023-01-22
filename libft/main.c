#include "src/libft.h"

int	main(void)
{
	char	*a;
	t_list	*b;

	a = "casa";
	b = ft_lstnew(a);
	ft_putstr_fd(a, 1);
	ft_putstr_fd(b->content, 1);
}
