/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adhaka <adhaka@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 05:56:02 by adhaka            #+#    #+#             */
/*   Updated: 2023/10/01 01:29:55 by adhaka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_duplicates(const t_stack *stack_a)
{
	int	a;
	int	b;

	a = 0;
	while (a < stack_a->size - 1)
	{
		b = a + 1;
		while (b < stack_a->size)
		{
			if (stack_a->arr[a].data == stack_a->arr[b].data)
				error_msg(NULL);
			b++;
		}
		a++;
	}
}

int	is_sorted(const t_stack *stack)
{
	int	a;

	a = 0;
	while (a < stack->size - 1)
	{
		if (stack->arr[a].data > stack->arr[a + 1].data)
			return (0);
		a++;
	}
	return (1);
}

int	ft_atol(const char *str)
{
	int		a;
	int		sign;
	long	res;

	sign = 1;
	a = 0;
	res = 0;
	while (str[a] == 32 || (str[a] >= 9 && str[a] <= 13))
		a++;
	if (str[a] == '-')
	{
		sign = -1;
		a++;
	}
	else if (str[a] == '+')
		a++;
	while (str[a] != '\0')
	{
		if (!('0' <= str[a] && str[a] <= '9'))
			break ;
		res = res * 10 + (str[a] - '0');
		a++;
	}
	res *= sign;
	return (res);
}

void	sort_array(int *arr, int size)
{
	int	temp;
	int	a;
	int	b;

	a = 0;
	while (a < size - 1)
	{
		b = 0;
		while (b < size - a - 1)
		{
			if (arr[b] > arr[b + 1])
			{
				temp = arr[b];
				arr[b] = arr[b + 1];
				arr[b + 1] = temp;
			}
			b++;
		}
		a++;
	}
}

void	fill_i_index(t_stack *stack_a)
{
	int	arr[9999];
	int	a;
	int	b;

	a = 0;
	while (a < stack_a->size)
	{
		arr[a] = stack_a->arr[a].data;
		a++;
	}
	sort_array(arr, stack_a->size);
	a = 0;
	while (a < stack_a->size)
	{
		b = 0;
		while (b < stack_a->size)
		{
			if (arr[b] == stack_a->arr[a].data)
				stack_a->arr[a].i_index = b;
			b++;
		}
		a++;
	}
}
