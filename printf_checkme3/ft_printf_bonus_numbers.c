/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus_numbers.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyuskiv <yyuskiv@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 17:11:00 by yyuskiv           #+#    #+#             */
/*   Updated: 2025/12/15 17:43:08 by yyuskiv          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	print_int_body(int n, long nbr, t_flags *flags)
{
	int	count;

	count = 0;
	if (flags->precision > 0)
		count += print_width(flags->precision - number_len(nbr, 10), 1);
	if (!(flags->precision == 0 && n == 0))
		count += ft_putnbr_base_fd(nbr, "0123456789", 1);
	return (count);
}

int	print_int_bonus(int n, t_flags *flags)
{
	int		count;
	int		len;
	int		padding;
	long	nbr;

	count = 0;
	nbr = n;
	len = calc_int_len(nbr, flags);
	padding = flags->width - len;
	if (!flags->minus && !flags->zero && padding > 0)
		count += print_width(padding, 0);
	count += print_sign(flags, nbr < 0);
	if (nbr < 0)
		nbr = -nbr;
	if (!flags->minus && flags->zero && flags->precision < 0 && padding > 0)
		count += print_width(padding, 1);
	count += print_int_body(n, nbr, flags);
	if (flags->minus && padding > 0)
		count += print_width(padding, 0);
	return (count);
}

static int	print_unsigned_body(unsigned int n, t_flags *f, char *base)
{
	int	count;

	count = 0;
	if (f->precision > 0)
		count += print_width(f->precision - number_len(n, ft_strlen(base)), 1);
	if (!(f->precision == 0 && n == 0))
		count += ft_putnbr_base_fd(n, base, 1);
	return (count);
}

int	print_unsigned_bonus(unsigned int n, t_flags *flags)
{
	int		count;
	int		len;
	int		padding;
	char	*base;

	count = 0;
	if (flags->specifier == 'x')
		base = "0123456789abcdef";
	else if (flags->specifier == 'X')
		base = "0123456789ABCDEF";
	else
		base = "0123456789";
	len = calc_unsigned_len(n, flags, ft_strlen(base));
	padding = flags->width - len;
	if (!flags->minus && !flags->zero && padding > 0)
		count += print_width(padding, 0);
	count += print_prefix(flags, n);
	if (!flags->minus && flags->zero && flags->precision < 0 && padding > 0)
		count += print_width(padding, 1);
	count += print_unsigned_body(n, flags, base);
	if (flags->minus && padding > 0)
		count += print_width(padding, 0);
	return (count);
}