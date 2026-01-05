/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus_utils.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyuskiv <yyuskiv@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 17:11:00 by yyuskiv           #+#    #+#             */
/*   Updated: 2025/12/15 17:43:08 by yyuskiv          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	number_len(long n, int base)
{
	int	len;

	len = 0;
	if (n == 0)
		return (1);
	if (n < 0)
		n = -n;
	while (n > 0)
	{
		n /= base;
		len++;
	}
	return (len);
}

int	print_width(int width, int zeros)
{
	int	count;

	count = 0;
	while (width-- > 0)
	{
		if (zeros)
			count += write(1, "0", 1);
		else
			count += write(1, " ", 1);
	}
	return (count);
}

int	print_sign(t_flags *flags, int is_negative)
{
	if (is_negative)
		return (write(1, "-", 1));
	else if (flags->plus)
		return (write(1, "+", 1));
	else if (flags->space)
		return (write(1, " ", 1));
	return (0);
}

int	print_prefix(t_flags *flags, unsigned int n)
{
	if (flags->hash && n != 0)
	{
		if (flags->specifier == 'x')
			return (write(1, "0x", 2));
		else if (flags->specifier == 'X')
			return (write(1, "0X", 2));
	}
	return (0);
}

int	calc_int_len(long nbr, t_flags *flags)
{
	int	len;

	if (flags->precision == 0 && nbr == 0)
		return (0);
	len = number_len(nbr < 0 ? -nbr : nbr, 10);
	if (flags->precision > len)
		len = flags->precision;
	if (nbr < 0 || flags->plus || flags->space)
		len++;
	return (len);
}