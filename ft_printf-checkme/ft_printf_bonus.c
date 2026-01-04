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

static void	parse_flags(const char **format, t_flags *flags)
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

static void	parse_width(const char **format, t_flags *flags, va_list args)
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

static void	parse_precision(const char **format, t_flags *flags, va_list args)
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

static int	number_len(long n, int base)
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

static int	print_width(int width, int zeros)
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

static int	print_sign(t_flags *flags, int is_negative)
{
	if (is_negative)
		return (write(1, "-", 1));
	else if (flags->plus)
		return (write(1, "+", 1));
	else if (flags->space)
		return (write(1, " ", 1));
	return (0);
}

static int	print_prefix(t_flags *flags, unsigned int n)
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

static int	calc_int_len(long nbr, t_flags *flags)
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

static int	print_int_bonus(int n, t_flags *flags)
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
	if (flags->precision > 0)
		count += print_width(flags->precision - number_len(nbr, 10), 1);
	if (!(flags->precision == 0 && n == 0))
		count += ft_putnbr_base_fd(nbr, "0123456789", 1);
	if (flags->minus && padding > 0)
		count += print_width(padding, 0);
	return (count);
}

static int	calc_unsigned_len(unsigned int n, t_flags *f, int base_len)
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

static int	print_unsigned_bonus(unsigned int n, t_flags *flags)
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
	if (flags->precision > 0)
		count += print_width(flags->precision - number_len(n, ft_strlen(base)), 1);
	if (!(flags->precision == 0 && n == 0))
		count += ft_putnbr_base_fd(n, base, 1);
	if (flags->minus && padding > 0)
		count += print_width(padding, 0);
	return (count);
}

static int	print_string_bonus(char *s, t_flags *flags)
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

static int	print_char_bonus(char c, t_flags *flags)
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

static int	print_pointer_bonus(void *ptr, t_flags *flags)
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

static int	handle_bonus(t_flags *flags, va_list args)
{
	if (flags->specifier == 'c')
		return (print_char_bonus((char)va_arg(args, int), flags));
	else if (flags->specifier == 's')
		return (print_string_bonus(va_arg(args, char *), flags));
	else if (flags->specifier == 'd' || flags->specifier == 'i')
		return (print_int_bonus(va_arg(args, int), flags));
	else if (flags->specifier == 'u' || flags->specifier == 'x'
		|| flags->specifier == 'X')
		return (print_unsigned_bonus(va_arg(args, unsigned int), flags));
	else if (flags->specifier == '%')
		return (print_char_bonus('%', flags));
	else if (flags->specifier == 'p')
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
		if (*format == '%' && *(format + 1))
		{
			format++;
			init_flags(&flags);
			parse_flags(&format, &flags);
			parse_width(&format, &flags, args);
			parse_precision(&format, &flags, args);
			flags.specifier = *format;
			count += handle_bonus(&flags, args);
		}
		else if (*format != '%')
			count += write(1, format, 1);
		format++;
	}
	va_end(args);
	return (count);
}
