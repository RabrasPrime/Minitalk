/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjooris <tjooris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 13:59:40 by tjooris           #+#    #+#             */
/*   Updated: 2024/12/18 13:59:45 by tjooris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "ft_printf.h"

int	ft_printf(const char *str, ...)
{
	char	*dest;
	int		len;
	va_list	arg;

	if (!str)
		return (-1);
	va_start(arg, str);
	len = ft_printlen(arg, (char *)str);
	va_end(arg);
	dest = (char *)malloc(sizeof(char) * (len + 1));
	if (!dest)
		return (-1);
	va_start(arg, str);
	len = ft_printstr(arg, (char *)str, dest);
	va_end(arg);
	len = write(1, dest, len);
	free(dest);
	return (len);
}
