/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjooris <tjooris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 10:00:34 by tjooris           #+#    #+#             */
/*   Updated: 2024/11/18 10:23:23 by tjooris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "limits.h"

void	*ft_calloc(size_t elementCount, size_t elementSize)
{
	void	*tab;

	if (elementCount == 0 || elementSize == 0)
	{
		elementCount = 0;
		elementSize = 1;
	}
	if (INT_MAX / elementSize < elementCount)
		return (NULL);
	tab = (void *)malloc(elementCount * elementSize);
	if (tab == NULL)
		return (NULL);
	ft_bzero(tab, elementCount * elementSize);
	return (tab);
}
