/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asurcouf <asurcouf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 15:52:41 by asurcouf          #+#    #+#             */
/*   Updated: 2025/03/27 15:40:41 by asurcouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	free_split(char **split, int i)
{
	while (i--)
		free(split[i]);
	free(split);
}

static int	count_words(char const *str, char c)
{
	int	count;

	count = 0;
	while (*str)
	{
		while (*str == c)
			str++;
		if (*str)
		{
			count++;
			while (*str && *str != c)
				str++;
		}
	}
	return (count);
}

static int	get_word_len(const char *str, char c)
{
	int	len;

	len = 0;
	while (str[len] && str[len] != c)
		len++;
	return (len);
}

static char	*get_next_word(const char *str, char c, char **dest, int i)
{
	char	*word;
	int		len;

	len = get_word_len(str, c);
	word = (char *)malloc(sizeof(char) * (len + 1));
	if (!word)
	{
		free_split(dest, i);
		return (NULL);
	}
	while (len--)
		word[len] = str[len];
	word[get_word_len(str, c)] = '\0';
	return (word);
}

char	**ft_split(char const *s, char c)
{
	char	**dest;
	int		i;

	if (!s)
		return (NULL);
	dest = (char **)malloc(sizeof(char *) * (count_words(s, c) + 1));
	if (!dest)
		return (NULL);
	i = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s)
		{
			dest[i] = get_next_word(s, c, dest, i);
			if (!dest[i])
				return (NULL);
			s += get_word_len(s, c);
			i++;
		}
	}
	dest[i] = NULL;
	return (dest);
}
