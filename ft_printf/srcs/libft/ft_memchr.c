/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asurcouf <asurcouf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 19:13:12 by asurcouf          #+#    #+#             */
/*   Updated: 2025/03/26 23:37:57 by asurcouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*char_s;

	char_s = (unsigned char *)s;
	while (n)
	{
		if (*char_s == (unsigned char)c)
			return (char_s);
		char_s++;
		n--;
	}
	return (NULL);
}
