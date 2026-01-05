/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus_parse.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyuskiv <yyuskiv@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 17:11:00 by yyuskiv           #+#    #+#             */
/*   Updated: 2025/12/15 17:43:08 by yyuskiv          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	parse_flags(const char **format, t_flags *flags)
{
	while (**format)
	{
		if (**format == '-')
			flags->minus = 1;
		else if (**format == '0')
			flags->zero = 1;
		else if (**format == '#')
			flags->hash = 1;
		else if (**format == '+')
			flags->plus = 1;
		else if (**format == ' ')
			flags->space = 1;
		else
			break ;
		(*format)++;
	}
	if (flags->minus)
		flags->zero = 0;
}

static int	ft_atoi_format(const char **format)
{
	int	result;

	result = 0;
	while (**format >= '0' && **format <= '9')
	{
		result = result * 10 + (**format - '0');
		(*format)++;
	}
	return (result);
}

void	parse_width(const char **format, t_flags *flags, va_list args)
{
	if (**format == '*')
	{
		flags->width = va_arg(args, int);
		if (flags->width < 0)
		{
			flags->minus = 1;
			flags->width = -flags->width;
			flags->zero = 0;
		}
		(*format)++;
	}
	else if (**format >= '0' && **format <= '9')
		flags->width = ft_atoi_format(format);
}

void	parse_precision(const char **format, t_flags *flags, va_list args)
{
	if (**format == '.')
	{
		(*format)++;
		flags->zero = 0;
		if (**format == '*')
		{
			flags->precision = va_arg(args, int);
			(*format)++;
		}
		else
			flags->precision = ft_atoi_format(format);
	}
}