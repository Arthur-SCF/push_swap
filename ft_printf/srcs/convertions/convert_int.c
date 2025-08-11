/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_int.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asurcouf <asurcouf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 17:27:35 by asurcouf          #+#    #+#             */
/*   Updated: 2025/05/02 14:29:32 by asurcouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

static void	handle_sign(long n, t_format *fmt)
{
	if (n < 0)
		ft_putchar_fd('-', 1);
	else if (fmt->flags & FLAG_PLUS)
		ft_putchar_fd('+', 1);
	else if ((fmt->flags & FLAG_SPACE) && n >= 0)
		ft_putchar_fd(' ', 1);
}

static void	handle_padding_and_number(long abs_n, int digit_len, t_format *fmt)
{
	if ((fmt->flags & FLAG_DOT) && fmt->precision > digit_len)
		print_padding(fmt->precision - digit_len, '0');
	if (!(abs_n == 0 && (fmt->flags & FLAG_DOT) && fmt->precision == 0))
		ft_putnbr_fd(abs_n, 1);
}

static int	print_number(long n, t_format *fmt)
{
	int		len;
	long	abs_n;

	len = get_nbr_len(n, fmt);
	if (len == 0)
		return (0);
	if (n == -2147483648)
	{
		ft_putstr_fd("-2147483648", 1);
		return (len);
	}
	if (n < 0)
		abs_n = -n;
	else
		abs_n = n;
	handle_sign(n, fmt);
	handle_padding_and_number(abs_n, count_digits(abs_n), fmt);
	return (len);
}

static int	handle_padding(t_format *fmt, long n, int len, char pad)
{
	int	count;

	count = len;
	if ((!(fmt->flags & FLAG_MINUS) && fmt->width > len))
	{
		if (pad == '0' && (n < 0 || fmt->flags & FLAG_PLUS
				|| fmt->flags & FLAG_SPACE))
			print_sign(n, fmt);
		print_padding(fmt->width - len, pad);
		count = fmt->width;
	}
	if (pad == '0' && !(fmt->flags & FLAG_MINUS) && fmt->width > len && (n < 0
			|| fmt->flags & FLAG_PLUS
			|| fmt->flags & FLAG_SPACE))
		print_nbr_only(n, fmt);
	else
		print_number(n, fmt);
	if ((fmt->flags & FLAG_MINUS) && fmt->width > len)
	{
		print_padding(fmt->width - len, ' ');
		count = fmt->width;
	}
	return (count);
}

int	convert_int(t_format *fmt)
{
	int		nbr;
	long	n;
	int		len;
	char	pad;

	nbr = va_arg(fmt->args, int);
	n = nbr;
	len = get_nbr_len(n, fmt);
	pad = ' ';
	if ((fmt->flags & FLAG_ZERO) && !(fmt->flags & FLAG_DOT)
		&& !(fmt->flags & FLAG_MINUS))
		pad = '0';
	return (handle_padding(fmt, n, len, pad));
}
