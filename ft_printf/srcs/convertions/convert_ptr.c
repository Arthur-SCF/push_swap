/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_ptr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asurcouf <asurcouf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 20:05:18 by asurcouf          #+#    #+#             */
/*   Updated: 2025/04/19 12:33:50 by asurcouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

static void	handle_right_padding(t_format *fmt, char pad, int len)
{
	if (!(fmt->flags & FLAG_MINUS) && fmt->width > len)
		print_padding(fmt->width - len, pad);
}

static void	handle_left_padding(t_format *fmt, int len)
{
	if ((fmt->flags & FLAG_MINUS) && fmt->width > len)
		print_padding(fmt->width - len, ' ');
}

static	int	handle_nil_pointer(t_format *fmt)
{
	int	len;

	len = 5;
	if (!(fmt->flags & FLAG_MINUS) && fmt->width > len)
		print_padding(fmt->width - len, ' ');
	ft_putstr_fd("(nil)", 1);
	if ((fmt->flags & FLAG_MINUS) && fmt->width > len)
		print_padding(fmt->width - len, ' ');
	if (fmt->width > len)
		return (fmt->width);
	return (len);
}

static int	print_ptr_value(t_format *fmt, unsigned long n, int len)
{
	char	pad;

	pad = ' ';
	if ((fmt->flags & FLAG_ZERO) && !(fmt->flags & FLAG_DOT)
		&& !(fmt->flags & FLAG_MINUS))
		pad = '0';
	if (pad == '0')
	{
		ft_putstr_fd("0x", 1);
		handle_right_padding(fmt, pad, len);
		print_ptr_number(n, fmt);
	}
	else
	{
		handle_right_padding(fmt, pad, len);
		print_ptr_number(n, fmt);
		handle_left_padding(fmt, len);
	}
	if (fmt->width > len)
		return (fmt->width);
	return (len);
}

int	convert_ptr(t_format *fmt)
{
	int				len;
	unsigned long	n;

	n = (unsigned long)va_arg(fmt->args, unsigned long);
	if (!n)
		return (handle_nil_pointer(fmt));
	len = get_ptr_len(n, fmt);
	return (print_ptr_value(fmt, n, len));
}
