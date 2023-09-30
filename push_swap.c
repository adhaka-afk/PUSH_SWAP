/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adhaka <adhaka@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 01:25:38 by adhaka            #+#    #+#             */
/*   Updated: 2023/07/02 20:52:54 by adhaka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_split(char **split)
{
	int	a;

	a = 0;
	while (split[a] != NULL)
		free(split[a++]);
	free(split);
}

void	error_msg(char **split)
{
	if (split)
		free_split(split);
	write(2, "Error\n", 6);
	exit (1);
}

int	fill_data(int argc, char *argv[], t_arr_elem *arr)
{
	char	**split;
	int		a;

	a = 0;
	if (argc == 2)
	{
		split = ft_split(argv[1], ' ');
		if (split == NULL)
			error_msg(NULL);
		while (split[a] != NULL)
		{
			arr[a].data = ft_atol(split[a]);
			if (arr[a].data > INT_MAX || arr[a++].data < INT_MIN)
				error_msg(split);
		}
		free_split(split);
		return (a);
	}
	while (a < argc - 1)
	{
		arr[a].data = ft_atol(argv[a + 1]);
		if (arr[a].data > INT_MAX || arr[a++].data < INT_MIN)
			error_msg(NULL);
	}
	return (a);
}

int	main(int argc, char *argv[])
{
	t_stack	stack_a;
	t_stack	stack_b;

	if (argc == 1)
		error_msg(NULL);
	stack_a.size = fill_data(argc, argv, stack_a.arr);
	stack_b.size = 0;
	check_duplicates(&stack_a);
	if (is_sorted(&stack_a))
		exit (0);
	fill_i_index(&stack_a);
	if (stack_a.size == 2)
		swap(&stack_a, 'a');
	else if (stack_a.size == 3)
		sort_three(&stack_a);
	else if (stack_a.size <= 5)
		sort_five(&stack_a, &stack_b);
	else
		main_sort(&stack_a, &stack_b);
	exit (0);
}
