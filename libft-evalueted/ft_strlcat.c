/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyuskiv <yyuskiv@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 16:09:29 by yyuskiv           #+#    #+#             */
/*   Updated: 2025/11/26 18:45:00 by yyuskiv          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdio.h>
#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	srclen;
	size_t	destlen;
	size_t	i;

	srclen = ft_strlen(src);
	destlen = ft_strlen(dst);
	i = 0;
	if (destlen >= dstsize)
		return (dstsize + srclen);
	while (src[i] != '\0' && (destlen + i) < (dstsize - 1))
	{
		dst[destlen + i] = src[i];
		i++;
	}
	dst[destlen + i] = '\0';
	return (destlen + srclen);
}

/*int main (void)
  {
  size_t return_value;
  char src[] = "World!";
  char dst[20] = "Hello, ";

// Define the buffer size limit.
size_t size = 20;

printf("Source string: \"%s\"\n", src);
printf("Destination string before strlcat: \"%s\"\n", dst);
printf("Buffer size (dstsize): %zu\n", size);

// Perform the concatenation
return_value = strlcat(dst, src, size);

printf("Destination string after strlcat: \"%s\"\n", dst);
printf("strlcat returned (expected total length): %zu\n", return_value);

return (0);
}*/
