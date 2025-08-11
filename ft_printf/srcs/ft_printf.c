/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asurcouf <asurcouf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 13:07:12 by asurcouf          #+#    #+#             */
/*   Updated: 2025/05/02 13:26:29 by asurcouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int	parse_format(const char *format, t_format *fmt)
{
	if (!*format)
		return (0);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (!*format)
			{
				ft_putchar_fd('%', 1);
				fmt->count++;
				return (fmt->count);
			}
			handle_format(&format, fmt);
		}
		else
			fmt->count += write(1, format++, 1);
	}
	return (fmt->count);
}

static void	init_format(t_format *fmt)
{
	fmt->count = 0;
	fmt->width = 0;
	fmt->precision = 0;
	fmt->flags = 0;
	fmt->error = 0;
}

int	ft_printf(const char *format, ...)
{
	t_format	fmt;
	int			ret;

	if (!format)
		return (ERR_NULL);
	init_format(&fmt);
	va_start(fmt.args, format);
	ret = parse_format(format, &fmt);
	va_end(fmt.args);
	return (ret);
}
