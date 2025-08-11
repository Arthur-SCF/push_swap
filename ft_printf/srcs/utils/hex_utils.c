/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hex_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asurcouf <asurcouf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 19:52:12 by asurcouf          #+#    #+#             */
/*   Updated: 2025/04/17 23:19:09 by asurcouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

int	count_hex_digits(unsigned int n)
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

void	print_hex(unsigned int n, int uppercase)
{
	char	*base;

	base = "0123456789abcdef";
	if (uppercase == 1)
		base = "0123456789ABCDEF";
	if (n >= 16)
		print_hex(n / 16, uppercase);
	ft_putchar_fd(base[n % 16], 1);
}

void	print_prefix(int uppercase)
{
	ft_putchar_fd('0', 1);
	if (uppercase == 0)
		ft_putchar_fd('x', 1);
	else
		ft_putchar_fd('X', 1);
}

int	get_hex_len(unsigned int n, t_format *fmt, int has_prefix)
{
	int	len;
	int	digit_len;

	if (n == 0 && (fmt->flags & FLAG_DOT) && fmt->precision == 0)
		return (0);
	digit_len = count_hex_digits(n);
	len = digit_len;
	if (has_prefix)
		len += 2;
	if ((fmt->flags & FLAG_DOT) && fmt->precision > digit_len)
	{
		len = fmt->precision;
		if (has_prefix)
			len += 2;
	}
	return (len);
}
