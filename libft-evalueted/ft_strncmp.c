/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyuskiv <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 16:10:52 by yyuskiv           #+#    #+#             */
/*   Updated: 2025/11/25 19:28:15 by yyuskiv          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdio.h>

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	if (n == 0)
		return (0);
	i = 0;
	while (i < n && s1[i]
		&& s2[i] && s1[i] == s2[i])
		i++;
	if (i == n)
		return (0);
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

/*
int main(void)
  {
  printf("%d\n", ft_strncmp("HelloWorld", "HelloThere", 5));
  printf("%d)\n", ft_strncmp("HelloWorld", "HelloThere", 6));
  printf("%d\n", ft_strncmp("Hello", "Hello123", 5));
  printf("%d\n", ft_strncmp("Hello", "Hello123", 6));
  printf("%d\n", ft_strncmp("", "", 5));
  printf("%d\n", ft_strncmp("abc", "abc", 3));
  printf("%d\n", ft_strncmp("abc", "abd", 3));
  return 0;
  }*/
