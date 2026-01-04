/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyuskiv <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 15:50:51 by yyuskiv           #+#    #+#             */
/*   Updated: 2025/11/25 17:55:01 by yyuskiv          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

static int	ft_numlen(int n)
{
	int	len;

	len = 0;
	if (n <= 0)
		len = 1;
	while (n != 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		len;
	long	nbr;

	nbr = n;
	len = ft_numlen(n);
	str = (char *)malloc((len + 1) * sizeof(char));
	if (!str)
		return (NULL);
	str[len] = '\0';
	if (nbr < 0)
	{
		str[0] = '-';
		nbr = -nbr;
	}
	if (nbr == 0)
		str[0] = '0';
	while (nbr > 0)
	{
		len--;
		str[len] = (nbr % 10) + '0';
		nbr /= 10;
	}
	return (str);
}

/*int	main(void)
{
	char	*result;

	printf("Testing ft_itoa:\n");

	result = ft_itoa(-2147483648);
	printf("ft_itoa(-2147483648) = %s\n", result);
	free(result);

	result = ft_itoa(2147483647);
	printf("ft_itoa(2147483647) = %s\n", result);
	free(result);

	result = ft_itoa(-2147483647);
	printf("ft_itoa(-2147483647) = %s\n", result);
	free(result);

	result = ft_itoa(10);
	printf("ft_itoa(10) = %s\n", result);
	free(result);

	result = ft_itoa(12345);
	printf("ft_itoa(12345) = %s\n", result);
	free(result);

	result = ft_itoa(0);
	printf("ft_itoa(0) = %s\n", result);
	free(result);

	result = ft_itoa(-98765);
	printf("ft_itoa(-98765) = %s\n", result);
	free(result);

	return (0);
}*/
