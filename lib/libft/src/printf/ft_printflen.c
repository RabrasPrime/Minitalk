/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printflen.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjooris <tjooris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 11:17:57 by tjooris           #+#    #+#             */
/*   Updated: 2025/01/20 13:39:46 by tjooris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "ft_printf.h"

static	int	count_len(va_list arg, char c)
{
	t_f	function[8];
	int	j;

	init_function_table(function);
	j = 0;
	while ("cspdiuxX%"[j] != c)
		j++;
	if (j < 8)
		return (function[j](0, 0, arg));
	if (j == 9)
		return (1);
	return (2);
}

int	ft_printlen(va_list arg, char *str)
{
	int	count;
	int	i;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i + 1] && str[i] == '%')
			count += count_len(arg, str[++i]);
		else
			count++;
		i++;
	}
	return (count);
}
