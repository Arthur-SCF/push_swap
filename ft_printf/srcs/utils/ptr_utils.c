/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ptr_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asurcouf <asurcouf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 19:37:34 by asurcouf          #+#    #+#             */
/*   Updated: 2025/04/17 22:34:23 by asurcouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

int	count_ptr_digits(unsigned long n)
{
	int	len;

	len = 0;
	if (n == 0)
		return (1);
	while (n)
	{
		n /= 16;
		len++;
	}
	return (len);
}

void	print_ptr_hex(unsigned long n)
{
	char	*base;

	base = "0123456789abcdef";
	if (n >= 16)
		print_ptr_hex(n / 16);
	ft_putchar_fd(base[n % 16], 1);
}

int	get_ptr_len(unsigned long n, t_format *fmt)
{
	int	len;
	int	digit_len;

	if (n == 0 && (fmt->flags & FLAG_DOT) && fmt->precision == 0)
		return (0);
	digit_len = count_ptr_digits(n);
	len = digit_len + 2;
	if ((fmt->flags & FLAG_DOT) && fmt->precision > digit_len)
		len = fmt->precision + 2;
	return (len);
}

int	print_ptr_number(unsigned long n, t_format *fmt)
{
	int	len;
	int	digit_len;

	len = get_ptr_len(n, fmt);
	if (!(fmt->flags & FLAG_ZERO) || (fmt->flags & FLAG_DOT
			|| (fmt->flags & FLAG_MINUS)))
		ft_putstr_fd("0x", 1);
	digit_len = count_ptr_digits(n);
	if ((fmt->flags & FLAG_DOT) && fmt->precision > digit_len)
		print_padding(fmt->precision - digit_len, '0');
	if (!(n == 0 && (fmt->flags & FLAG_DOT) && fmt->precision == 0))
		print_ptr_hex(n);
	return (len);
}
