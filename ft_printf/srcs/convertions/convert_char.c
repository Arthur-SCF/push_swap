/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_char.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asurcouf <asurcouf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 21:29:14 by asurcouf          #+#    #+#             */
/*   Updated: 2025/05/02 14:33:32 by asurcouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

int	convert_char(t_format *fmt)
{
	int				count;
	unsigned char	c;

	count = 1;
	c = (unsigned char)va_arg(fmt->args, int);
	if (!(fmt->flags & FLAG_MINUS) && fmt->width > 1)
	{
		print_padding(fmt->width - 1, ' ');
		count += fmt->width - 1;
	}
	ft_putchar_fd(c, 1);
	if ((fmt->flags & FLAG_MINUS) && fmt->width > 1)
	{
		print_padding(fmt->width - 1, ' ');
		count += fmt->width - 1;
	}
	return (count);
}

int	convert_percent(void)
{
	int		count;

	count = 1;
	ft_putchar_fd('%', 1);
	return (count);
}
