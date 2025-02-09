/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjooris <tjooris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 12:11:41 by tjooris           #+#    #+#             */
/*   Updated: 2024/11/18 09:25:14 by tjooris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*new;
	unsigned int	i;

	if (s == NULL)
		return (NULL);
	i = ft_strlen(s);
	if (len + start > i)
	{
		if (i >= start)
			len = i - start;
		else
			len = 0;
	}
	new = (char *)malloc(sizeof(char) * (len + 1));
	if (new == NULL)
		return (NULL);
	if (len == 0)
		ft_strlcpy(new, "", 1);
	else
		ft_strlcpy(new, (s + start), len + 1);
	return (new);
}
