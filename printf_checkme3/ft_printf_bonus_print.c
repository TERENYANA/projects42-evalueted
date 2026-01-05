/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus_print.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyuskiv <yyuskiv@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 17:11:00 by yyuskiv           #+#    #+#             */
/*   Updated: 2025/12/15 17:43:08 by yyuskiv          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	calc_unsigned_len(unsigned int n, t_flags *f, int base_len)
{
	int	len;

	if (f->precision == 0 && n == 0)
		return (0);
	len = number_len(n, base_len);
	if (f->precision > len)
		len = f->precision;
	if (f->hash && n != 0 && f->specifier != 'u')
		len += 2;
	return (len);
}

int	print_char_bonus(char c, t_flags *flags)
{
	int	count;

	count = 0;
	if (!flags->minus && flags->width > 1)
		count += print_width(flags->width - 1, 0);
	count += write(1, &c, 1);
	if (flags->minus && flags->width > 1)
		count += print_width(flags->width - 1, 0);
	return (count);
}

int	print_string_bonus(char *s, t_flags *flags)
{
	int	count;
	int	len;
	int	print_len;

	count = 0;
	if (!s)
		s = "(null)";
	len = ft_strlen(s);
	print_len = len;
	if (flags->precision >= 0 && flags->precision < len)
		print_len = flags->precision;
	if (!flags->minus && flags->width > print_len)
		count += print_width(flags->width - print_len, 0);
	count += write(1, s, print_len);
	if (flags->minus && flags->width > print_len)
		count += print_width(flags->width - print_len, 0);
	return (count);
}

int	print_pointer_bonus(void *ptr, t_flags *flags)
{
	unsigned long	addr;
	int				count;
	int				len;
	int				padding;

	count = 0;
	addr = (unsigned long)ptr;
	len = number_len(addr, 16) + 2;
	padding = flags->width - len;
	if (!flags->minus && padding > 0)
		count += print_width(padding, 0);
	count += write(1, "0x", 2);
	count += ft_putnbr_base_fd(addr, "0123456789abcdef", 1);
	if (flags->minus && padding > 0)
		count += print_width(padding, 0);
	return (count);
}