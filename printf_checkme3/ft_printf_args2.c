/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_args2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyuskiv <yyuskiv@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 17:11:00 by yyuskiv           #+#    #+#             */
/*   Updated: 2025/12/15 18:50:00 by yyuskiv          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	print_hex(va_list args, int uppercase)
{
	unsigned int	n;

	n = va_arg(args, unsigned int);
	if (uppercase)
		return (ft_putnbr_base_fd(n, "0123456789ABCDEF", 1));
	else
		return (ft_putnbr_base_fd(n, "0123456789abcdef", 1));
}

int	handle_specifier(char specifier, va_list args)
{
	if (specifier == 'c')
		return (print_char(args));
	if (specifier == 's')
		return (print_string(args));
	if (specifier == 'p')
		return (print_pointer(args));
	if (specifier == 'd' || specifier == 'i')
		return (print_decimal(args));
	if (specifier == 'u')
		return (print_unsigned(args));
	if (specifier == 'x')
		return (print_hex(args, 0));
	if (specifier == 'X')
		return (print_hex(args, 1));
	if (specifier == '%')
		return (ft_putchar_fd('%', 1));
	return (0);
}