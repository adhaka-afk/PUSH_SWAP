/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adhaka <adhaka@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 02:04:17 by adhaka            #+#    #+#             */
/*   Updated: 2023/07/02 20:24:06 by adhaka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack *stack, char name)
{
	t_arr_elem	temp;

	if (stack->size < 2)
		return ;
	temp = stack->arr[0];
	stack->arr[0] = stack->arr[1];
	stack->arr[1] = temp;
	write(1, "s", 1);
	write(1, &name, 1);
	write(1, "\n", 1);
}

void	push(t_stack *dst, t_stack *src, char name)
{
	int	a;

	if (src->size < 1)
		return ;
	a = dst->size - 1;
	while (a >= 0)
	{
		dst->arr[a + 1] = dst->arr[a];
		a--;
	}
	dst->arr[0] = src->arr[0];
	dst->size++;
	a = 0;
	while (a < src->size - 1)
	{
		src->arr[a] = src->arr[a + 1];
		a++;
	}
	src->size--;
	write(1, "p", 1);
	write(1, &name, 1);
	write(1, "\n", 1);
}

void	rotate(t_stack *stack, char name)
{
	t_arr_elem	temp;
	int			a;

	if (stack->size < 2)
		return ;
	temp = stack->arr[0];
	a = 0;
	while (a < stack->size - 1)
	{
		stack->arr[a] = stack->arr[a + 1];
		a++;
	}
	stack->arr[a] = temp;
	write(1, "r", 1);
	write(1, &name, 1);
	write(1, "\n", 1);
}

void	reverse_rotate(t_stack *stack, char name)
{
	t_arr_elem	temp;
	int			a;

	if (stack->size < 2)
		return ;
	temp = stack->arr[stack->size - 1];
	a = stack->size - 1;
	while (a > 0)
	{
		stack->arr[a] = stack->arr[a - 1];
		a--;
	}
	stack->arr[0] = temp;
	write(1, "rr", 2);
	write(1, &name, 1);
	write(1, "\n", 1);
}
