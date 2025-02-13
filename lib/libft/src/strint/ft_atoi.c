/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjooris <tjooris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 13:19:51 by tjooris           #+#    #+#             */
/*   Updated: 2025/02/12 16:02:05 by tjooris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <limits.h>

int	ft_atoi_preprocess(const char *nptr, int *sign)
{
	int	i;

	i = 0;
	*sign = 1;
	while (nptr[i] == ' ' || (nptr[i] >= 9 && nptr[i] <= 13))
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			*sign = -1;
		i++;
	}
	if (!nptr[i] || !(nptr[i] >= '0' && nptr[i] <= '9'))
		ft_error();
	return (i);
}

int	ft_atoi_convert(const char *nptr, int i, int sign)
{
	long long	result;

	result = 0;
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		result = result * 10 + (nptr[i] - '0');
		if ((sign == 1 && result > INT_MAX)
			|| (sign == -1 && - result < INT_MIN))
			ft_error();
		i++;
	}
	if (nptr[i] != '\0')
		ft_error();
	return ((int)(sign * result));
}

int	ft_atoi(const char *nptr)
{
	int		sign;
	int		i;

	i = ft_atoi_preprocess(nptr, &sign);
	return (ft_atoi_convert(nptr, i, sign));
}
