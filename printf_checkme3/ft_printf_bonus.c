/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyuskiv <yyuskiv@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 17:10:57 by yyuskiv           #+#    #+#             */
/*   Updated: 2025/12/15 19:30:00 by yyuskiv          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	init_flags(t_flags *flags)
{
	flags->minus = 0;
	flags->zero = 0;
	flags->width = 0;
	flags->precision = -1;
	flags->hash = 0;
	flags->plus = 0;
	flags->space = 0;
	flags->specifier = 0;
}

static int	handle_bonus(t_flags *flags, va_list args)
{
	if (flags->specifier == 'c')
		return (print_char_bonus((char)va_arg(args, int), flags));
	if (flags->specifier == 's')
		return (print_string_bonus(va_arg(args, char *), flags));
	if (flags->specifier == 'd' || flags->specifier == 'i')
		return (print_int_bonus(va_arg(args, int), flags));
	if (flags->specifier == 'u' || flags->specifier == 'x'
		|| flags->specifier == 'X')
		return (print_unsigned_bonus(va_arg(args, unsigned int), flags));
	if (flags->specifier == '%')
		return (print_char_bonus('%', flags));
	if (flags->specifier == 'p')
		return (print_pointer_bonus(va_arg(args, void *), flags));
	return (0);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	t_flags	flags;
	int		count;

	if (!format)
		return (-1);
	va_start(args, format);
	count = 0;
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			init_flags(&flags);
			parse_flags(&format, &flags);
			parse_width(&format, &flags, args);
			parse_precision(&format, &flags, args);
			flags.specifier = *format;
			count += handle_bonus(&flags, args);
			format++;
		}
		else
		{
			count += write(1, format, 1);
			format++;
		}
	}
	va_end(args);
	return (count);
}