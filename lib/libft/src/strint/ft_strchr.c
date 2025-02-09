/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjooris <tjooris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 13:46:52 by tjooris           #+#    #+#             */
/*   Updated: 2024/11/18 13:02:53 by tjooris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *string, int searchedChar)
{
	unsigned char	c;

	c = (unsigned char) searchedChar;
	while (*string != '\0' && *string != c)
		string++;
	if (*string == c)
		return ((char *)string);
	return (NULL);
}
