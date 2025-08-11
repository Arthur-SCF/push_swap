/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_str.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asurcouf <asurcouf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 16:09:33 by asurcouf          #+#    #+#             */
/*   Updated: 2025/05/02 13:28:20 by asurcouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

static int	handle_padding(t_format *fmt, char *str, char pad, int len)
{
	int	count;

	count = len;
	if (!(fmt->flags & FLAG_MINUS) && fmt->width > len)
	{
		print_padding(fmt->width - len, pad);
		count = fmt->width;
	}
	if (len > 0)
		write(1, str, len);
	if ((fmt->flags & FLAG_MINUS) && fmt->width > len)
	{
		print_padding(fmt->width - len, pad);
		count = fmt->width;
	}
	return (count);
}

int	convert_str(t_format *fmt)
{
	char	pad;
	char	*str;
	int		len;
	char	*null_str;

	null_str = "(null)";
	str = va_arg(fmt->args, char *);
	if (!str)
		str = null_str;
	len = ft_strlen(str);
	if ((fmt->flags & FLAG_DOT))
	{
		if (str == null_str && fmt->precision < len && fmt->precision >= 0)
			len = 0;
		else if (fmt->precision < len)
			len = fmt->precision;
	}
	pad = ' ';
	if ((fmt->flags & FLAG_ZERO) && !(fmt->flags & FLAG_DOT))
		pad = '0';
	return (handle_padding(fmt, str, pad, len));
}
