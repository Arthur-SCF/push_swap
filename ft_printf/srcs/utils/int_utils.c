/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asurcouf <asurcouf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 18:28:51 by asurcouf          #+#    #+#             */
/*   Updated: 2025/04/16 15:10:47 by asurcouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

int	count_digits(long n)
{
	int	len;

	if (n == 0)
		return (1);
	len = 0;
	if (n < 0)
		n = -n;
	while (n)
	{
		n /= 10;
		len++;
	}
	return (len);
}

void	print_padding(int width, int pad_char)
{
	while (width-- > 0)
		ft_putchar_fd(pad_char, 1);
}

void	print_sign(long n, t_format *fmt)
{
	if (n < 0)
	{
		ft_putchar_fd('-', 1);
		n = -(n);
	}
	else if (fmt->flags & FLAG_PLUS)
		ft_putchar_fd('+', 1);
	else if (fmt->flags & FLAG_SPACE)
		ft_putchar_fd(' ', 1);
}

void	print_nbr_only(long n, t_format *fmt)
{
	int		len;
	long	abs_n;

	abs_n = n;
	if (n < 0)
		abs_n = -abs_n;
	len = count_digits(n);
	if ((fmt->flags & FLAG_DOT) && fmt->precision > len)
		print_padding(fmt->precision - len, '0');
	if (!(n == 0 && (fmt->flags & FLAG_DOT) && fmt->precision == 0))
		ft_putnbr_fd(abs_n, 1);
}

int	get_nbr_len(long n, t_format *fmt)
{
	int	len;
	int	has_sign;
	int	digit_len;

	if (n == 0 && fmt->flags & FLAG_DOT && fmt->precision == 0)
		return (0);
	has_sign = (n < 0 || fmt->flags & FLAG_PLUS || fmt->flags & FLAG_SPACE);
	digit_len = count_digits(n);
	len = digit_len;
	if (has_sign)
		len++;
	if (fmt->flags & FLAG_DOT && fmt->precision > digit_len)
		len = fmt->precision + has_sign;
	return (len);
}
