/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyuskiv <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 16:08:20 by yyuskiv           #+#    #+#             */
/*   Updated: 2025/11/25 19:04:11 by yyuskiv          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdio.h>

char	*ft_strchr(const char *s, int c)
{
	char	search_char;

	search_char = (char)c;
	while (*s != '\0')
	{
		if (*s == search_char)
			return ((char *)s);
		s++;
	}
	if (*s == search_char)
		return ((char *)s);
	return (NULL);
}

/*int main(int argc, char *argv[])
  {
  const char *result;
  if (argc != 3)
  {
  printf("Usage: %s <string> <character>\n", argv[0]);
  return (1);
  }
  result = ft_strchr(argv[1], (int)argv[2][0]);
  if (result != NULL)
  printf("Character found at position: %ld\n", result - argv[1]);
  else
  printf("Character not found.\n");
  return (0);
  }   */
