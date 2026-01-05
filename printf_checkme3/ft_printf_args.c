/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_args.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyuskiv <yyuskiv@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 17:11:00 by yyuskiv           #+#    #+#             */
/*   Updated: 2025/12/15 18:50:00 by yyuskiv          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_char(va_list args)
{
	char	c;

	c = (char)va_arg(args, int);
	return (ft_putchar_fd(c, 1));
}

int	print_string(va_list args)
{
	char	*s;

	s = va_arg(args, char *);
	return (ft_putstr_fd(s, 1));
}

int	print_pointer(va_list args)
{
	void			*ptr;
	unsigned long	addr;
	int				count;

	ptr = va_arg(args, void *);
	addr = (unsigned long)ptr;
	count = 0;
	count += ft_putstr_fd("0x", 1);
	count += ft_putnbr_base_fd(addr, "0123456789abcdef", 1);
	return (count);
}

int	print_decimal(va_list args)
{
	int		n;
	long	nbr;
	int		count;

	n = va_arg(args, int);
	nbr = n;
	count = 0;
	if (nbr < 0)
	{
		count += ft_putchar_fd('-', 1);
		nbr = -nbr;
	}
	count += ft_putnbr_base_fd(nbr, "0123456789", 1);
	return (count);
}

int	print_unsigned(va_list args)
{
	unsigned int	n;

	n = va_arg(args, unsigned int);
	return (ft_putnbr_base_fd(n, "0123456789", 1));
}