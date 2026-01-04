/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyuskiv <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 16:11:29 by yyuskiv           #+#    #+#             */
/*   Updated: 2025/11/25 20:12:58 by yyuskiv          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdio.h>
#include <string.h>

char	*ft_strrchr(const char *s, int c)
{
	char			*last_match;
	unsigned char	target;

	target = (unsigned char)c;
	last_match = NULL;
	while (1)
	{
		if ((unsigned char)*s == target)
		{
			last_match = (char *)s;
		}
		if (*s == '\0')
			break ;
		s++;
	}
	return (last_match);
}

/*int main(int argc, char *argv[])
  {
  char *result;
  if (argc != 3)
  {
  printf("Usage: %s <string> <character>\n", argv[0]);
  return (1);
  }
  result = ft_strrchr(argv[1], argv[2][0]);
  if (result != NULL)
  printf("Found at position: %ld\n", result - argv[1]);
  else
  printf("Not found\n");
  return (0);
  }*/
