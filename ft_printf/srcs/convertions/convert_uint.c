/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_uint.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asurcouf <asurcouf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 22:45:47 by asurcouf          #+#    #+#             */
/*   Updated: 2025/04/17 23:19:53 by asurcouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

static void	print_uint_only(unsigned int n, t_format *fmt)
{
	if (n == 0 && (fmt->flags & FLAG_DOT) && fmt->precision == 0)
		return ;
	if (n >= 10)
		print_uint_only((n / 10), fmt);
	ft_putchar_fd((n % 10) + '0', 1);
}

static int	print_uint_number(unsigned int n, t_format *fmt)
{
	int	len;
	int	digit_len;

	len = get_nbr_len(n, fmt);
	if (len == 0)
		return (0);
	digit_len = count_digits(n);
	if ((fmt->flags & FLAG_DOT) && fmt->precision > digit_len)
		print_padding(fmt->precision - digit_len, '0');
	print_uint_only(n, fmt);
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

int	convert_uint(t_format *fmt)
{
	unsigned int	n;
	int				len;
	char			pad;
	int				count;

	n = va_arg(fmt->args, unsigned int);
	fmt->flags &= ~(FLAG_PLUS | FLAG_SPACE);
	len = get_nbr_len(n, fmt);
	pad = ' ';
	if ((fmt->flags & FLAG_ZERO) && !(fmt->flags & FLAG_DOT)
		&& !(fmt->flags & FLAG_MINUS))
		pad = '0';
	count = handle_right_padding(fmt, pad, len);
	print_uint_number(n, fmt);
	return (handle_left_padding(fmt, count));
}
