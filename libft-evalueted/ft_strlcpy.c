/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyuskiv <yyuskiv@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 16:09:53 by yyuskiv           #+#    #+#             */
/*   Updated: 2025/11/26 18:57:25 by yyuskiv          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdio.h>
#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	srclen;
	size_t	i;

	srclen = ft_strlen(src);
	i = 0;
	if (dstsize == 0)
		return (srclen);
	while (src[i] != '\0' && i < (dstsize - 1))
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (srclen);
}

/*int main (void)
  {
  int size;
  char src[] = "Hello, World!";
  char dst[] = "Have a good day!";

  size = 100;
  printf("Source before strlcpy: %s\n", src);
  printf("Destination before strlcpy: %s\n", dst);
  strlcpy(dst, src, size);
  printf("Source after strlcpy: %s\n", src);
  printf("Destination after strlcpy: %s\n", dst);
  return (0);
  }*/
