/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjooris <tjooris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 12:52:55 by tjooris           #+#    #+#             */
/*   Updated: 2024/11/15 14:55:09 by tjooris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h" 

int	ft_memcmp(const void *pointer1, const void *pointer2, size_t size )
{
	size_t	i;

	i = 0;
	while (i < size && *(unsigned char *)(pointer1 + i)
			== *(unsigned char *)(pointer2 + i))
		i++;
	if (i < size)
		return (*(unsigned char *)(pointer1 + i)
				- *(unsigned char *)(pointer2 + i));
	return (0);
}
