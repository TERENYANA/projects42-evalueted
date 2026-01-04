/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyuskiv <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 16:10:19 by yyuskiv           #+#    #+#             */
/*   Updated: 2025/11/25 19:18:31 by yyuskiv          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdio.h>

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

/*int main(int argc, char *argv[])
  {
  if(argc != 2)
  {
  printf("Usage: %s <string>\n", argv[0]);
  return 1;
  }
  printf ("%zu\n", ft_strlen(argv[1]));
  return 0;
  }*/
