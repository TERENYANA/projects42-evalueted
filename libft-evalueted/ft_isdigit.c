/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyuskiv <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 15:50:03 by yyuskiv           #+#    #+#             */
/*   Updated: 2025/11/25 17:51:04 by yyuskiv          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}
/*int main(int argc,char *argv[])
{
	if(argc != 2)
	{
		printf("Usage: %s <character>/n", argv[0]);
		return 1;
	}
	printf ("%d\n", ft_isdigit(argv[1][0]));
	return 0;
}*/
