/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asurcouf <asurcouf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 19:13:43 by asurcouf          #+#    #+#             */
/*   Updated: 2025/03/27 12:23:52 by asurcouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	*ft_strnstr(const char *haystack, const char *needle, size_t n)
{
	const char	*c_h;
	const char	*c_n;
	size_t		len;

	if (!*needle)
		return ((char *)haystack);
	if (!n)
		return (NULL);
	while (*haystack && n)
	{
		c_h = haystack;
		c_n = needle;
		len = n;
		while (len-- && *c_h && *c_n && *c_h == *c_n)
		{
			c_h++;
			c_n++;
		}
		if (!*c_n)
			return ((char *)haystack);
		haystack++;
		n--;
	}
	return (NULL);
}
