/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyuskiv <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 15:46:35 by yyuskiv           #+#    #+#             */
/*   Updated: 2025/11/25 17:33:18 by yyuskiv          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_bzero(void *s, size_t n)
{
	unsigned char		*p;
	size_t				i;

	p = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		p[i] = 0;
		i++;
	}
}

/*int	main(void)
{
	char	str[20] = "Hello World!";
	size_t	i;

	ft_bzero(str, 5);

	for (i = 0; i < 12; i++)
	{
		if (str[i] == 0)
			printf("\\0");
		else
			printf("%c", str[i]);
	}
	printf("\n");

	return (0);
}*/
