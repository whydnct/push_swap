/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperez-m <aperez-m@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 13:18:06 by aperez-m          #+#    #+#             */
/*   Updated: 2023/02/24 22:38:25 by aperez-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# define UINT_MAX 4294967295
# define INT_MAX 2147483647
# define INT_MIN -2147483648
# define INT_MIN_ABS 2147483648

# include <unistd.h>
# include <stdlib.h>
# include "../libft/src/libft.h"

typedef struct s_stack
{
	void			*content;
	struct s_stack	*next;
	struct s_bundle	*bundle;

} t_stack;
typedef struct s_bundle
{
	unsigned int			params_nbr;
	char					*params_str;
	char					**params_str_lst;
	unsigned int			*uint_lst;
	t_list					*stack_a;
	t_list					*stack_b;
	int						moves;
}	t_bundle;
unsigned int			atoi_unsigned(t_bundle *bundle, unsigned int i);
void					check_length(char *number, t_bundle *bundle);
void					check_argv(int argc, char **argv, t_bundle *bundle);
void					check_duplicate(int i, t_bundle *bundle);
int						get_max_iters(t_bundle bundle);
void					radix_one_position(t_bundle *bundle, int i);
void					radix_all_positions(t_bundle *bundle);

//moves
void					push_b(t_bundle *bundle);
void					push_a(t_bundle *bundle);
void					rotate_a(t_bundle *bundle);
void					down_to_zero(t_bundle *bundle);
unsigned int			get_chars_nbr(int argc, char **argv);
void					get_params_str(int argc, char **argv, t_bundle *bundle);
void					get_params_nbr(t_bundle *bundle, char c);
int						valid_chars(char c);
void					up_to_params_nbr(t_bundle *bundle);
void					simpler_sort(t_bundle *bundle);

//debuggers
void					printf_params_str_lst(t_bundle *bundle);
void					ft_print_bundle(t_bundle bundle);
void					ft_print_bundle_contents(t_bundle *bundle);
void					printf_uint_lst(t_bundle *bundle);
void					ft_print_list(t_list *stack);
/*
void			push_a(t_list **stack_b, t_list **stack_a);
void			push_b(t_list **stack_a, t_list **stack_b);
void			error(unsigned int *contents, int type_error);
void	r_rotate_a(int **stack, int *size, int in_both_call);
void	r_rotate_b(int **stack, int *size, int in_both_call);
void	r_rotate_both(int **stack_a, int **stack_b, int *size_a, int *size_b);
void	rotate_a(int **stack, int *size, int in_both_call);
void	rotate_b(int **stack, int *size, int in_both_call);
void	rotate_both(int **stack_a, int **stack_b, int *size_a, int *size_b);
void	add_on_top(int **stack_to, int **stack_from, int *size_to);
void	remove_from_top(int **stack, int *size);
*/
#endif