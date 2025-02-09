/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjooris <tjooris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 13:42:17 by tjooris           #+#    #+#             */
/*   Updated: 2024/11/18 09:36:58 by tjooris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	size_t	count;
	size_t	start;
	size_t	end;

	if (s1 == 0 || set == 0)
		return (NULL);
	start = 0;
	count = ft_strlen(s1);
	while (ft_strchr(set, s1[start]) != 0 && start < count)
		start++;
	end = count - 1;
	while (ft_strchr(set, s1[end]) != 0 && start < end)
		end--;
	str = ft_substr(s1, start, end - start + 1);
	return (str);
}
