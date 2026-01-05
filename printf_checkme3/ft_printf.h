/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyuskiv <yyuskiv@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 17:10:21 by yyuskiv           #+#    #+#             */
/*   Updated: 2025/12/15 18:50:00 by yyuskiv          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stddef.h>
# include <unistd.h>

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
}			t_flags;

int			ft_printf(const char *format, ...);
int			handle_specifier(char specifier, va_list args);
size_t		ft_strlen(const char *s);
int			ft_putchar_fd(char c, int fd);
int			ft_putstr_fd(char *s, int fd);
int			ft_putnbr_base_fd(unsigned long n, char *base, int fd);
int			print_char(va_list args);
int			print_string(va_list args);
int			print_pointer(va_list args);
int			print_decimal(va_list args);
int			print_unsigned(va_list args);
void		parse_flags(const char **format, t_flags *flags);
void		parse_width(const char **format, t_flags *flags, va_list args);
void		parse_precision(const char **format, t_flags *flags, va_list args);
int			number_len(long n, int base);
int			print_width(int width, int zeros);
int			print_sign(t_flags *flags, int is_negative);
int			print_prefix(t_flags *flags, unsigned int n);
int			calc_int_len(long nbr, t_flags *flags);
int			calc_unsigned_len(unsigned int n, t_flags *f, int base_len);
int			print_int_bonus(int n, t_flags *flags);
int			print_unsigned_bonus(unsigned int n, t_flags *flags);
int			print_string_bonus(char *s, t_flags *flags);
int			print_char_bonus(char c, t_flags *flags);
int			print_pointer_bonus(void *ptr, t_flags *flags);

#endif