/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_integer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjooris <tjooris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 15:02:40 by tjooris           #+#    #+#             */
/*   Updated: 2024/12/03 14:03:57 by tjooris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>

static unsigned int	absolute_value(int nb)
{
	if (nb < 0)
		return (-nb);
	return (nb);
}

static void	write_number(char *str, int index, unsigned int n)
{
	while (n != 0)
	{
		str[index--] = (n % 10) + '0';
		n /= 10;
	}
}

static int	int_len(int nb)
{
	int	len;

	len = 0;
	if (nb <= 0)
		len = 1;
	while (nb != 0)
	{
		len++;
		nb /= 10;
	}
	return (len);
}

int	ft_int(char *str, int i, va_list arg)
{
	int				nb;
	int				len;
	unsigned int	n;

	nb = va_arg(arg, int);
	len = int_len(nb);
	n = absolute_value(nb);
	if (nb < 0 && str)
		str[i++] = '-';
	if (nb == 0 && str)
		str[i] = '0';
	else if (str)
		write_number(str, i + len - 1 - (nb < 0), n);
	return (len);
}
