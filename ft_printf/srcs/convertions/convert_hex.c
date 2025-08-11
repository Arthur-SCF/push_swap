/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_hex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asurcouf <asurcouf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 19:47:41 by asurcouf          #+#    #+#             */
/*   Updated: 2025/05/02 13:26:49 by asurcouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

static int	print_hex_number(unsigned int n, t_format *fmt, int uppercase)
{
	int	len;
	int	digit_len;
	int	has_prefix;

	has_prefix = ((fmt->flags & FLAG_HASH) && n != 0);
	len = get_hex_len(n, fmt, has_prefix);
	if (len == 0)
		return (0);
	if (fmt->width > len && !(fmt->flags & FLAG_MINUS) && has_prefix)
		has_prefix = 0;
	if (has_prefix && !(fmt->width > len))
		print_prefix(uppercase);
	digit_len = count_hex_digits(n);
	if ((fmt->flags & FLAG_DOT) && fmt->precision > digit_len)
		print_padding(fmt->precision - digit_len, '0');
	if (!(n == 0 && (fmt->flags & FLAG_DOT) && fmt->precision == 0))
		print_hex(n, uppercase);
	return (len);
}

static int	handle_right_padding(t_format *fmt, char pad, int len)
{
	if (!(fmt->flags & FLAG_MINUS) && fmt->width > len)
	{
		print_padding(fmt->width - len, pad);
		return (fmt->width);
	}
	return (len);
}

static int	handle_left_padding(t_format *fmt, int len)
{
	if ((fmt->flags & FLAG_MINUS) && fmt->width > len)
	{
		print_padding(fmt->width - len, ' ');
		return (fmt->width);
	}
	return (len);
}

int	convert_hex(t_format *fmt, int uppercase)
{
	int				len;
	char			pad;
	int				count;
	int				has_prefix;
	unsigned int	n;

	n = va_arg(fmt->args, unsigned int);
	has_prefix = ((fmt->flags & FLAG_HASH) && n != 0);
	len = get_hex_len(n, fmt, has_prefix);
	pad = ' ';
	if ((fmt->flags & FLAG_ZERO) && !(fmt->flags & FLAG_DOT)
		&& !(fmt->flags & FLAG_MINUS))
		pad = '0';
	if ((pad == '0' && has_prefix) || (fmt->width > len && has_prefix
			&& (fmt->flags & FLAG_MINUS)))
	{
		print_prefix(uppercase);
		has_prefix = 0;
	}
	count = handle_right_padding(fmt, pad, len);
	if (fmt->width > len && !(fmt->flags & FLAG_MINUS) && has_prefix)
		print_prefix(uppercase);
	print_hex_number(n, fmt, uppercase);
	return (handle_left_padding(fmt, count));
}
