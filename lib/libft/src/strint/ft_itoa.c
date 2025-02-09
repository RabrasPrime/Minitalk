/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjooris <tjooris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 15:49:05 by tjooris           #+#    #+#             */
/*   Updated: 2024/11/15 14:51:42 by tjooris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	size_t	nb_len(long long nb)
{
	size_t	num;

	num = 0;
	if (nb < 0)
	{
		nb = nb * (-1);
		num++;
	}
	if (nb == 0)
		num++;
	else
	{
		while (nb)
		{
			nb = nb / 10;
			num++;
		}
	}
	return (num);
}

char	*ft_itoa(int n)
{
	size_t		len;
	long long	nb;
	char		*str;
	int			sign;

	len = nb_len ((long long)n);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (str == NULL)
		return (NULL);
	nb = (long long)n;
	sign = 0;
	if (nb < 0)
	{
		nb = nb * (-1);
		str[0] = '-';
		sign = 1;
	}
	str[len] = '\0';
	while (len > (size_t)sign)
	{
		str[len - 1] = nb % 10 + '0';
		nb = nb / 10;
		len--;
	}
	return (str);
}
