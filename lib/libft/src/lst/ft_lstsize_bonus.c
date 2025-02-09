/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjooris <tjooris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 14:00:44 by tjooris           #+#    #+#             */
/*   Updated: 2024/11/18 10:56:04 by tjooris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int		size;
	t_list	*courant;

	size = 0;
	courant = lst;
	if (!courant)
		return (0);
	while (courant != NULL)
	{
		size++;
		courant = courant->next;
	}
	return (size);
}
