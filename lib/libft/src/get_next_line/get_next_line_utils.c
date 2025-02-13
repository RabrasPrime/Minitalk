/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjooris <tjooris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 15:20:37 by tjooris           #+#    #+#             */
/*   Updated: 2025/02/07 14:31:47 by tjooris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stddef.h>
#include "get_next_line.h"
#include "libft.h"
/*
void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;

	i = 0;
	if (dest == 0 && src == 0)
		return (dest);
	while (i < n)
	{
		*(unsigned char *)(dest + i) = *(unsigned char *)(src + i);
		i++;
	}
	return (dest);
}

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*d;
	unsigned char	*s;

	if ((dest == 0 && src == 0) || n == 0)
		return (dest);
	d = (unsigned char *)dest;
	s = (unsigned char *)src;
	if (d > s)
	{
		while (n > 0)
		{
			*(d + n - 1) = *(s + n - 1);
			n--;
		}
	}
	else
		while (n-- > 0)
			*(d++) = *(s++);
	return (dest);
}

void	*ft_memchr(const void *memoryBlock, int searchedChar, size_t size)
{
	while (size > 0)
	{
		if (*(unsigned char *)memoryBlock == (unsigned char)searchedChar)
			return ((void *)memoryBlock);
		memoryBlock++;
		size--;
	}
	return (0);
}
*/
char	*ft_strndup(char *ptr, size_t n)
{
	char	*line;

	line = malloc(n + 1);
	if (!line)
		return (NULL);
	ft_memcpy(line, ptr, n);
	line[n] = '\0';
	return (line);
}
