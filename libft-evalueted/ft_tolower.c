/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyuskiv <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 16:12:19 by yyuskiv           #+#    #+#             */
/*   Updated: 2025/11/26 15:52:43 by yyuskiv          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		return (c + 32);
	return (c);
}

/*int main(int argc, char *argv[])
  {
  if (argc != 2)
  {
  printf("Usage: %s <character>\n", argv[0]);
  return (1);
  }

  printf ("%c\n", ft_tolower((int)argv[1][0]));

  return (0);
  }*/
