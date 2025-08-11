/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asurcouf <asurcouf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 19:41:55 by asurcouf          #+#    #+#             */
/*   Updated: 2025/05/02 14:32:32 by asurcouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void	parse_flags(const char **format, t_format *fmt)
{
	fmt->flags = 0;
	while (**format)
	{
		if (**format == '-')
			fmt->flags |= FLAG_MINUS;
		else if (**format == '0')
			fmt->flags |= FLAG_ZERO;
		else if (**format == '#')
			fmt->flags |= FLAG_HASH;
		else if (**format == ' ')
			fmt->flags |= FLAG_SPACE;
		else if (**format == '+')
			fmt->flags |= FLAG_PLUS;
		else
			break ;
		(*format)++;
	}
}

static void	parse_width(const char **format, t_format *fmt)
{
	fmt->width = 0;
	while (ft_isdigit(**format))
	{
		fmt->width = (fmt->width * 10) + (**format - '0');
		(*format)++;
	}
}

static void	parse_precision(const char **format, t_format *fmt)
{
	fmt->precision = 0;
	if (**format != '.')
		return ;
	fmt->flags |= FLAG_DOT;
	(*format)++;
	while (ft_isdigit(**format))
	{
		fmt->precision = (fmt->precision * 10) + (**format - '0');
		(*format)++;
	}
}

static int	handle_conversion(const char type, t_format *fmt)
{
	if (type == CONV_CHAR)
		return (convert_char(fmt));
	else if (type == CONV_STR)
		return (convert_str(fmt));
	else if (type == CONV_PTR)
		return (convert_ptr(fmt));
	else if (type == CONV_DEC || type == CONV_INT)
		return (convert_int(fmt));
	else if (type == CONV_UINT)
		return (convert_uint(fmt));
	else if (type == CONV_HEX)
		return (convert_hex(fmt, 0));
	else if (type == CONV_UPHEX)
		return (convert_hex(fmt, 1));
	else if (type == CONV_PCT)
		return (convert_percent());
	return (ERR_CONV);
}

int	handle_format(const char **format, t_format *fmt)
{
	int	ret;

	parse_flags(format, fmt);
	parse_width(format, fmt);
	parse_precision(format, fmt);
	if (**format == 'c' || **format == 's' || **format == 'p'
		|| **format == 'd' || **format == 'i' || **format == 'u'
		|| **format == 'x' || **format == 'X' || **format == '%')
	{
		ret = handle_conversion(**format, fmt);
		fmt->count += ret;
		(*format)++;
		return (ret);
	}
	else
	{
		ft_putchar_fd('%', 1);
		ret = 1;
		fmt->count += ret;
		return (ret);
	}
	return (ERR_CONV);
}
