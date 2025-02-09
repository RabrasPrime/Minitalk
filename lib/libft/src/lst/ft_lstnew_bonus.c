/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjooris <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 13:09:47 by tjooris           #+#    #+#             */
/*   Updated: 2024/11/15 15:43:21 by tjooris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*lnew;

	lnew = (t_list *)malloc(sizeof(t_list));
	if (lnew == NULL)
		return (NULL);
	lnew->content = content;
	lnew->next = NULL;
	return (lnew);
}
