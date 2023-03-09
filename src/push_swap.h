/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperez-m <aperez-m@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 13:18:06 by aperez-m          #+#    #+#             */
/*   Updated: 2023/03/09 17:34:37 by aperez-m         ###   ########.fr       */
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

typedef struct s_bundle
{
	unsigned int			params_nbr;
	char					*params_str;
	char					**params_str_lst;
	unsigned int			*uint_lst;
	t_list					*stack_a;
	t_list					*stack_b;
	int						moves;
	int						max_iters;
}	t_bundle;
//read_params
unsigned int			get_chars_nbr(int argc, char **argv);
void					get_params_str(int argc, char **argv, t_bundle *bundle);
void					get_params_nbr(t_bundle *bundle, char c);
unsigned int			atoi_unsigned(t_bundle *bundle, unsigned int i);
void					get_uint_lst(t_bundle *bundle);

//normalize_params
void					up_to_params_nbr(t_bundle *bundle);
void					down_to_zero(t_bundle *bundle);
void					fill_stack_a(t_bundle *bundle);

//errors

int						valid_chars(char c);
void					check_duplicate(int i, t_bundle *bundle);
void					error(t_bundle *bundle, int type_error);
void					check_ordered(t_bundle *bundle);

//moves_push_swap
void					push_b(t_bundle *bundle);
void					push_a(t_bundle *bundle);
void					swap_a(t_bundle *bundle);
void					swap_b(t_bundle *bundle);

//moves_rotate
void					rotate_a(t_bundle *bundle);
void					rotate_b(t_bundle *bundle);
void					r_rotate_a(t_bundle *bundle);

//simpler_sort
void					sort_5(t_bundle *bundle);
void					sort_3(t_bundle *bundle);
void					reduce_to_3(t_bundle *bundle);

//radix
int						get_max_iters(t_bundle bundle);
void					radix_one_position(t_bundle *bundle, int i);
void					radix_all_positions(t_bundle *bundle);

//free
void					ft_del(void *content);
void					free_all(t_bundle	*bundle);
#endif
