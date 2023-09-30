/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adhaka <adhaka@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 21:29:48 by adhaka            #+#    #+#             */
/*   Updated: 2023/07/01 21:30:01 by adhaka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_sqrt(int number)
{
	int	i;

	if (number < 4)
		return (1);
	i = 2;
	while (i * i < number)
		i++;
	if (i * i > number)
	{
		if ((i * i - number) < ((i - 1) * (i - 1) + (-number)))
			return (i);
	}
	return (i - 1);
}
