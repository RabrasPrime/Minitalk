/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjooris <tjooris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 12:54:17 by tjooris           #+#    #+#             */
/*   Updated: 2024/12/03 13:59:16 by tjooris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>

int	str_null(char *str, int i)
{
	if (str)
	{
		str[i] = '(';
		str[i + 1] = 'n';
		str[i + 2] = 'u';
		str[i + 3] = 'l';
		str[i + 4] = 'l';
		str[i + 5] = ')';
	}
	return (6);
}

int	ft_str(char *str, int i, va_list arg)
{
	int		j;
	char	*s;

	s = va_arg(arg, char *);
	if (!s)
		return (str_null(str, i));
	j = 0;
	while (s[j])
	{
		if (str)
		{
			str[i] = s[j];
			i++;
		}
		j++;
	}
	return (j);
}
