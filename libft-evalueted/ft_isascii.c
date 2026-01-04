/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyuskiv <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 15:48:50 by yyuskiv           #+#    #+#             */
/*   Updated: 2025/11/25 17:50:33 by yyuskiv          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stdio.h"

int	ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
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
	printf ("%d\n", ft_isascii(argv[1][0]));
	return 0;
}*/
