/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyuskiv <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 15:47:36 by yyuskiv           #+#    #+#             */
/*   Updated: 2025/11/25 17:48:50 by yyuskiv          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stdio.h"

int	ft_isalnum(int c)
{
	if ((c >= 'a' && c <= 'z')
		|| (c >= 'A' && c <= 'Z')
		|| (c >= '0' && c <= '9'))
		return (1);
	else
		return (0);
}

/*int main(int argc , char *argv[])
{
	if(argc != 2)
	{
		printf("Usege : %s <character>\n", argv[0]);
		return 1;
	}
	printf("%d/n", ft_isalnum(argv[1][0]));
	return (0);
}*/
