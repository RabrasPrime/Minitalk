/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjooris <tjooris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 15:30:15 by tjooris           #+#    #+#             */
/*   Updated: 2024/11/18 10:32:49 by tjooris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr( const void *memoryBlock, int searchedChar, size_t size )
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
