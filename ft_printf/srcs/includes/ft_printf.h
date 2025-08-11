/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asurcouf <asurcouf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 17:08:09 by asurcouf          #+#    #+#             */
/*   Updated: 2025/05/02 14:33:17 by asurcouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "../libft/libft.h"
# include <stdarg.h>

// macros for all conversions
# define CONV_CHAR   'c'
# define CONV_STR    's'
# define CONV_PTR    'p'
# define CONV_DEC    'd'
# define CONV_INT    'i'
# define CONV_UINT   'u'
# define CONV_HEX    'x'
# define CONV_UPHEX  'X'
# define CONV_PCT    '%'

//error handling
# define ERR_NULL    -1
# define ERR_FORMAT  -2
# define ERR_CONV    -3

//enum constant for flags
enum e_flags
{
	FLAG_MINUS = (1U << 0),
	FLAG_ZERO = (1U << 1),
	FLAG_HASH = (1U << 2),
	FLAG_SPACE = (1U << 3),
	FLAG_PLUS = (1U << 4),
	FLAG_DOT = (1U << 5)
};

//structure for 
typedef struct s_format
{
	va_list			args;
	int				count;
	int				width;
	int				precision;
	unsigned int	flags;
	int				error;
}	t_format;

int		ft_printf(const char *format, ...);
int		handle_format(const char **format, t_format *fmt);
int		convert_char(t_format *fmt);
int		convert_percent(void);
int		convert_str(t_format *fmt);
int		convert_ptr(t_format *fmt);
int		convert_int(t_format *fmt);
int		convert_uint(t_format *fmt);
int		convert_hex(t_format *fmt, int uppercase);
int		count_digits(long n);
int		get_nbr_len(long n, t_format *fmt);
void	print_sign(long n, t_format *fmt);
void	print_nbr_only(long n, t_format *fmt);
void	print_padding(int width, int pad_char);
int		count_hex_digits(unsigned int n);
void	print_hex(unsigned int n, int uppercase);
int		get_hex_len(unsigned int n, t_format *fmt, int has_prefix);
void	print_prefix(int uppercase);
int		count_ptr_digits(unsigned long n);
void	print_ptr_hex(unsigned long n);
int		get_ptr_len(unsigned long n, t_format *fmt);
int		print_ptr_number(unsigned long n, t_format *fmt);

#endif // FT_PRINTF_H
