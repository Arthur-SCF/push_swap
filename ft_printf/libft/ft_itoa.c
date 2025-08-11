/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asurcouf <asurcouf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 15:53:00 by asurcouf          #+#    #+#             */
/*   Updated: 2025/03/26 23:37:57 by asurcouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static int	int_len(long nbr)
{
	int	i;

	i = 0;
	if (nbr <= 0)
	{
		i++;
		nbr = -nbr;
	}
	while (nbr > 0)
	{
		nbr /= 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	long	number;
	int		length;
	char	*result;

	number = n;
	length = int_len(number);
	result = (char *)ft_calloc(length + 1, sizeof(char));
	if (!result)
		return (NULL);
	if (number < 0)
		number = -number;
	while (length > 0)
	{
		result[--length] = (number % 10) + 48;
		number = number / 10;
	}
	if (n < 0)
		result[0] = '-';
	return (result);
}
