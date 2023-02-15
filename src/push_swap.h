/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperez-m <aperez-m@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 13:18:06 by aperez-m          #+#    #+#             */
/*   Updated: 2023/02/15 20:31:41 by aperez-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include "../libft/src/libft.h"

long			ft_atoi_error(char *number, unsigned int *contents);
void			check_length(char *number, unsigned int *contents);
unsigned int	check_range(long number, unsigned int *contents);
void			check_argv(int argc, char **argv, unsigned int *contents);
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