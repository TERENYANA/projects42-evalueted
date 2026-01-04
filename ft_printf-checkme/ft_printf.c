#include "ft_printf.h"

static int	print_char(va_list args)
{
	char	c;

	c = (char)va_arg(args, int);
	return (ft_putchar_fd(c, 1));
}

static int	print_string(va_list args)
{
	char	*s;

	s = va_arg(args, char *);
	return (ft_putstr_fd(s, 1));
}

static int	print_pointer(va_list args)
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

static int	print_decimal(va_list args)
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

static int	print_unsigned(va_list args)
{
	unsigned int	n;

	n = va_arg(args, unsigned int);
	return (ft_putnbr_base_fd(n, "0123456789", 1));
}

static int	print_hex(va_list args, int uppercase)
{
	unsigned int	n;

	n = va_arg(args, unsigned int);
	if (uppercase)
		return (ft_putnbr_base_fd(n, "0123456789ABCDEF", 1));
	else
		return (ft_putnbr_base_fd(n, "0123456789abcdef", 1));
}

static int	handle_specifier(char specifier, va_list args)
{
	if (specifier == 'c')
		return (print_char(args));
	else if (specifier == 's')
		return (print_string(args));
	else if (specifier == 'p')
		return (print_pointer(args));
	else if (specifier == 'd' || specifier == 'i')
		return (print_decimal(args));
	else if (specifier == 'u')
		return (print_unsigned(args));
	else if (specifier == 'x')
		return (print_hex(args, 0));
	else if (specifier == 'X')
		return (print_hex(args, 1));
	else if (specifier == '%')
		return (ft_putchar_fd('%', 1));
	return (0);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		count;
	int		i;

	if (!format)
		return (-1);
	va_start(args, format);
	count = 0;
	i = 0;
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1])
		{
			i++;
			count += handle_specifier(format[i], args);
		}
		else if (format[i] != '%')
			count += ft_putchar_fd(format[i], 1);
		i++;
	}
	va_end(args);
	return (count);
}
