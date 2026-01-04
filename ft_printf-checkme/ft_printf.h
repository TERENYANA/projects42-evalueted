#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stddef.h>

typedef struct s_flags
{
	int		minus;
	int		zero;
	int		width;
	int		precision;
	int		hash;
	int		plus;
	int		space;
	char	specifier;
}	t_flags;

int		ft_printf(const char *format, ...);
size_t	ft_strlen(const char *s);
int		ft_putchar_fd(char c, int fd);
int		ft_putstr_fd(char *s, int fd);
int		ft_putnbr_base_fd(unsigned long n, char *base, int fd);

#endif