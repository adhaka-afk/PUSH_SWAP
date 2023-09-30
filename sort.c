/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adhaka <adhaka@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 02:04:20 by adhaka            #+#    #+#             */
/*   Updated: 2023/07/02 20:24:50 by adhaka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	count_r(t_stack *stack, int i_index)
{
	int	a;

	a = 0;
	while (a < stack->size)
	{
		if (stack->arr[a].i_index == i_index)
			break ;
		a++;
	}
	return (a);
}

void	sort_three(t_stack *stack_a)
{
	int	a;
	int	b;
	int	c;

	a = stack_a->arr[0].data;
	b = stack_a->arr[1].data;
	c = stack_a->arr[2].data;
	if (is_sorted(stack_a))
		return ;
	if (stack_a->size == 3 && ((b < c && a > c) || (c < a && a < b)))
	{
		if (count_r(stack_a, 0) == 1)
			rotate(stack_a, 'a');
		else
			reverse_rotate(stack_a, 'a');
	}
	else
	{
		swap(stack_a, 'a');
		sort_three(stack_a);
	}
}

void	sort_five(t_stack *stack_a, t_stack *stack_b)
{
	int	r;
	int	rr;
	int	a;

	a = 0;
	while (stack_a->size != 3)
	{
		r = count_r(stack_a, 3 + a);
		rr = stack_a->size - r;
		while (stack_a->arr[0].i_index != 3 + a)
		{
			if (r > rr)
				reverse_rotate(stack_a, 'a');
			else
				rotate(stack_a, 'a');
		}
		push(stack_b, stack_a, 'b');
		a++;
	}
	sort_three(stack_a);
	while (stack_b->size != 0)
		push(stack_a, stack_b, 'a');
	while (!is_sorted(stack_a))
		rotate(stack_a, 'a');
}

static void	main_sort2(t_stack *stack_a, t_stack *stack_b)
{
	int	r;
	int	rr;

	while (stack_b->size != 0)
	{
		while (stack_b->arr[0].i_index != stack_b->size - 1)
		{
			r = count_r(stack_b, stack_b->size - 1);
			rr = stack_b->size - r;
			if (r <= rr)
				rotate(stack_b, 'b');
			else
				reverse_rotate(stack_b, 'b');
		}
		push(stack_a, stack_b, 'a');
	}
}

void	main_sort(t_stack *stack_a, t_stack *stack_b)
{
	int	a;
	int	factor;

	a = 0;
	factor = ft_sqrt(stack_a->size) * 2;
	while (stack_a->size)
	{
		if (stack_a->arr[0].i_index <= a + factor)
		{
			push(stack_b, stack_a, 'b');
			if (stack_b->arr[0].i_index <= a)
				rotate(stack_b, 'b');
			a++;
		}
		else
			rotate(stack_a, 'a');
	}
	main_sort2(stack_a, stack_b);
}
