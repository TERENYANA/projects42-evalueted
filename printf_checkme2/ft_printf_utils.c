/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyuskiv <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 17:11:32 by yyuskiv           #+#    #+#             */
/*   Updated: 2025/12/15 17:11:34 by yyuskiv          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

int	ft_putchar_fd(char c, int fd)
{
	return (write(fd, &c, 1));
}

int	ft_putstr_fd(char *s, int fd)
{
	if (!s)
		s = "(null)";
	return (write(fd, s, ft_strlen(s)));
}

int	ft_putnbr_base_fd(unsigned long n, char *base, int fd)
{
	int		count;
	size_t	base_len;

	count = 0;
	base_len = ft_strlen(base);
	if (n >= base_len)
		count += ft_putnbr_base_fd(n / base_len, base, fd);
	count += ft_putchar_fd(base[n % base_len], fd);
	return (count);
}