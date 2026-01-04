/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyuskiv <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 15:50:20 by yyuskiv           #+#    #+#             */
/*   Updated: 2025/11/25 17:53:30 by yyuskiv          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_isprint(int c)
{
	if (c >= 32 && c <= 126)
		return (1);
	else
		return (0);
}

/*int main(int argc, char *argv[])
{
	if(argc != 2)
	{
		printf("Usage: %s <character>\n", argv[0]);
	}
	printf ("%d\n", ft_isprint(argv[1][0]));
}*/
