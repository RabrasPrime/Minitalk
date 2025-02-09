/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsigned.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjooris <tjooris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 15:03:37 by tjooris           #+#    #+#             */
/*   Updated: 2024/12/03 14:13:30 by tjooris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>

static int	u_len(unsigned int nb)
{
	int	i;

	i = 0;
	while (nb != 0)
	{
		i++;
		nb /= 10;
	}
	return (i);
}

int	ft_unsigned(char *str, int i, va_list arg)
{
	unsigned int	nb;
	int				len;
	int				j;	

	nb = va_arg(arg, unsigned int);
	len = u_len(nb);
	j = len - 1;
	if (nb == 0)
	{
		if (str)
			str[i] = '0';
		return (1);
	}
	while (nb != 0)
	{
		if (str)
			str[i + j] = (nb % 10) + '0';
		j--;
		nb /= 10;
	}
	return (len);
}
