/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyuskiv <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 17:55:47 by yyuskiv           #+#    #+#             */
/*   Updated: 2025/11/25 18:22:51 by yyuskiv          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stddef.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*ptr;
	unsigned char		letter;

	ptr = (const unsigned char *)s;
	letter = (unsigned char)c;
	while (n--)
	{
		if (*ptr == letter)
			return ((void *)ptr);
		ptr++;
	}
	return (NULL);
}

/*int main(void)
{
	char data[] = "abcdef";
	char *pos = ft_memchr(data, 'c', sizeof(data));

	if (pos)
		printf("Caractère trouvé : %c\n", *pos);
	else
		printf("Caractère non trouvé\n");

	return 0;
}*/
