/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyuskiv <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 15:48:22 by yyuskiv           #+#    #+#             */
/*   Updated: 2025/11/25 17:49:54 by yyuskiv          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_isalpha(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
	else
		return (0);
}

/*int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		printf("Usage: %s <character>\n", argv[0]);
		return 1;
	}
	printf ("%d\n", ft_isalpha(argv[1][0]));
	return 0;
}*/
