/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjooris <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 14:29:11 by tjooris           #+#    #+#             */
/*   Updated: 2024/11/18 13:03:18 by tjooris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *string, int searchedChar)
{
	unsigned int	i;
	unsigned char	c;

	c = (unsigned char)searchedChar;
	i = ft_strlen(string);
	string += i;
	while (i > 0 && *string != c)
	{
		string--;
		i--;
	}
	if (*string == c)
		return ((char *)string);
	return (NULL);
}
