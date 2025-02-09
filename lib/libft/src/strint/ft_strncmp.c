/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjooris <tjooris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 14:52:22 by tjooris           #+#    #+#             */
/*   Updated: 2024/11/18 09:41:43 by tjooris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp( const char *first, const char *second, size_t length )
{
	while ((*first != 0 || *second != 0) && length > 0)
	{
		if (*first != *second)
			return ((unsigned char)*first - (unsigned char)*second);
		first++;
		second++;
		length--;
	}
	return (0);
}
