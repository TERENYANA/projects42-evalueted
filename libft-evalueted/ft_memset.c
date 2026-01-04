/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyuskiv <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 18:46:28 by yyuskiv           #+#    #+#             */
/*   Updated: 2025/11/25 18:46:54 by yyuskiv          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdio.h>
#include <string.h>

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			i;
	unsigned char	*ptr;

	ptr = (unsigned char *)b;
	i = 0;
	while (i < len)
	{
		ptr[i] = (unsigned char)c;
		i++;
	}
	return (b);
}

/*int main(int argc, char *argv[])
  {
  char buffer[1024];
  if (argc != 2)
  {
  printf("Usage: %s <string>\n", argv[0]);
  return (1);
  }
  strncpy(buffer, argv[1], sizeof(buffer) - 1);
  buffer[sizeof(buffer) - 1] = '\0';
  ft_memset(buffer, argv[1][0], 5);
  printf("%s\n", buffer);
  return (0);
  }*/
