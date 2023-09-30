/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adhaka <adhaka@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 02:37:46 by adhaka            #+#    #+#             */
/*   Updated: 2023/10/01 01:22:44 by adhaka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <limits.h>

typedef struct s_arr_elem
{
	int	data;
	int	i_index;
}	t_arr_elem;

typedef struct s_stack
{
	t_arr_elem	arr[9999];
	int			size;
}	t_stack;

void	error_msg(char **split);
void	free_split(char **split);

int		fill_data(int argc, char *argv[], t_arr_elem *arr);
int		ft_atol(const char *str);
void	check_duplicates(const t_stack *stack_a);
int		is_sorted(const t_stack *stack);
void	sort_array(int *arr, int size);
void	fill_i_index(t_stack *stack_a);

void	swap(t_stack *stack, char name);
void	push(t_stack *dst, t_stack *src, char name);
void	rotate(t_stack *stack, char name);
void	reverse_rotate(t_stack *stack, char name);

void	sort_three(t_stack *stack_a);
void	sort_five(t_stack *stack_a, t_stack *stack_b);
void	main_sort(t_stack *stack_a, t_stack *stack_b);

#endif
